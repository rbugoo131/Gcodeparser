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
Gcodeparser: Gcodeparser.o gcode.o extra_fun.o
	gcc -o ./build/Gcodeparser Gcodeparser.o gcode.o extra_fun.o -lm

extra_fun.o: $(SRC_DIR)/extra_fun.c $(HEADER_DIR)/extra_fun.h
	gcc -c $(SRC_DIR)/extra_fun.c -I $(HEADER_DIR)

gcode.o: $(SRC_DIR)/gcode.c $(HEADER_DIR)/gcode.h $(HEADER_DIR)/struc.h
	gcc -c $(SRC_DIR)/gcode.c -I $(HEADER_DIR)

Gcodeparser.o: $(SRC_DIR)/Gcodeparser.c
	gcc  -c $(SRC_DIR)/Gcodeparser.c
	mkdir build

clean:
	rm -rf $(OBJS)
	rm -rf $(target)
	rm -rf build
test:
	././build/Gcodeparser < ./Gcode/test.ngc
