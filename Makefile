all: hello

hello: 00_hello.cpp
		g++ -o hello -lncurses