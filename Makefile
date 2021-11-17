main: main.o time.o
	g++ -o main main.o time.o
tests: tests.o time.o
	g++ -o tests tests.o time.o
main.o: main.cpp time.o time.h
tests.o: tests.cpp time.o time.h
time.o: time.cpp time.h
clean:
	rm -f *.o tests main