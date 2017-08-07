Encapsulation Rules:
1. All member vars should be private
2. Basic class operations should be:
  - Public member functions
  - Friend or ordinary functions
  - Overloaded operators
  Group class definition and prototypes together -> interface
3. Make class implementation unavailable to users of the class

Interface: group of class definitions and functions and operator declarations
  - contains class definition with function and operator declarations/prototypes
  - Users can see this
Implementation: consists of function defiinitions and overloaded operator definitions
Header file: an interface file that ends with '.h'
Application(driver) file: contains program

Compiling:
- compile implementation and application file, but no interface file

Linking:
- once implementation and application files are compiled, we need to connect the files
- done with a linker

#define DTIME_H
- puts DTIME_H on a list to indicate it has been seen
#ifndef DTIME_H
- test whether DTIME_H has been seen
- if seen, skips everything till #endif

Namespaces
- collection of name definitions, such as class and var declarations

Global Namespace
- namespace where code that isnt in a specific namespace

Using Directive
using namespace Namespace;
- makes all definitions in std namespace available
- can have same name defined in two different namespaces but can only use one of those namespaces at a time
  - if name is defined in multiple namespaces, must use scope resolution operator to specify which namespace is used
- using directive applies only to the block from where it is placed
  - {
      using namespace NS1;
      myFunction();
    }
    {
      using namespace NS2;
      myFunction();
    }

Creating a Namespace
- to placecode in a namespace, place it in a namespace grouping:
namespace Name_Space_Name {}

Using Declaration
- can specify individual names from namespace
using Name_Space::One_Name;
- makes One_Name from the namespace Name_Space available but not the other names in Name_Space

Qualifying Names
- specifies where name comes from
- use qualifier and scope-resolution operator
- NS1::fun();  <-- fun() comes from namespace NS1

Difference between Using Declaration and Using Directive
1. Using declaration makes only one name in the namespace available to your code, while a using directive makes all the names in a namespace available
2. Using declaration introduces a name into your code so no other use of the name can be made, while a using directive only potentially introduces the names in the namespace
  - if NS1 and NS2 both provide definitions of myFunction,
    - using namespace NS1;
      using namespace NS2; <-- legal as long as myFunction is not used
    - using NS1::myFunction;
      using NS2::myFunction;  <-- illegal

- We name namespaces with unique strings like last name, as it reduces the chance of other namespaces with the same name

Unnamed Namespaces
- compilation unit: a file along with all files included in file
  - every compilation unit has an unnnamed namespace
    - written in the same way, but no name
    - local to compilation unit
- use unnnamed namespaces to keep things local
- namespace {
  ...
}

Global vs Unnamed Namespaces
- Global
  - No namespace grouping
  - global scope
- Unnamed Namespace
  - Has namespace grouping, just no name
  - local scope

Hiding helper functions
- make private member function
- place in unnamed namespace if function does not need a calling object
