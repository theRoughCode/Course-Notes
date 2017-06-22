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
- to make clear if a fucntion is overriden or redefined

final keyword
- prevents virtual function from being overriden
- useful for inherited classes that inherit virtual functions

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
- can still access the breed field of node pointed to by ppet
- by using pointers and dynamic vars, we can treat objects of the derived class as a base class without throwing away additional vars
