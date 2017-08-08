Templates allow us to define one function that applies to all types of variables
- an example of Algorithm Abstraction, which is the expression of algorithms in a general way so we can ignore details and concentrate on the substantive parts of the algorithm

template<class T>  // Template prefix
  - tells compiler that the definition/declaration that follows is a template and that 'T' is a type parameter
  - 'T' can be replaced by any type, whether the type is a class or not
  - the compiler produces a separate definition only for the types which you use the template

template<class T>
void swapValues(T& var1, T& var2) {
  T temp;
  temp = var1;
  var1 = var2;
  var2 = temp;
}
int int1 = 1, int2 = 2;
swapValues(int1, int2);
char sym1 = 'A', sym2 = 'B';
swapValues(sym1, sym2);

- note that we call the function just like any other function

Multiple Parameters
- template<class T1, class T2>
- cannot have unused template parameters


Class Templates
- same syntax as for function templates
- once class template is defined, we can declare object of the class
- declaration must specify what type to be filled in for T
- e.g. Pair<int> score; Pair<char> seats;

Member Functions for a Class Template
- defined same way as member functions for ordinary classes
- only difference is that the member functions are also templates
template<class T>
Pair<T>::Pair(T firstValue, T secondValue) {
  first = firstValue;
  second = secondValue;
}
- note that the class name before the scope resoltion operator is Pair<T> and not just Pair, while the constructor name is simply Pair without <T>

Class Templates as Parameters
- class templates may be used as the type for a function parameter
- int addUp(const Pair<int> & thePair);
    - note that we specified the type of T
- can use a class template within a function template
template<class T>
T addUp(const Pair<T>& thePair);

Type Definitions
- can define a new class type name that has the same meaning as a specialized class template name like Pair<int>
- typedef Class_Name<T> New_Type_Name;
- e.g. typedef Pair<int> PairOfInt;

Friend Functions
- used with template classes in the same way they are used with ordinary functions, except that you must include a type parameter where appropriate

Templates and Inheritance
- to define a derived template class, start with a template class and derive another template class from it


Factory Method Pattern
- uses factory methods to deal with the problem of creating objects without having to specify the exact class of the object being created
- Factory method allows classes to defer instantiation it uses to subclasses
class Level {
public:
  virtual Enemy *createEnemy() = 0;  // factory method
};

class NormalLevel: public Level {
public:
  Enemy *createEnemy() override {
    // create mostly turtles
  }
};

class Castle : public Level {
public:
  Enemy *createEnemy() override {
    // create mostly bullets
  }
}

int main(int argc, char const *argv[]) {
  Level *l = new NormalLevel;
  Enemy *e = l->createEnemy();
  return 0;
}


Template Method Pattern
- defines the skeleton of an algorithm in a method deferring some steps to subclasses to override some aspects of superclass behaviour but, in other aspects, must stay the same

class Turtle {
public:
  void draw() {
    drawHead();
    drawShell();
    drawFeet();
  }
private:
  void drawHead() {}
  void drawFeet() {}
  virtual void drawShell = 0;
}

class RedTurtle : public Turtle {
  void drawShell override {
    // draw red shell
  }
}

class GreenTurtle : public Turtle {
  void drawShell override {
    // draw green shell
  }
}

Extension: non-virtual interface (NVL) Idiom
A public virtual method:
1. Interface to client
  - indicate provided behaviour pre/post condition invariants
2. Interface to subclasses
  - "hooks" for subclassses to insert specialized behaviour
If these ideas are wrapped in function declaration, it would be difficult to separate
* separate customizable behaviour into two methods with non-customizable steps in between without changing public interface
* How could you make sure overriding function confers to pre/post conditions and invariant

NVL Idiom
1. All public methods should be non-virtual
2. All virtual methods should be private (or at least protected)
3. Except destructors

e.g. Translate the following class to conform with the NVL Idiom
class DigitalMedia {
public:
  virtual void play() = 0;
  virtual ~DigitalMedia;
}
class DigitalMedia {
public:
  void play() {
    doPlay();
  }
  virtual ~DigitalMedia();
private:
  virtual void doPlay() = 0;
}
- extra control over Play
  - add before/after code around doPlay that cant change
  - add more "hooks" by calling additional virtual methods from play
  - without changing the public interface


Maps
- creates dictionaries
- a vector of pairs (key + value)
- templated class

#include <map>
using namespace std;
// main
map <string, int> m;
m["abc"] = 1;
m["def"] = 4;
cout << m["abc"] << endl; // 1
cout << m["ghi"] << endl; // if key is not defined, it will call the default constructor of value type and insert it in that key  (prints 0)
m.erase("abc");
if(m.count("def")) {} // 0 if not found, 1 if found
for (auto &p : m)
  cout << p.first << p.second << endl;
  // p.first gets key
  // p.second gets value
Using User-defined classes as key
- class must be:
  - copyable
  - assignable
  - comparable ( implement operator <)

Visitor Pattern
- double dispatch
- performs an extensible set of operations on an object structure without requiring any change to the structure
- adds capability to composite of objects when encapsulation is not important
e.g. Striking enemies with weapons
virtual void strike(Enemy &e, Weapon &w);
// Enemy
virtual void strike(Weapon &w);
// Weapon
virtual void strike(Enemy &e);

class Enemy {
public:
  virtual void beStruckBy(Weapon &w) = 0;
};

class Turtle : public Enemy {
public:
  void beStruckBy(Weapon &w) override {
    w.strike(*this);
  }
};

class Bullet : public Enemy {
public:
  void beStruckBy(Weapon &w) override {
    w.strike(*this);
  }
}

class Weapon {
public:
  virtual void strike(Turtle &t) = 0;
  virtual void strike(Bullet &b) = 0;
};

class Stick : public Weapon {
public:
  void strike(Turtle &t) {
    // strike turtle with stick
  }
  void strike(Bullet &b) {
    // strike bullet with stick
  }
}

class Rock : public Weapon {
public:
  void strike(Turtle &t) {
    // strike turtle with rock
  }
  void strike(Bullet &b) {
    // strike bullet with rock
  }
}

int main() {
  Enemy *e = new Bullet(...);
  Weapon *w = new Rock(...);
  e->beStruckBy(*w);
}

1. Bullet::beStruckBy runs virtual method
2. It calls Weapon::strike
  - *this is bullet
  - Bullet version happens at compile time
3. virtual method strike (Bullet &b)
  - resolves to Rock::strike(Bullet &b)

- visitor can be used to add functionality to existing classes without changing or recompiling classes
e.g. Add a visitor to book hierarchy
class Book {
public:
  virtual void accept(BookVisitor &v) {
    v.visit(*this);
  }
};
class Text : public Book {
public:
  void accept(BookVisitor &v) override {
    v.visit(*this);
  }
};
class Comic : public Book {
public:
  void accept(BookVisitor &v) {
    v.visit(*this);
  }
};
class BookVisitor {
public:
  virtual void visit(Book &b) = 0;
  virtual void visit(Text &t) = 0;
  virtual void visit(Comic &c) = 0;
};
// Track how many of each type of book we have.  Group books by author, texts by topic, comics by hero
class Catalog : public BookVisitor {
  map<string, int> theCatalog;
public:
  map<string, int> getCatalog() { return theCatalog; }
  void visit(Book &b) { ++theCatalog[b.getAuthor()]; }
  void visit(Text &t) { ++theCatalog[t.getTopic()]; }
  void visit(Comic &c) { ++theCatalog[t.getHero()]; }
};


Observer Design Pattern
- define a one-to-many dependency between objects so that when one object changes state, all dependents are notified/updated
Subject
  - keeps track of all observers and provides the facility to add or remove observers
  - updates oberservers when any change occurs
Observer
  - defines method that should be called whenever there is a change

Decorator Design Pattern
- Attach additional responsibilities to an object dynamically
- Provide a flexible alternative to subclassing for extending functionality
- Recursively wrapping object
- Inheritance is static and applies to enture class, decorator design pattern adds behaviour/state to individual objects dynamically
- encapsulates the object inside an abstract wrapper interface which the decorator and core object inherit
- allows responsibilities to be added not methods to objects interface
- interface must remain constant as successive layers are specified
Check List
1. Ensure a single core component, several optional wrappers, and a common interface
2. Create a "Lowest Common Denominator" interface that makes all classes interchangeable
3. Create a second level base class (Decorator) to support optional wrapper classes
4. Core and Decorator class inherit from LCD
5. Decorator class declares a composition relationship to LCD interface, and this data member is initialized in its constructor
6. Decorator class delegates to LCD object
7. Define a Decorator derived class for each optional wrapper
8. Decorator derived classes implement their wrapper functionality and delegate to Decorator base class
9. Client configures the type and ordering of Core and Decorator objects




Pimpl idiom
- pointer to implementation
class XWindow {
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[10];
};

// XWindowImpl.h
#include<x11/Xlib.h>
class XWindowImpl {
public:
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[10];
};
// window.h
class XWindowImpl;
class XWindow {
  XWindow *pImpl;  // private pointer to public class
};
// window.cc
#include "window.h"
#include "XWindowImpl.h"
XWindow::XWindow() : pImpl { new XWindowImpl } {}

Tips:
- include as few other header files as possible in header files
- Do the #include in the .cc file instead of .h file where possible
