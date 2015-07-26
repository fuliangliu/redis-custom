#variable
CXX   := g++
CC    := gcc  

OBJS = $(shell find ./  -name '*.cpp' | sed "s/.cpp$$/.o/g")
OBJS += $(shell find ./  -name '*.c'|grep -v "inclu.c" | sed "s/.c$$/.o/g")

INC := -I../deps/jemalloc/include
INC += $(shell find ./ -type d -exec echo -I{} \;)


LIBDIR := -L. -L../deps/jemalloc/lib
LIB := 

CFLAG := -c -std=gnu99 -Wall -g3 #-O2 
#CFLAG += -Wunused-parameter
LDFLAG := -ljemalloc
MACRO := -DUSE_JEMALLOC -D__linux__

#all target
TARGET := test
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
