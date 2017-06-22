Make and Makefiles
- with single files, compilation is easy
- We can use separate compilation
  - g++14 -c main.cc <-- create object file for each file
  .
  .
  .
  - g++14 main.o ... -o main <-- compile all object files

- 'make' allows us to specify the dependencies of the targets and the command for producing each target in a Makefile

Makefile:
#means main depends on these dependencies
main: main.o book.o textbook.o comic.o
  #specifies how to build main
  g++14 main.o book.o textbook.o comic.o -o main
book.o: book.cc book.h
  g++14 -c book.cc
.
.
.

- whitespace before build command MUST be a tab
- on command line, run 'make'
- we can build specific targets using make
  - make textbook.o

- We can generalize Makefile with variables
CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -Werror -1X11
...
book.o: book.cc book.h
  ${CXX} ${CXXFLAG} -c book.cc

Shortcut: For any rule of the form x.o: x.cc x.h, we can leave out the build command as make will guess tht it is
${CXX} ${CXXFLAGS} -c book.cc -o book.o

Keeping trach of dependencies and updating them as they change
- g++14 -MMD -c comic.cc will create comic.o and comic.d
- comic.d contains
  comic.o: comic.cc book.h comic.h
- We can just include the .d files in Makefile
CXX=g++-5
CSSFLAGS=-std=c++14 -Wall -Werror -MMD
OBJECTS=main.o book.o textbook.o comic.o
DEPENDS=${OBJECTS: .o=.d}
EXEC=main
${EXEC}: ${OBJECTS}
  ${CXX} ${CXXFLAGS}${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
clean:
  rm *.o main
.PHONY: clean

LValues and RValues
Lvalue: has an address explicitly accessible by the program
  - Lvalue reference: &
Rvalue: not an Lvalue
  - Rvalue reference: &&
  - may be used to initialize a sconst Lvalue reference
