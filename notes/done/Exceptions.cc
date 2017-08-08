int milk, donuts;
cin << milk << donuts;

double dpg = donuts/static_cast<double>(milk);
cout << dpg;
- If milk == 0, there will be an error because of division by zero
- We can use if statements to handle the edge case or try-and-catch blocks

try {
  int milk, donuts;
  cin << milk << donuts;

  if (milk <= 0) throw donuts;

  double dpg = donuts/static_cast<double>(milk);
  cout << dpg;
} catch(int e) {
  cout << "We have " << e << " donuts, and no milk!" << endl;
}

Try Block
- contains the code that tells the program what to do when everything goes smoothly
- if something unusual happens, we throw an exception, and flow of control is transferred to the catch block

Catch Block
- contains code that executes when try block throws an exception
- executing the catch block is known as "catching the exception" or "handling the exception"
- takes in a catch-block parameter
  1. preceded by a type name that specifiies the type of thrown value that the catch block can catch
  2. gives a name for thrown value to be used in catch block

Defining Your Own Exception Class
- common to define a class whose objects can carry precise info on what is thrown to the catch block
- allows us to have a different type to identify each possible kind of exceptional situation
- An exception class is just a class
class NoMilk {
public:
  NoMilk(){}
  NoMilk(int num) : count(num) {}
  int getCount() const {return count;}
private:
  int count;
}
int main () {
  try {
    int milk, donuts;
    cin << milk << donuts;

    if (milk <= 0) throw NoMilk(donuts);

    double dpg = donuts/static_cast<double>(milk);
    cout << dpg;
  } catch(NoMilk e) {
    cout << "We have " << e.getCount() << " donuts, and no milk!" << endl;
  }
}

catch(...): special kind of catch block that catches a thrown value of any type


Multiple Throws and Catches
- a try block can throw any numnber of exception values
try {
  int milk, donuts;
  cin << milk << donuts;

  if (milk < 0) throw NegativeNumber("milk");
  if (milk == 0) throw DivideByZero();

  double dpg = donuts/static_cast<double>(milk);
  cout << dpg;
} catch(NegativeNumber e) {
  cout << "Cannot have a negative number of " << e.getMessage() << endl;
} catch (DivideByZero) {  // no need to give parameter if not used
  cout << "ERROR: DIVIDE BY ZERO!";
}
- when catching multiple exceptions the order of the catch blocks can be important
- the catch blocks are tried in order
- place more specific exceptions first

Trivial Exception Classes
class DivideByZero{};
- This exception class has no member data, but it allows us to throw an object of this class and activate the appropriate catch block


Throwing an Exception in a Function
- if we want to define the catch block outside of a function, the function can throw an exception that is handled when the function is called within a try block
try {
  quotient = safeDivide(num, denom);
} catch(DivideByZero) {
  cout << "ERROR: DIVSION BY ZERO!";
}
double safeDivide(int top, int bot) throw (DivideByZero) {
  if (bottom == 0) throw DivideByZero();
  return top / static_cast<double> (bottom);
}

Exception Specification
- If a function does not need to catch an exception, it should warn the programmer that the invocation of the function might throw an exception
- Exception types throw are listed in an exception specification, also known as the "throw list"
- Exception specification appears in both the function declaration and definition
- Multiple function declarations must have identical exception specifications
- If there are multiple possible exceptions, the exception types are separated by commas
    - void someFunction() throw (DivideByZero, SomeOtherException);
- If a function should not throw any exceptions that are caught inside the function, we use an empty exception specification
    - void someFunction() throw ();
- any exceptions thrown that arent in the throw list invoke unexpected()
  - default action of unexpected() is to end the program
  - can be changed with 'set_unexpected';

C++11
- throw is deprecated
- use noexcept
- if a function might throw, omit any throw statement or use noexcept(false)
- if a function does not throw, use noexcept(true)

Inheritance and Exceptions
- If we have a derived class D of class B, and B is in the exception specification, then a thrown D will be treated normally with no automatic type conversion done
- if double is in the exception specification and an int value is thrown, the int value exception is not accounted for


Programming Techniques for Exception Handling
- separate throwing and catching into separate functions
  - throw within a function definition and listed in the exception specification, and place the catch clause in a different function
- NEVER let the destructor throw an exception as it might be called when dealing with another exception
  - have two active unhandled exceptions
  - program will abort immediately

Nested Try-Catch Blocks
- if an exception is thrown in the inner try block but not caught in any of the inner catch blocks, then the exception is thrown to the outer try block and possibly caught by an outer catch block
