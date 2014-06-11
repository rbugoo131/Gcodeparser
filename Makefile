#
# Makefile for Gcodeparser
#

OBJS= *.o
SRC= ./src/*.c
SRC_DIR=./src
HEADER_DIR=./include
HEADER=./include/*.h
target=Gcodeparser


all: Gcodeparser 
	rm -rf $(OBJS)
Gcodeparser: Gcodeparser.o input.o
	gcc -o ./build/Gcodeparser Gcodeparser.o input.o

input.o: $(SRC_DIR)/input.c $(HEADER_DIR)/input.h
	gcc -c $(SRC_DIR)/input.c -I $(HEADER_DIR)

Gcodeparser.o: $(SRC_DIR)/Gcodeparser.c
	gcc  -c $(SRC_DIR)/Gcodeparser.c
	mkdir build

clean:
	rm -rf $(OBJS)
	rm -rf $(target)
	rm -rf build
test:
	./build/Gcodeparser ./Gcode/test3_0001.ngc
