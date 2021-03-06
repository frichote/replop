
#    LFMM GUI, file: nothing2zscore.pl
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

my @tab_zscore;
my @tab_pvalue;
my @tab_mlog10pvalue;
my @ref;

open FILE,"$input" or die "Error when $input was opened.\n";

for ($i=1;$i<=$M;$i++) {
	my $line = <FILE>;
	if ($line =~ /\s*(\S+)\s+(\S+)\s+(\S+).*/) {
		$tab_zscore[$i] = $1;
		$tab_mlog10pvalue[$i] = $2;
		$tab_pvalue[$i] = $3;
	} else {
		die "Ca ne marche pas !!! ";
	}
}
close(FILE);

open(WRITE,">$output") || die ("Error in the creation of $output.\n") ;

for($c=1; $c<=$M; $c++) {
       print WRITE "SNP_$c 0 $c $tab_zscore[$c] $tab_mlog10pvalue[$c] $tab_pvalue[$c]\n";
}
close(WRITE);
