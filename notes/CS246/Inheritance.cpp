Inheritance: the process by which a new class (derived class) is created from another class (base class)
- the derived class has all the member vars and all ordinary member functions that the base class has

Derived Class
class derivedClass : public baseClass {
  void inheritedFn();  <-- list only the declaration of an inherited member function if you want to change the definition
}

Inherited Members
- derived class has all the member vars and all ordinary member functions of base class
- inherited member functions and member vars are not mentioned in the definition of the derived class, but are automatically members of the derived class
  - constructors, destructors, copy constructors, assignment operator, and private member functions are not inherited

Constructors
- constructors are not inherited, but can invoke a constructor of base class within definition of a derived class constructor
  - constructors for derived classes begin with an invocation of a constructor for the base class which initializes all the data inherited from the base class
  - derived class does not inherit constructors from base class
  - if constructor of base class is not called, the default (zero-argument) constructor of th base class will be called

Destructors
- destructors for derived classes automatically invokes the destructor of the base class, but it has to delete additional member variables it defined

Overloaded Operators
  - derived overloaded functions will have to invoke the base class overload function
    - Derived& Derived::operator =(const Derived& rightSide) {
      Base::operator =(rightSide);
    }

- If you want to change the definition of an inherited member function, you declare it in the definition of the derived class (called redefining)
  - if a derived class of a derived class wants to use the base class function, use the scope resolution operator with the name of the base class
  - derivedClass.baseClass::function();
- derived classes can add new member vars and functions
- derived classes are objects of the base class (but not vice versa)
- derived classes do not have access to private vars or functions from the base class

Base class = Parent class / Ancestor class (parent of parent of etc)
Derived class = Child class / Descendent class

protected Qualifier: allows vars/functions to be accessed by name in a derived class but not anywhere else
- protected members are inherited in the derived class as if they were marked protected in the derived class

Protected and Private Inheritance
- protected: members that are public in the base class are proteccted in the derived class when they are inherited
- private: all members of the base class are inaccessible in the derived class
- protected/private derived classes cannot be used as an argument that has the type of the base class

Multiple Inheritance
- a derived class can have more than one base class
- separate base classes with commas
