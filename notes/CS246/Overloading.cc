Overloading
- specify more than one definition of a function/operator

e.g.
const Money operator +(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount1, const Money& amount2);
bool operator ==(const Money& amount1, const Money& amount2);

const Money operator +( const Money& amount1, const Money& amount2) {
 int allCents1 = amount1.getCents( ) + amount1.getDollars( )*100;
 int allCents2 = amount2.getCents( ) + amount2.getDollars( )*100;
 int sumAllCents = allCents1 + allCents2;
 int absAllCents = abs(sumAllCents); //Money can be negative.
 int finalDollars = absAllCents / 100;
 int finalCents = absAllCents % 100;

 if (sumAllCents < 0) {
  finalDollars = -finalDollars;
  finalCents = -finalCents;
 }

 return Money(finalDollars, finalCents);
}

Returning by const value
- + operator returns an "anonymous object"
- if overloaded operator didnt return a const value
  - we can invoke member functions on it, allowing us to modify the anonymous object

Operator Overloading
- written similar to function definition except that the operator defnition includes the reserved word 'operator' before the operator name


Overloading Member Functions
- only one parameter not two
  - calling object serves as first parameter
- Money cost(1, 50), tax(0, 15), total;
  total = cost + tax;
  - If '+' was overloaded as a member operator, 'cost' is the calling object with tax as the single arg
  - think of it as total = cost.+(tax)
  - more efficient as there is no need to call accessor & mutator functions

Overloading Function Application '( )'
- Allows us to use an object of the class as if it were a function
- If class AClass has overloaded the fucntion application operator to have one arg of type int, and if anObject is an object of AClass, then anObject(42) invokes the overloaded function call operator

Overloading &&, ||, comma operator
- when overloaded, no longer uses short-circuit evaluation
- generally should not overload them

Comma Operator
- string together several expressions
- value of comma-separated list of expressions is the value on right
- e.g var = (count=19, incr=10, count+1);  <-- var = count+1
- has lower precedence than assignment operator so brackets are needed

Automatic Type Conversion
Money baseAmount(100, 60), fullAmount;
fullAmount = baseAmount + 25;
fullAmount.output( );
- 25 is of type int
- Since the '+' operator is not overloaded, the system looks to see if there is a constructor that takes a single argument of int and converts int '25' to a value of type Money
- Note that 25 + baseAmount wouldnt work as 25 cannot be a calling object.  This can be handled if we overload '+' as a Non-member
  -> biggest advantage of overloading an operator as a nonmember
  -> Overloading an operator as a nonmember gives automatic type conversion of all arguments.
  -> Overloading an operator as a member gives efficiency of bypassing accessor/mutator functions and directly accessing member vars
  -> Overloading as a friend function offers both advantages

Friend Functions
- A friend function of a class is not a member function of the class but it has access to private members/functions of that class
- nonmember functions that have all the privileges of member functions
- If your class has a full set of access and mutator functions, we can define nonmember overloaded operators using them
- Might not give efficient access to private member vars
- To make a funcion a friend function, we must name it as a friend in the class definition.
  -> We declare friend functions of a class in the class definition, similar to member functions, but they are NOT member functions.  They are ordinary functions with extra access to data members of the class
- called the same way as a nonmember function, no need for dot operator


3 WAYS TO OVERLOAD OPERATORS
1. Non-member, non-friends
2. Members
3. Friends


Friend Classes
- A class can be a friend of another class
- If class F is a friend of class C, then every member function of class F is a friend of class C
- Declare the friend class as a friend within other class
class F; // forward declaration
class C {
public:
  friend class F;
};
class F {}


Rules on Overloading Operators
- When overloading an operator, at least one parameter of the resulting overloaded operator must be of a class type
- Most operators can be overloaded as a member of the class, a friend of the class, or a nonmember, nonfriend
- The following operators can only be overloaded as (nonstatic) members of the class: =, [], ->, and ()
- Cannot create a new operator, can only overload existing operators
- Cannot change the number of arguments that an operator takes
- Cannot changeprecedence of an operator.  An overloaded operator has the same precedence as the ordinary version of the operator
  -> e.g. x*y + z => (x*y) + z
- The following operators cannot be overloaded: ., ::, sizeof, ?:, .*
- overloaded operators cannot have default arguments


References
- name of a storage location
int robert;
int& bob = robert;
  -> bob is a reference to the storage location for the var robert
  -> bob is an alias for robert: any change to bob will also be made to robert
- returning a reference allows us to overload certain operators in a more natural way
  -> e.g. double& sampleFunction(double& variable);
  -> should not return a local var because that generates an alias to a var that is destroyed once the function call is done

L-value: appears on the left-hand side of an assignment operator
R-value: appears on the right-hand side of an assignment operator

- Functions that return an l-value must return by reference

Caution: When a member function returns a member var of some class type, refrain from returning by reference to avoid external access to private member vars.  If you do, add a const to return value to protect access to member var

Overloading >> and <<
- use them to input and output objects of classes we define
ostream& operator <<(ostream& outputStream, const Money& amount) {
  int absDollars = abs(amount.dollars);
  int absCents = abs(amount.cents);
  if (amount.dollars < 0 || amount.cents < 0)
    //accounts for dollars == 0 or cents == 0
    outputStream << "$-";
  else
    outputStream << '$';
  outputStream << absDollars;
  if (absCents >= 10)
    outputStream << '.' << absCents;
  else
    outputStream << '.' << '0' << absCents;
  return outputStream;
}
  -> Note that the operator returns a reference
- >> is overloaded in a similar way, but the second argument receives the input valiue, so it cannot be a const
istream& operator >>(istream& inputStream, Money& amount)
{
 char dollarSign;
 inputStream >> dollarSign; //hopefully
 if (dollarSign != '$')
 {
   cout << "No dollar sign in Money input.\n";
   exit(1);
 }
 double amountAsDouble;
 inputStream >> amountAsDouble;
 amount.dollars = amount.dollarsPart(amountAsDouble);
 amount.cents = amount.centsPart(amountAsDouble);
 return inputStream;
}


Assignment Operator '='
- overload as a member operator
- default assignment operator copies values of member vars from one object of the class to the corresponding member vars of another object of the class

Overloading Increment/Decrement Operators
- need to distinguish prefix and postfix versions
- prefix version:
  -> overload as nonmember operator with one parameter
  -> overload a member operator with no parameters
- postfix version:
  -> add parameter of type int
  -> just a marker for compiler.  DO NOT give a second int arg when invoking it
- e.g.
class IntPair {
public:
  IntPair operator++(); // Prefix version
  IntPair operator++(int); // Postfix version
}
IntPair IntPair:: operator++( ) //Prefix version
{
 first++;
 second++;
 return IntPair(first, second);
}
IntPair IntPair:: operator++(int ignoreMe) //Postfix version
 {
 int temp1 = first;
 int temp2 = second;
 first++;
 second++;
 return IntPair(temp1, temp2);
}


Overloading Array Operator []
- overload for a class so that it can be used with objects of hte class
- To use it on the left-hand side of an assignment operator, the operator must be defined to return a reference
- MUST be a member function
char& CharPair:: operator[](int index)
{
 if (index == 1) return first;
 else if (index == 2) return second;
 else
 {
   cout << "Illegal index value.\n";
   exit(1);
 }
}

Overloading based on L-value vs R-value
l-value: int& f();
r-value: const int& f() const;

Overloading the Assignment Operator
