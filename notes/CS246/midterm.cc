CS 246 Midterm
- Programming (shorter than assignment)
- Theory

1. Bash and Regular Expressions

1)
i) lines that contain CS 2XX where XX are digits
CS 2[0-9][0-9]

ii) lines that contain at least two 4s
CS (44[0-9]|4[0-9]4|[0-9]44)

iii) lines that contain only a whitespace-delimited list of integers
- assume list is non-empty
^(-?[1-9]([0-9]*)|0)( +(-?[1-9]([0-9]*)|0)*$

iv) (([1-9][0-9]*)?x(\^[1-9][0-9]*)?|0|[1-9][0-9]*)
    (+|-)

2)
- bash is all about string replacements
a)  - argument is "*" literal -> lists contents of directory "*"
    - ERROR -> no directory called "*"
b) ERROR -> no command called x
c) output: a b c
d) ERROR -> no command called x
e) output: a b c

2. Bash Programming Question
for test in in $(cat $1); do
  if [ -r ${test}.in ]; then  // -r == if exists and is readable
    input=${test}.in
  else
    input = $(mktemp)
  fi
  if [ -r ${test}.out ]; then
    output=${test}.out
  else
    output=$(mktemp)
  fi
  tmp=$(mktemp)
  $2 < $input > $tmp
  diff $temp $output > /dev/null
  if [ $? -ne 0 ]; then
    echo "Test failed: ${test}"
    echo "Input:"
    if [ -r ${test}.in ]; then
      cat $input
    else
      echo
    fi
    echo "Expected:"
    if [ -r ${test}.out ]; then
      cat $output
    else
      echo
    fi
    echo "Actual:"
    cat $tmp
done

3. Programming Question
string getName(string &s) {
  stringstream ss;
  ss << s;
  string firstName = "", lastName = "", id = "";
  while(s.length() > 0) {
    string name;
    ss >> name;
    firstName += name + " ";
    id += (name[0] - ('A' - 'a'));
    ss.clear();
    ss.str("");
    ss << s;
  }
  ss >> lastName;
  id += (lastName[0] - ('A' - 'a'));
  id += lastName.substr(1, s.length());
  return lastName + ", " + firstName + "(" + id + ")";
}

4. Programming Question: Big 5
// Destructor
~Data(){ delete[] arr; }
// Copy Constructor
Data(const Data &other): arr {new int[other.capacity]}, datalen {other.datalen}, capacity {other.capacity} {
  for (int i = 0; i < datalen; i++) {
    arr[i] = other.arr[i];
  }
}
// Move Constructor
Data(Data &&other):  arr{other.arr}, datalen {oter.datalen}, capacity{other.capacity} {
  other.arr = nullptr;
}
// Copy Assignment operator
Data &operator=(const Data &other) {
  Data tmp(other);
  swap(tmp.arr, curr);
  swap(tmp.datalen, datalen);
  swap(tmp.capacity, capacity);
  return *this;
}
// Move Assignment operator
Data &operator=(Data &&other) {
  swap(other.arr, arr);
  swap(other.capacity, capacity);
  swap(other.datalen, datalen);
  return *this;
}
