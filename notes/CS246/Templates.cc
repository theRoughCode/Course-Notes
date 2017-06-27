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
