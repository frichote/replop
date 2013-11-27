#!/bin/sh
#
# by E. Frichot
#
# parameters and functions common for all scripts

# color parameters
VERT="\\033[1;32m" NORMAL="\\033[0;39m" ROUGE="\\033[1;31m" LBLUE="\\033[1;36m"
PURPLE="\\033[1;35m" BOLD="\\033[0;1m" BLUE="\\033[1;34m"

# run command line $1
# compare $2 and $3
# return OK if $2 == $3, FAILED elsewise
ok() {
	cl=$1
	eval $cl

	if cmp -s $2 $3;then
	       	echo "$VERT" "[OK]" "$NORMAL ok() $cl"
	else
       		echo "$ROUGE" "[FAILED]" "$NORMAL ok() $cl"
	fi
}

# run command line $1
# compare $2 with the log
# return OK if $2 == log, FAILED elsewise
ok_log() {
	cl=$1
	eval $cl > test.log

	if cmp -s $2 test.log;then
	       	echo "$VERT" "[OK]" "$NORMAL ok_log() $cl"
	else
       		echo "$ROUGE" "[FAILED]" "$NORMAL ok_log() $cl"
	fi
	rm test.log
}

# run command line $1
# compare two matrix in files $2 and $3 with R
# return OK if $2 == $3, FAILED elsewise
ok_matrix() {
	cl=$1
	cp ../../check.R .
	Rscript check.R $2 $3 > test.log
	echo '[1] "OK"' > ok.log
	if cmp -s ok.log test.log; then
	       	echo "$VERT" "[OK]" "$NORMAL ok_matrix() $cl"
	else
       		echo "$ROUGE" "[FAILED]" "$NORMAL ok_matrix() $cl"
	fi
	rm ok.log check.R test.log
}

# compare $2 and $3 with cmp
# return OK if $2 == $3, FAILED elsewise
log() {
	cl=$1
	if cmp -s $2 $3;then
	       	echo "$VERT" "[OK]" "$NORMAL log() $cl"
	else
       		echo "$ROUGE" "[FAILED]" "$NORMAL log() $cl"
	fi
}

ok_and_log() {
	cl=$1 
	eval $cl > test.log
	if cmp -s $2 test.log && cmp -s $2 $3; then
	       	echo "$VERT" "[OK]" "$NORMAL ok_and_log() $cl"
	else
       		echo "$ROUGE" "[FAILED]" "$NORMAL ok_and_log() $cl"
	fi
	#rm test.log
}

ok_cl() {
	cl=$1 
	if eval "$cl" > test.log; then
	       	echo "$VERT" "[OK]" "$NORMAL ok_cl() $cl"
		rm test.log
	else
       		echo "$ROUGE" "[FAILED]" "$NORMAL ok_cl() $cl"
	fi
}

ok_main() {
	cl=$1
	
#	time -o time.txt $cl > test.log
	d=`date +%Y%m%d+%H%M%S`
	eval $cl > test.log
	gprof $3 gmon.out > analysis_$d.txt

        if cmp -s $2 test.log;then
                echo "$VERT" "[OK]" "$NORMAL ok_main() $cl"
        else
                echo "$ROUGE" "[FAILED]" "$NORMAL ok_main() $cl"
        fi
}

ok_valgrind() {
	cl=$1
	valgrind --trace-children=yes --smc-check=all --read-var-info=yes --leak-check=full --show-reachable=yes --track-origins=yes --malloc-fill=ff --free-fill=42 $cl > valgrind.txt  2>&1

        if grep --quiet "All heap blocks were freed -- no leaks are possible" valgrind.txt && grep --quiet "ERROR SUMMARY: 0 errors from 0 contexts" valgrind.txt; then 
                echo "$VERT" "[OK]" "$NORMAL ok_valgrind() $cl"
        else
                echo "$ROUGE" "[FAILED]" "$NORMAL ok_valgrind() $cl"
        fi

}
