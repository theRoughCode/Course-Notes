struct CDAccount {
  double balance;
  double interestRate;
  int term;
};  <-- Don't forget semi-colon

CDAccount cd1;  // cd1 is a strcture variable
// cd1's value is a collection of 3 member values

Dot Operator
- used to specify a member variable of a stucture variable
- cd1.balance

/////////////////////////////////////////////////////////

Class: has member functions as well as member variables
Object: value of a variable of a class type

class Class_Name {
public:
  int int1;
  string str1;
private:
  int int2;
  string str2;
};  <-- Dont forget semicolon


Member Functions
- definition must include class name
- void DayofYear:: output()
- :: is the scope resolution operator
  - tells what a member function is a member of
  - :: is used with class name, . is used with objects

Encapsulation
- Defining a class so that the implementation of member functions and data in objects are not known to client

Private
- cannot be referenced outside class
- all items that follow "private:" are private

Accessor Functions
- allow client to read data

Mutator Functions
- allow client to change data


Constructors
- member function called when an object of that class is declared
- initializes values of some or all member variables
- returns an "anonymous object"

Constructor Definitions
- must have same name as class
- cannot return a value
- no type can be given

class DayofYear {
public:
  DayofYear(int monthValue, int dayValue);
}


Initialization Section
- goes after parameter list and before opening braces
- consists of a colon followed by a list of some or all member vars separated by comma
- Each member var included is followed by its initializing value in paranthesis

DayofYear::DayofYear(int monthValue, int dayValue) : month(monthValue), day(dayValue) {

}


Overloading Constructors
- We can create multiple constructors of varying parameters
- * Default constructor (with no parameter) when declared doesnt have brackets (so that it wont be mistaken as a function)

Explicit Constructor Calls
- constructors can be called even after object has been declared
- holiday = DayofYear(5, 5);
- *For a constructor with no arguments, we DO have to include paranthesis
- TIP: always include a default constructor to allow for "accidental" declarations of classes without parameters

Member Initializers
- set default values for member vars by initializing them within the class definition

Constructor Delegation
- constructors invoking another constructor

Constant Parameter
- const
- prevents call-by-reference parameter from being changed
bool isLarger(int a, int b);
bool isLarger(const int& a, const int& b);
- both have the same function but the constant parameters provide an automatic error checking (compiler will issue an error message if there is a change to parameter)

Constant Function
- if a member function should not change the value of calling object, we can mark the function with a const modifier by appending it at the end of the function declaration
void output() const;
- constant objects can only call constant functions

Inline Functions
- complete definition of member function within definition of class
- more efficient for smaller function definitions

Inline Non-member Functions
- place keyword 'inline' before function declaration and definition

Inline Class Member Functions
- Defined within class definition

Static Members
- variable shared by all objects of clas
- used for object of a class to communicate with each other and coordinate actions

Static Function
- Does not need a calling object
- cannot use anything that depends on a calling object (only static variables)


Returning By Constant Value
const DataType Name() {};
- returned object cannot be changed


Destructor
- executed whenever an object of its class goes out of scope or the delete expression is applied to a pointer of an object of that class
- ~className(){}

Copy Constructor
- used when a copy of an object is made
- used when:
  1. A class object is declared and initialized by another object of the same type in parameters
    - Class c1(c2);
    - Class c1 = c2;
  2. When a function returns a value of the class type
  3. When an argument of the class type is plugged in for a call-by-calue parameter
- has one call-by-reference parameter of same class type (normally const)
- Any class that uses pointers/new operator should have a copy constructor
Class::Class(const Class& Object) {
  ptr = new int;
  *ptr = Object->ptr; // copies value
}

Copy Assignment Operator
- used when an already initialized object is assigned a new value from another existing object
- fallback for move assignment when move is unavailable (rvalues can bind to const references)
Class &Class::operator=(const Class &Object) {
  delete ptr;
  ptr = new int;
  *ptr = Object->ptr; // copies value
}
Class c2 = c1;  <-- calls copy constructor



RULE OF THREE
- rule of thumb of C++ for building exception-safe code and for formalizng rules on resource management
- claims that if a class defines one (or more) of the following, then it should explicitly define all three:
- destructor
- copy constructor
- copy assignment operator


RULE OF FIVE
- used in C++11
- implements move semantics, allowing destination objects to grab data from temporary objects
- the five:
  - destructor
  - copy constructor
  - move constructor
  - copy assignment operator
  - move assignment operator


Rvalues
- temp values (i.e. x+(y*z))
- declaration looks like
std::string&& rrstr; // C++11 rvalue reference varaiable
- contrasting to lvalues that look like
std::string& ref;  // C++11 lvalue reference varaiable

Move Semantics
- copying transfers the state of an object to another
- moving is faster as they move existing resources to the new destination, while copying requires the creation of a new resource from scratch

Move Constructor
- moves sub-objects and data members
C::C(C&& other);  //C++11 move constructor
- doesnt allocate new resources, gets others resources
- std::move() is a cast that produces an rvalue reference to an object to enable moving from it
MemoryPage (MemoryPage &&other) : size(0), buf(nullptr) {
  // pilers other's resources
  size = other.size;
  buf = other.buf;
  // reset other
  other.size = 0;
  other.bug = nullptr;
}

Move Assignment Operator
C& C::operator=(C&& other); //C++ move assignment operator
- similar to copy constructor except that before pilfering source object, it releases any resources the object might own
- Performs the following steps:
  - releases source object, *this, currently owns
  - pilfers others resources
  - set other to a default state
  - return *this
MemoryPage& MemoryPage::operator=(MemoryPage&& other)
{
  if (this!=&other)
  {
    // release the current object’s resources
    delete[] buf;
    size=0;
    // pilfer other’s resource
    size=other.size;
    buf=other.buf;
    // reset other
    other.size=0;
    other.buf=nullptr;
  }
  return *this;
}


Uniform Initialization
- similar to array: int arr[4] = {0,1,2,3};
- public vars:
class Student {
public:
  String name;
  int id;
}
Student s1 = {"Sarah", 1222};  // agggregate initialization
- private vars:
class Student {
private:
  String name;
  int id;
public:
  Student(String name, int id) : name {name}, id {id} {}
}
Student s2 = {"John", 3344};  // calls constructor

- Uniform Initialization searches for:
  1. initializer_list constructor
    myclass (std::initializer_list<int> v);
  2. Regular constructor
    - private member vars
    - public constructor
  3. Aggregate Initialization
    - public member vars

MIL = Member Initialization List
-className (a1, a2, ...) : member_var1(a1), member_var2(a2)...
- fields are initialized in the order of declaration in the class, not in the order of MIL
- more efficient than initializing in the body as it calls the constructor once rather than calling the default constructor and then initializing the member vars


Every class comes with:
1. default constructor
2. copy constructor
3. copy assignment constructor
4. destructor
5. move constructor
6. move assignment constructor
