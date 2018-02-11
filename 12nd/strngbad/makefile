.PHONY: clean attend all
all : strngbad.o vegnews.o attend clean

strngbad.o : strngbad.cpp
	g++ -c strngbad.cpp -o strngbad.o
vegnews.o : vegnews.cpp
	g++ -c vegnews.cpp -o vegnews.o
attend : strngbad.o vegnews.o
	g++ strngbad.o vegnews.o -o vegnews
clean : strngbad.o vegnews.o
	rm strngbad.o
	rm vegnews.o
