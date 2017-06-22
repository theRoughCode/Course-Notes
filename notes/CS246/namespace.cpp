Interface: group of class definitions and functions and operator declarations
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
- namespace where code that isn't in a specific namespace

Using Directive
using namespace Namespace;
- can have same name defined in two different namespaces but can only use one of those namespaces at a time
- using directive applies only to the block from where it is placed

Creating a Namespace
- to placecode in a namespace, place it in a namespace grouping:
namespace Name_Space_Name {}

Using Declaration
using Name_Space::One_Name;
- makes One_Name from the namespace Name_Space available but not the other names in Name_Space

Difference between Using Declaration and Using Directive
1. Using declaration makes only one name in the namespace available to your code, while a using directive makes all the names in a namespace available
2. Using declaration introduces a name into your code so noother use of the name can be made, while a using directive only potentially introduces the names in the namespace
  - if NS1 and NS2 both provide definitions of myFunction,
    - using namespace NS1;
      using namespace NS2; <-- legal as long as myFunction is not used
    - using NS1::myFunction;
      using NS2::myFunction;  <-- illegal
