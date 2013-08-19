
#    LFMM GUI, file: eigenstrat2lfmm.pl
#    Copyright (C) 2012 Eric Frichot
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.



my $input = $ARGV[0]; # output file name
my $output = $ARGV[1];
my $M = $ARGV[2];
my $N = $ARGV[3];

open FILE,"$input" or die "Error when $input was opened.\n";

my @tab;
my $M = 1;
my $N = 0;
my $line = <FILE>;
chomp $line;
my $tmp = $line;

while ($tmp =~ /([0129])(.*)/) {	
	$N = $N + 1;
	if ($1 == 9) {
		$tab[$o][$M] = -9
	} else {
		$tab[$o][$M] = $1;	
	}
	$tab[$N][1] = $1;	
	$tmp = $2;	
}

while($line = <FILE>) {

	$M = $M + 1;
	$o = 0;
	chomp $line;
	$tmp = $line;
	while ($tmp =~ /([0129])(.*)/) {	
		$o = $o + 1;
		if ($1 == 9) {
			$tab[$o][$M] = -9
		} else {
			$tab[$o][$M] = $1;	
		}
		$tmp = $2;	
	}
	if ($o != $N) {
		die "ERROR not the same number of individual per line $o $N.\n";
	}
}

close(FILE);

open(WRITE,">$output") || die ("Error in the creation of $output.\n") ;
for($d=1; $d<=$N; $d++) {
        for($c=1; $c<=$M-1; $c++) {
                print WRITE "$tab[$d][$c] ";
        }
        print WRITE "$tab[$d][$M]\n";
}
close(WRITE);
