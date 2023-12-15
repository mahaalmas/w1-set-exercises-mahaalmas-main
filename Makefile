all: hello.out catch_tutorial.out

hello.out: hello.cpp
	g++ -std=c++11 hello.cpp -o hello.out

catch_tutorial.out: catch_tutorial.cpp
	g++ -std=c++11 catch_tutorial.cpp -o catch_tutorial.out

test1: hello.out
	./hello.out

test2: catch_tutorial.out
	./catch_tutorial.out

clean:
	rm hello.out catch_tutorial.out
