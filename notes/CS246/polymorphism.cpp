Polymorphism: the ability to associate multiple meanings to one function name with virtual functions or late binding

Virtual Functions: used before it is defined
- compiler waits till it is used in the program and gets the object's implementation
- this technique is known as late binding or dynamic binding
- used when we have a function which we don't know exactly how it is implemented
- Note that in Java, all functions are virtual, unlike in C++
- virtual type varName();
- inherited classes will keep the virtual properties of virtual functions in the base class (even without stating the virtual keyword)
- if a virtual function is changed, it is overriden
  - defined at runtime
- if a non-virtual function is changed, it is redefined
  - defined at compiletime

override keyword
- to make clear if a function is overridden or redefined
class Sale {
  virtual double bill() const;
};
class DiscountSale : public Sale {
  double bill() const override;
};

final keyword
- prevents virtual function from being overriden
- useful for inherited classes that inherit virtual functions
class Sale {
  virtual double bill() const final;
};
class DiscountSale : public Sale {
  double bill() const;  <-- compiler error
};

Disadvantage of Virtual Functions
- Overhead
  - uses more storage
  - late binding -> program runs slower
- use when needed

Pure Virtual Functions: no need to give any definition to it
- add '= 0' to declaration
- virtual type var() = 0;

Abstract Class: class with one or more virtual functions
- can only be used as a base class
- cannot create objects of an abstract class
- can still write code with parameters of the abstract class type which will apply to all object of derived classes
- inherited classes from abstract class will be abstract unless you provide definitions for all the inherited pure virtual functions

Slicing Problem
class Pet
{
  public:
    string name;
    virtual void print( ) const;
};
class Dog : public Pet
{
  public:
    string breed;
    virtual void print( ) const; //keyword virtual not needed,
    //but put here for clarity.
};
Dog vdog;
Pet vpet;
vdog.name = "Tiny";
vdog.breed = "Great Dane";
vpet = vdog;

- vpet loses its breed field
- to counter this, we use pointers and dynamic vars
Pet *ppet;
Dog *pdog;
pdog = new Dog;
pdog->name = "Tiny";
pdog->breed = "Great Dane";
ppet = pdog;
- ppet->breed will generate an error, but ppet->print() will access the breed field from Dog
- by using pointers and dynamic vars, we can treat objects of the derived class as a base class without throwing away additional vars


class Book {
  string title, author;
protected:
  int numPages;
public:
  Book();
  virtual bool isHeavy() const {
    return numPages > 200;
  }
};
class Comic : public Book {
  bool isHeavy() const override {
    return numPages > 30;
  }
}

Comic c{40};
Book &pB{&c};
Book &rB{c};
Comic *pc{&c};

cout  << pc->isHeavy() // true
      << pB->isHeavy() // true
      << rb.isHeavy(); // true

Book *myBook[20];
for (int i = 0; i < 20; i++) {
  cout << myBooks[i]->isHeavy() << endl;
}
// accomodates multiple types under one abstraction (polymorphism)

------------ Danger: ------------
class One {
  int x, y;
public:
  One(int x = 0, int y = 0) : x{x}, y{y}{}
};
class Two : public One {
  int x;
public:
  Two(int x = 0, int y = 0, int z = 0) : One{x, y}, z{z}{}
};

void f(One *a) {
  a[0] = One {6,7};
  a[1] = One {8,9};
}

Two myArray[2] {{1,2,3}, {4,5,6}};
f(myArray);
myArray: | 1 2 3 | 4 5 6 |
a[0] = {6,7};
a[1] = {8,9};
myArray: | 6 7 8 | 9 5 6 |  // Data misaligned

- Never use array of objects polymorphism if you want to have a polymorphic array of pointers

UML
- Abstract class and pure virtual functions are italic


Virtual Destructors
Base *pBase = new Derived;
delete pBase;
- if destructor in Base was virtual, the destructor in Derived is called.  If it was not virtual, the Base destructor is called
- makes sense to make all destructors virtual

Upcasting: castng from a descendent type to anscestor type
  - safe as youre only disregarding some info
Downcasting: casting from ancestor type to descendent
  - dangerous
  - use dynamic_cast, only works for pointer types
  Pet *ppet;
  ppet = new Dog;
  Dog *pdog = dynamic_cast<Dog*>(ppet);
  - dynamic_cast informs you if it fails and returns NULL
  - Keep the following points in mind when Downcasting:
    1. Keep track of things so you know the info to be added is present
    2. Member functions must be virtual since dynamic_cast uses the virtual functions info to perform cast

virtual function table: created for a class that has one or more member functions that are virtual
  - has a pointer for each virtual member function
  - if inherited virtual function is not changed, table points to definition in ancestor class
  - if virtual function has a new definition, pointer points to that definition
