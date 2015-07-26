#variable
CXX   := g++
CC    := gcc  

OBJS = $(shell find ./  -name '*.cpp' | sed "s/.cpp$$/.o/g")
OBJS += $(shell find ./  -name '*.c' | sed "s/.c$$/.o/g")

INC := -I. -I../../deps/jemalloc/include
LIBDIR := -L. -L../../deps/jemalloc/lib
LIB := 

CFLAG := -c -std=gnu99 -Wall -O2 
#CFLAG += -Wunused-parameter
LDFLAG := -ljemalloc
MACRO := 

#all target
TARGET := jemalloc_test
all:$(TARGET)

#build rules 
$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBDIR) $(LIB) $(LDFLAG)
	
.cpp.o:
	$(CXX) -o $@ $< $(CFLAG) $(MACRO) $(INC)
.cc.o:
	$(CXX) -o $@ $< $(CFLAG) $(MACRO) $(INC)
.c.o:
	$(CC) -o $@ $< $(CFLAG) $(MACRO) $(INC)

#install
install:$(TARGET)

#clean
clean:
	rm -rf $(OBJS)  $(TARGET)
