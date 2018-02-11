.PHONY: all complex0.o main.o main
all : complex0.o main.o main
	
complex0.o : complex0.cpp
	g++ -c complex0.cpp -o complex0.o
main.o : main.cpp
	g++ -c main.cpp -o main.o
main : main.o complex0.o
	g++ main.o complex0.o -o main
