#
# Makefile for Gcodeparser
#

OBJS= Gcodeparser.o
SRC= Gcodeparser.cpp
target=Gcodeparser


all: Gcodeparser
Gcodeparser: Gcodeparser.o
	g++ -o ./build/Gcodeparser Gcodeparser.o
	rm -rf $(OBJS)

Gcodeparser.o: Gcodeparser.cpp
	g++  -c Gcodeparser.cpp
	mkdir build

clean:
	rm -rf $(OBJS)
	rm -rf $(target)
	rm -rf build
