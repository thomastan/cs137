## Notes ##
There is no event.c nor poly.c ready to submit as there are two versions of each of these
files.  Rename either event-a6.c or event-a10.c (along with event-a6.h or event-a10.h) to
event.c and poly-a5.c or poly-a9.c (along with poly-a9.h) to poly.c.

Each of the "diff" commands below can be replaced with "paste" to see the obtained and
expected output side-by-side.


## Assignment 1 ##
hello.c

	gcc hello.c -o hello
	./hello > output/hello
	diff output/hello expected/hello


## Assignment 2 ##
reduce.c  
reverse.c

	gcc reduce.c -o reduce;  rm -f output/reduce
	for i in '4 6' '-10 3' '21 7' '100 0'; do echo $i | ./reduce >> output/reduce; done
	diff output/reduce expected/reduce

	gcc reverse.c -o reverse;  rm -f output/reverse
	for i in 12345 -12345 0 1000; do echo $i | ./reverse >> output/reverse; done
	diff output/reverse expected/reverse


## Assignment 3 ##
twin.c  
day.c  
revlist.c

	gcc twin.c test-twin.c -o twin
	./twin > output/twin
	diff output/twin expected/twin

	gcc day.c test-day.c -o day
	./day > output/day
	diff output/day expected/day

	gcc revlist.c -o revlist
	echo 1 5 7 8 3 0 | ./revlist > output/revlist
	diff output/revlist expected/revlist


## Assignment 4 ##
array.c test-array.c  
factor.c test-factor.c  
sudoku.c test-sudoku.c

	gcc array.c test-array.c -o array
	./array > output/array
	diff output/array expected/array

	gcc factor.c test-factor.c -o factor
	./factor > output/factor
	diff output/factor expected/factor

	gcc sudoku.c test-sudoku.c -o sudoku
	./sudoku > output/sudoku
	diff output/sudoku expected/sudoku


## Assignment 5 ##
avgmoney.c test-avgmoney.c  
poly.c test-poly.c --- ** submit as poly.c (not poly-a5.c) **

	gcc avgmoney.c test-avgmoney.c -o avgmoney
	./avgmoney > output/avgmoney
	diff output/avgmoney expected/avgmoney

	cp poly-a5.c poly.c;
	gcc poly.c test-poly-a5.c -o poly-a5
	./poly-a5 > output/poly-a5
	diff output/poly-a5 expected/poly-a5


## Assignment 6 ##
fraction.h fraction.c test-fraction.c  (**submit as zip file with .h file**)  
event-a6.h event-a6.c test-event-a6.c --- ** submit as event.c (not event-a6.c) **

	gcc fraction.c test-fraction.c -o fraction
	./fraction > output/fraction
	diff output/fraction expected/fraction
	zip fraction.zip fraction.h fraction.c

	cp event-a6.c event.c;  cp event-a6.h event.h
	gcc event.c test-event-a6.c -o event-a6
	./event-a6 > output/event-a6
	diff output/event-a6 expected/event-a6


## Assignment 7 ##
dateSplit.c test-dateSplit.c  
histogram.c test-histogram.c

	gcc dateSplit.c test-dateSplit.c -o dateSplit
	./dateSplit > output/dateSplit
	diff output/dateSplit expected/dateSplit

	gcc histogram.c test-histogram.c -o histogram
	./histogram > output/histogram
	diff output/histogram expected/histogram


## Assignment 8 ##
contains.c test-contains.c  
alphabetic.c test-alphabetic.c  
rpsls.c test-rpsls.c

	gcc contains.c test-contains.c -o contains
	./contains > output/contains
	diff output/contains expected/contains

	gcc alphabetic.c test-alphabetic.c -o alphabetic
	./alphabetic > output/alphabetic
	diff output/alphabetic expected/alphabetic

	gcc rpsls.c test-rpsls.c -o rpsls
	./rpsls > output/rpsls
	diff output/rpsls expected/rpsls


## Assignment 9 ##
poly.h poly.c test-poly.c  (**submit as zip file with .h file**)  
 --- ** submit as poly.c (not poly-a9.c) **

	cp poly-a9.c poly.c;  cp poly-a9.h poly.h;
	gcc poly.c test-poly-a9.c -o poly-a9
	./poly-a9 > output/poly-a9
	diff output/poly-a9 expected/poly-a9
	zip poly.zip poly.h poly.c


## Assignment 10 ##
sf.h sf.c test-sf.c  
event-a10.h event-a10.c --- ** submit as event.c (not event-a10.c) **

	gcc sf.c test-sf.c -o sf
	./sf > output/sf
	diff output/sf expected/sf

	cp event-a10.c event.c;  cp event-a10.h event.h;
	gcc event.c test-event-a10.c -o event-a10
	./event-a10 > output/event-a10
	diff output/event-a10 expected/event-a10


## How to clean up ##
	rm -f hello reduce reverse twin day revlist array factor sudoku
	rm -f avgmoney poly-a5 fraction fraction.zip event-a6 dateSplit histogram
	rm -f contains alphabetic rpsls poly-a9 poly.zip sf event-a10
	rm -f event.c event.h poly.c poly.h