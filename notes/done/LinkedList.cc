Example of Linked List Copy Constructor
struct Node {
  int data;
  Node *next;
  Node(int data, Node *next) : data {data}, next{next} {}
  Node (const Node &other): data {other.data}, next{other.next ? new Node {*other.next} : nullptr} {}
  ~Node(){
    delete next;
  }
};
Node m = *n;  // calls copy constructor
Node *p = new Node{*p}; // calls copy constructor

The copy constructor is called when
1. object is initialized by another object
2. object is passed by value
3. object is returned by function

Implicit Type Conversion
struct Node {
  Node(int data) : data {data}, next{nullptr} {}
};
Node n(4);
Node n = 4;

Explicit Type Conversion
- use explicit keyword
struct Node {
  explicit Node(int data) : data {data}, next{nullptr} {}
};
Node n(4); //OK
Node n = 4;  //Not OK

Example of LinkedList Assignment Operator
Node &operator =(const Node &other) {
  if(this == &other) return *this;
  data = other.data;
  delete next;
  next = other.next ? new Node (*other.next) : nullptr;
}

Copy and Swap Idiom
- strong exception guarantee for resource managing class
Normal Way:
1. Check for first assignment
2. Free up memory
3. Allocate new memory
4. Deep copy similar to copy constructor
- doesnt leak memory
- DOES NOT maintain the state of object when exception is thrown
  - new throws exception
  - delete next;
    next = other.next ? new Node (*other.next) : nullptr;
  - if new throws error, next has lost its data
- one solution is to perform deep operation before changing the state of the object
- or use copy and swap Idiom
- make use of copy constructor to copy to temp value then swap this object with the temp

Copy and Swap LinkedList Example
#include <utility>
struct Node {
  ...
  void swap(Node &other){
    using std::swap;
    swap(data, other.data); // data now contains other.data, other.data contains your data
    swap(next, other.next);
  }
  Node &operator =(const Node &other) {
    Node temp = other;  // copy constructor
    swap(temp);  // swap temp with this
    return *this;
  }
}


Move Constructor
- used with R-values (&&)
- removes need for deep copy or delete
struct Node {
  // Move constructor with R-value
  Node(Node &&node) : data {other.data}, next {other.next} {
    other.next = nullptr;  // R-value will be destroyed so must prevent lost heap mem
  }
}

Node m;
m = addOne(n);
Node &operator =(Node &&other){
  using std::swap;
  swap(data, other.data); // swap values of this with other (R-value to be destroyed)
  swap(next, other.next);
  return *this;
}


Copy/Move Elision
- Optimization technique where compilers are required or permitted to omit the copy/move constructors, even if these constructors and destructors have observable side effects
- prevents extra copies
- can disable with -fno-elide-constructors
struct C {
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
};

C f() {
  return C();
}

int main() {
  std::cout << "Hello World!\n";
  C obj = f();
}

The following outputs are valid, depending on the compiler:
- 'Hello World!
A copy was made.
A copy was made.'
- 'Hello World!
A copy was made.'
- 'Hello World!'


Array of Objects
struct Vec {
  int x,y;
  Vec(int x, int y) : x{x}, y{y} {}
};
Vec *vp = new Vec[10];  // Error
Vec moreVectors[15]; // Error

Provide default constructor
Vec moreVec[3] = {
  Vec{0,0}, Vec{1,3}, Vec{2.1}
}
Vec *vp= new Vec*[5];
vp[0] = new Vec{0,0};
for (int i = 0; i < 5; i++){
  delete vp[i];
}
delete[] vp;


Mutable Fields
- mutable fields can be changed in constant methods
struct Student {
  mutable int numMethodCalls = 0;
  float grade() const {
    ++numMethodCalls;
    return
  }
}

Invariants
- set of asserts that must hold true from the creation to the destruction of objects
- i.e. exactly one of two member vars must be 0.  Can use a member function to check if invariant holds and raise an assert if invariant is broken

Encapsulation
- enforces invariants
struct Node {
  int data;
  Node *next;
  Node(int data, Node *next) : data {data}, next{next} {}
  ~Node(){
    delete next;
  }
};
// stacck-allocated
Node n1 {1, new Node{2, nullptr}};
Node n2 {3, nullptr};
Node n3 {4, &n2};

- When pushed off stack
  - n1: destructor called on n1, and its next node is deleted off heap
  - n2: nullptr so OK
  - n3: undefined behaviour/crash since n2 is being deleted
- To solve this, we use encapsulation

Example of Nested Class
class List {
  struct Node; // private nested class
  Node *l = nullptr;
public:
  void addToFront(int n);
  int ith(int i);
  ~List();
}

struct List::Node {
  int data;
  Node *next;
  Node(int data, Node *next) : data{data}, next{next} {}
  ~Node() {
    delete next;
  }
};
List::~List(){
  delete l;
}
void list::addToFront(int n) {
  l = new Node(n, l);
}
int List::ith(int i){
  Node *cur = l;
  for(int j = 0; j < i && cur; ++j) {
    cur = cur->next;
    return cur->data;
  }
}


Introduction to Design Patterns
- Software design pattern: a general reusable solution to a commonly occurring problem within a given context in software design
- e.g. Iterator in LinkedList

class List {
  struct Node;
  Node *list = nullptr;
public:
  class Iterator {
    Node *p;
  public:
    explicit Iterator(Node *p) : p{p} {};
    int &operator*(){
      return p->data;
    }
    Iterator &operator++() {
      p = p->next;
      return *this;
    }
    bool operator ==(const Iterator &other) const {
      return p == other.p;
    }
    bool operator !=(const Iterator &other) const {
      return !(*this == other);
    }
    Iterator begin() {
      return Iterator(list);
    }
    Iterator end() {
      return Iterator(nullptr);
    }
  }
}
List lst;
lst.addToFront(1);
lst.addToFront(2);
lst.addToFront(3);
for(auto it = lst.begin(); it != lst.end; ++it){
  cout << *it << end;
}
// OR
for(auto n : lst) {
  cout << n << endl;
}
