Topics
-Midterm topics
-Polymorphism: (Introduced before the midterm, completed after) Polymorphism and Virtual Functions including Late Binding, pure virtual functions, abstract class, Virtual function and extended type compatibility, final keyword, the difference between overriding and redefinition, Extended type compatibility, slicing problem,  virtual destructor (why it is good practice and when it is necessary) (Absolute C++ 6th Ch15) [Inheritance is "prerequisite" to polymorphism].
- The danger use of array polymorphically its solution.
-UML: (Started before the midterm, completed after)(Association, aggregation, composition and inheritance, visibility: public, private, protected, abstract class and pure virtual function (abstract method), static keyword, more examples of given in design patterns)
- Copy constructor/ assignment operator with Inheritance
- Move constructor/ assignment operator with Inheritance (std::move)
- pure virtual destructor: when and why
- Partial Assignment and mixed assignment problems and a solution [recommendation])
- Template classes and functions (Absolute C++ 6th Chapter 16, Example of template with iterator)
- STL: vector/iterators
- Exceptions (Absolute C++ 6th Chapter 18, Example: out_of_range with vectors, stack unwinding, rethrow exception throw vs throw s, "Throw by value, catch by reference", never destructor to emits exception, exception and error codes: comment on speed and efficiency)
- Design Patterns(Observer, Decorator, Factory Method, Template Method, NVI Idiom)
- STL map (definition, example, erase, count, iterating  through the map using range based for loop, std::pair (first and second fields), how to make your own map class)
- Visitor Design Pattern (double dispatch, adding functionality without changing class hierarchy code)
- Circular Dependencies: solution: forward declare when possible
- Compilation Dependencies: when to forward declare vs when to include
- pImpl Idiom (Generalize the pImpl Idiom: Bridge Design Pattern)
- Measure of design quality: coupling and cohesion.
- Decoupling the interface: MVC
-Exception Safety (example, C++ guarantee on stack-allocated object, RAII, smart pointers including unique_ptr and shared_ptr - difference and when to use each, levels of exception safety: basic, strong, no throw, exception safety and STL example (vector), emplace_back and its strong exception guarantee: copy vs move, noexcept keyword at least on move and swap, how to check if the function is noexcept).
- Casting: (static_cast, reinterpret_cast, const_cast, dynamic_cast, casting on smart pointers, prefer polymorphism over dynamic_cast when possible)
- runtime type identification (RTTI), typeid, cating on references, bad_cast exception, solution to mixed/partial assignment problem with virtual operator= and dynamic cast on reference, why dynamic_cast needs polymorphic type (virtual method/destructor/inheritance)) [Thinking in C++ volume II Ch8 Runtime type Identification)]
- How C++ implement late binding? size of classes example with or without virtual methods, vtable and vptr, picturing object at runtime with vptr and vtable and virtual methods. [Thinking in C++ volume I Ch15 Polymorphism and virtual functions]
- Multiple inheritance (Interface vs Implementation inheritance, duplicate subobject example using sizeof and addresses, object layout, diamond inheritance, ambiguity and resolution using specifying a parent class, solution using virtual base class or virtual inheritance) [Thinking in C++ volume II Ch 8 Multiple Inheritance]
- STL Algorithms [for_each, find, count, copy, transform], function objects, lambdas, Iterators [stream iterators, inserters (front_inserter, back_inserter)]
- Introduction to Concurrency (definition, approaches, why to use concurrency: performance, separation of concerns,  hello world concurrency example, basics of thread management, issue of exception safety)

1.a.
Use Visitor Pattern
class A {
  virtual void visit(B& b) = 0;
};
class A1 {
  void accept(B &b) {
    b->visit(*this);
  }
};
class A2 {
  void accept(B& b) {
    b->visit(*this);
  }
};

class B {
  virtual void accept(A1& a) = 0;
  virtual void accept(A2& a) = 0;
};

class B1 {
  void visit(A1 &a) {}
  void visit(A2 &a) {}
};

b.
Use Bridge Pattern
UI <>---  GraphicsLib <<abstract>>
          |           |
        OpenGL      DirectX

Bridge Pattern vs Strategy Pattern

c. Observer Pattern

d. Decorator Pattern

Potential Problems:
1. Identify a Pattern
2. UML
3. Explain a pattern
4. Implement design patterns

---------------------------------------------------------------
2. A, B <-- include
C, D, E, F, G, H, I, J <-- Forward Declare (pointers or references, parameter, return type)
"http://umich.edu/~eecs381/handouts/IncompleteDeclarations.pdf"

---------------------------------------------------------------
3.
Levels of Exception Safety:
1. No-throw (basic, strong, no exceptions thrown)
2. Strong - If exception is thrown, method does nothing (states dont change)
3. Basic - If exception is thrown, program is in valid state (no memory leak, program invariants maintained)
4. No guarantee

i) Are there exceptions generated?
ii) If not -> no-throw
iii) If yes -> figure out what exception is throw

a) basic -> copy ctor called
b) strong -> exception can be thrown with make_unique(). If exception thrown, other statements dont execute as no-throw
* Allocating memory can always throw exceptions
c) no-throw -> seg faults are not exceptions (dereferencing nullptr)

What could be asked?
1. Explain/define the levels of exception safety
2. Write some code with some guarantee
3. Modify code to get some level of exception safety
---------------------------------------------------------------
4.
a)  We want a binary tree wrapper class and a node class
template<class T>
class Node {
  T data;
  unique_ptr<Node> left, right;
public:
  Node(T data) : data { data }, left { make_unique<Node>() }, right { make_unique<Node>() } {}
  ~Node() {
    delete left;
    delete right;
  }
};

template<class T>
class BinTree {
  unique_ptr<Node<T>> root;
public:
  BinTree();
  BinTree(const BinTree<T> &o);
  BinTree(BinTree<T> &&o);
  BinTree<T> &operator=(BinTree<T> &o);
  BinTree<T> &operator=(BinTree<T> &&o);
  ~BinTree();
};

template<class T>
BinTree<T>::BinTree() : root { nullptr } {}
template<class T>
BinTree<T>::BinTree(const BinTree<T> &o) : root { other.root ? make_unique<Node<T>>(other->root) : nullptr } {}
template<class T>
BinTree<T>::BinTree(BinTree<T> &&o) : root { std::move(other.root) } {} // move ctor works with unique pointers
template<class T>
Node<T>::Node(const Node<T> &other) : data { other.data }, left { other.left ? make_unique<Node<T>>(other->left) : nullptr }, right { other.right ? make_unique<Node<T>>(other->right) : nullptr } {}
template<class T>
Node<T>::Node(const Node<T> &&other) : data { std::move(other.data) }, left { std::move(other.left) }, right { std::move(other.right) } {}

For ++ operator for Node:
1. If have right child, find left most descendent in right subtree
2. If not, find first ancestor on the right

---------------------------------------------------------------------------
5.
4) Partial assignment problem:
Base *b = new Derived();
*b = Derived();  // r-value  --> calls base overloaded operator
  Move assignment operator suffers from partial assignment operator

  Mixed assignment problem:
