CC=g++-7 -Wall -O0 -fno-omit-frame-pointer -g -coverage



main: main.cpp extra.cpp lab.o
	$(CC) -o prog main.cpp extra.cpp lab.o

lab.o: lab.cpp
	$(CC) -c lab.cpp



cov:     	
	lcov --capture --directory . --output-file coverage.info
	genhtml --demangle-cpp coverage.info --output-directory out



cov_branch:     	
	lcov --rc lcov_branch_coverage=1 --capture --directory . --output-file coverage.info
	genhtml --branch-coverage coverage.info --output-directory out

clean: 
	rm *.gcno *.gcda coverage.info

