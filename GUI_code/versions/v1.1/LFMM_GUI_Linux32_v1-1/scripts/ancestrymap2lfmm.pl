
#    LFMM GUI, file: ancestrymapgen2lfmm.pl
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

my @tab;

open FILE,"$input" or die "Error when $input was opened.\n";

my $snp = "";
my $tmp;
for($c=1; $c<=$M; $c++) {
	for($d=1; $d<=$N; $d++) {
		my $line = <FILE>;
		if ($line =~ /\s*(\S+)\s+(\S+)\s+(-*[0129])/) {	
			$tab[$d][$c]=$3;
		} else {
			die "Error while analyzing file.\n";
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
