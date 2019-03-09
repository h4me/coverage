CC=g++-7 -Wall -g -coverage



main: main.cpp extra.cpp
	$(CC) -o prog main.cpp extra.cpp

cov:     	
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
clean: 
	rm *.gcno *.gcda coverage.info

