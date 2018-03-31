all : mytime

mytime : mytime0.o usetime0.o
	g++ mytime0.o usetime0.o -o mytime

mytime0.o : mytime0.cpp
	g++ -c mytime0.cpp

usetime0.o : usetime0.cpp
	g++ -c usetime0.cpp
