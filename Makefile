tests: tests.o time.o
	g++ -o tests tests.o time.o
tests.o: tests.cpp time.o time.h
time.o: time.cpp time.h
clean:
	rm -f *.o tests