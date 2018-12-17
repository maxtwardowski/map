Test: Test.o
	g++ -g $^ -o $@ -std="c++11"

Test.o: Test.cpp Map.h Employee.h BookInfo.h
	g++ -g -c -Wall -pedantic $< -o $@ -std="c++11"

.PHONY: clean

clean:
	-rm Test.o Test
