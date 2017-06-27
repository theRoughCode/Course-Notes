'#include <iostream>'
'using namespace std'
'cout<<': output text to stdout
'cin>>': read stdin
  - cin only reads up to a whitespace
'cerr': error
- to include a var to a string:
  'cout << "You are" << age << "years old."'
Formatting numeric values for outpout
  - 'cout.setf(ios::fixed)'
  - 'cout.precision(2)'
  - forces all proceeding cout to this specified format

Two methods of initialization:
1. int count = 0;
2. int count (0);

Escape Sequences
'\n'
'\r'
'\t'

Raw String Literals
 - 'R"(string)'

Type Casting
- '(data type to cast)'
- static_cast<Type> (Expression)
  - function that takes in a type and returns an "equivalent" value of type Type
  - does not change the value of variable in expression
- const_cast<Type> (Expression)
  - cast away constantness
- dynamic_cast<Type> (Expression)
  - downcasting from a type to a descendent type
- reinterpret_cast<Type> (Expression)
  - implementation-dependent cast

Enums
 - Variable that cna only take on specific values
 - enum car = { "Toyota", "Mercedes", "BMW" }

 Opening a text file
 - "#include <fstream>"
 - "using namespace std"

"fstream inputStream
 inputStream.open("player.txt")
 inputStream >> score >> firstName >> lastName"

 Input File Stream
  - 'ifstream in ('inputfile.in')'
  - 'assure' ensures successful opening of file

  - 'cin.fail()' if previous input op failed, including eof
  - 'cin.bad()'
  - 'cin.good()'
  - 'cin.eof()' end of file
  - 'cin.clear()' resets the state to good (sets failbit to false)
  - 'cin.ignore()' will skip until the next newline

  To skip over a bad input, use 'ignore()' then 'clear()'



 '#include <string>' needed to use strings

- c-string
- 'endl': end line


Operator
 - inserter: <<
 - extractor: >>
  - parse the info that's expected by the destination object
  - If type doesn't match, an error will be displayed


  Read and echo, stop at bad on EOF
  '
  int main() {
    int i;
    while(true){
      cin >> i;
      if(cin.fail()) break;
      cout << i << endl;
    }
  }
  '

Converting String From and To Integer
- use 'stringstream'
- To convert from string to int:
'
string s = "42 -42";
istringstream iss{s};
int x, y;
iss >> x >> y;
'
- To convert from int to string:
'
ostringstream oss;
oss << 23 << "+" << 124;
string s = oss.str();
'
