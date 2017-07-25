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


Smart Pointers
- wrapper classes for pointers pointing to dynamic memory: shared_ptr, unique_ptr, weak_ptr
- unique_ptr is the only pointer that points to a block of heap memory
  - supports operator[] and array initialization
  - used to model composition relationship
- shared_ptr allows many pointers that all point to the same block of heap memory and only deletes the memory when no other shared_ptr point to it
- weak_ptr is similar to shared_ptr but doesnt count towards the "shared count"
  - used to implement temporary ownership of a shared_ptr
  - used to prevent cyclic ownership in shared_ptr
  - usage of weak_ptr is different than shared_ptr and unique_ptr.
- Raw pointers still have some uses even if ou use smart pointers to manage dynamically-allocated memory
  // a node for doubly linked list
  template <typename T>
  struct Node  {
    T data;
    std::unique_ptr<Node<T>> next;
    // Raw pointers are ok to use for modelling has-a relationship
    Node<T> *prev;
  }

  Dangers of Shared Pointers
  - should use std::make_shared and std::make_unique rather than use new
    - If you have both raw and smart pointers to the same piece of heap memory then you might not realize when the memory is released
    - use raw pointers to create 2 smart pointers have INDEPENDENT "count" values and most certainly will lead to double free errors
