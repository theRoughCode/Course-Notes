Call-by-value
- local variable
- only value of arg is passed in

Call-by-reference
- arg is a variable
- variable itself is plugged in, so var's value can be changed by function
- 'datatype& var'
-e.g.
void getNumbers(int& num1, int& num2) {
  num1 += num2;
  num2 += num1;
}
getNumbers(firstNum, secondNum);
  - function is not given variable name, instead, given the ADDRESS
  - firstNum's value will be changed to firstNum+secondNum
  - secondNum's value will be changed to firstNum+2*secondNum


Definitions:
- Formal Parameters
  - listed in function declaration
  - used in body of function
  - placeholder that is filled in with something when the function is called
- Argument
  - used to fill in a formal parameter
  - listed in paranthesis in function call
  - plugged in to formal parameters when function is invoked
- Call-by-value/reference
  - mechanism that is used in the pluggin-in process
  - call-by-value:
    - only value is passed in
    - formal parameter is a local variable initialized to value of corresponding arg
  - call-by-reference
    - argument is variable, entire variable is used
    - arg var is substituted for the formal parameter so that any change to formal parameter is made to the argument variable
