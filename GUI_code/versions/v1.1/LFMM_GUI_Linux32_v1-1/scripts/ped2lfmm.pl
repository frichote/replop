
#    LFMM GUI, file: ped2lfmm.pl
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



my $nsamp =200;    # number of samples
my $nbloci = 1000;      # number of loci        
my $input = $ARGV[0]; # output file name
my $output = $ARGV[1];
my $N = $ARGV[3];
my $M = $ARGV[2];

my @tab;
my @ref;

for ($i=1;$i<=$M;$i++) {
	$ref[$i]=0;
}

my $tmp;

open FILE,"$input" or die "Error when $input was opened.\n";


for($d=1; $d<=$N; $d++) {
	my $line = <FILE>;
	chomp $line;
	if ($line =~ /(\s*\S+){6}(.*)/) {	
		$tmp = $2;	
	} else {
		print "$line\n";
		die "Error while reading ped file: $input.\n";
	}
        for($c=1; $c<=$M; $c++) {
		if ($tmp =~ /\s*([01234ACTG])\s*([01234ACTG])(.*)/) {
			$tab[$d][$c]=0;
			$tmp = $3;
			if($ref[$c] eq 0) {
				if ($1 eq 0) {
					$ref[$c] = $2;
				} else {
					$ref[$c] = $1;
				}
			}
			if ($1 ne 0 && $1 ne $ref[$c]) {
					$tab[$d][$c]++;
			}
			if ($2 ne 0 && $2 ne $ref[$c]) {
					$tab[$d][$c]++;
			}
			if ($1 eq 0 || $2 eq 0) {
					$tab[$d][$c] = -9;
			}


		} else {
			die "Error while reading ped file: $input.\n";
		}
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
