Test: Test.o
	g++ -g $^ -o $@

Test.o: Test.cpp Map.h Employee.h BookInfo.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Test.o Test