Measures of Design Quality:
1. Coupling
2. Cohesion

Coupling:
- degree of interdependence between software modules
- Low coupling is better

Low to High Coupling:
1. Modules communicate via function calls with basic parameters returns
2. Modules pass arrays/structs back and forth
3. Module affect each others control flow
4. Modules share global data
5. Modules have access to each others implementation (friends)

High Coupling:
1. Changes to one module require greater changes to other modules
2. Harder to reuse individual modules

Cohesion:
- How closely elements of a module are related to each other
- High cohesion is better

Low to High Cohesion:
1. Arbitrary grouping of unrelated elements, e.g. <utility>
2. Elements have a common theme, otherwise unrelated, perhaps share base code, e.g. <algorithm>
3. Elements maniplate a state over lifetime of an object, e.g. open/read/close files
4. Elements pass data to each other
5. Elements cooperate to perform exactly one task

Low Cohesion:
1. Poorly organized code2. Hard to understand  and maintain


Decoupling the Interface (MVC)
- MVC: Model-View-Controller
class ChessBoard {
  istream &in;
  ostream &out;
public:
  ChessBoard(istream &in, ostream &out) : in{in}, out{out} {
    cout << "you move";
  }
}
- chessBoard class should not be doing any communication at all

Single Responsibility Principle: A class should have only one reason to change

- confine user interaction outside game class
  -> total freedowm to change how the game interacts
- Do not use main as you may want to reuse or extend the communication code -> hard reuse inside main
- Better solution: have a class to manage interactions, MVC
Model -> Controller <- View

Model
- the brains
- can have multiple views (text, graphics)
- doesnt need to know about their details
- class observer pattern (or could communicate through controller)

Controller
- mediate communication between model and view
- may encapsulate turn-taking or entire game rules (tradeoff with model)
- may communicate with user for input or view


Exception Safety
void f() {
  MyClass *p = new MyClass;
  MyClass mc;
  try {
    y();
  } catch {
    delete p;
    throw;
  }
  delete p;
}
- tedious and error prone (duplication of code)
- C++ guarantees us that the destructors of stack-allocated objects will run
- Use stack-allocated objects as much as possible

RAII (Resource Acquisition Is Initialization) Idiom
- Every resource should be wrapped in a stack-allocated object, where destructor deletes it
- e.g. Files
{
  ifstream f {"file"};
}
- Acquiring resource happens by initializing the object f;
- Dynamic Memory
class std::unique_ptr<T>
  - holds a T* which you supply to constructor (#include <memory>), the destructor will delete this pointer
  - can dereference this object just like a pointer
void f() {
  auto p = std::make_unique<MyClass>();
  MyClass mc;
  g();
} // No leak even if g throws
Difficulty:
auto p = std::make_unique<C>();
unique_ptr<C> q = p; // ERROR, cannot have multiple pointers pointing to same object
template<typename T>
class unique_ptr {
  T* ptr;
public:
  unique_ptr(T* p) : ptr{p}{}
  ~unique_ptr() {delete ptr;}
  unique_ptr(unique_ptr<T> &other) = delete;
  unique_pt(unique_ptr<T> &&other) : ptr{other.ptr} {
    other.ptr = nullptr;
  }
  unique_pt<T> &operator=(const unique_ptr<T> &other) = delete;
  unique_pt<T> &operator=(unique_ptr<T> &&other) {
    using std::swap;
    swap(ptr, other.ptr);
    return *this;
  }
  T &operator*() {
    return *ptr;
  }
}

use std::shared_ptr;

void f() {
  auto p1 = std::make_shared<MyClass>();
  if(...) {
    auto p2 = p1;
  } // p2 is popped bu object is NOT deleted
}

- Shared pointers will only delete the pointer once the count of shared pointers is zero

Advice:
Use shared_ptr and unique_ptr instead of raw pointers as much as possible.  They will dramatically reduce memory leaks

Three levels of exception safety:
1. Basic Guarantee
  - If exception occurs, the program is valid, but in an unspecified state
  - Nothing is leaked
  - Class invariant are maintained
  - e.g. Regular copy constructor where data is lost
2. Strong Guarantee
  - Exception is raised while executing error
  - The state of the program will be as if the function had not been called
  - e.g. Copy and Swap idiom
3. Nothrow Guarantee
  - Function will never throw an exception
  - no exception is emitted outside of the function
  - Always accomplishes its task
  - use noexcept

e.g.
class A {}
class B {}
class C {
  A a;
  B b;
public:
  void f() {
    a.method1();
    b.method2();
  }
};
- This is a basic guarantee.
- If a.method1() runs and b.method2() has an error, the state of a is changed without b changing
- Results in a "partial function"

// To Provide Strong Exception Guarantee
- Use Copy & Swap Idiom
class C {
  A a;
  B b;
public:
  void f() {
    A aTemp = a;  // calls copy ctor
    B bTemp = b;
    aTemp.method1();
    bTemp.method2();
    a = aTemp;
    b = bTemp;
  }
}
- Because copy assignment operator could throw, we dont yet have strong exception guarantee
- Better if we could guarantee that the swap part is a nothrow
- A non-throwing 'swap' operation is at the heart of writing exception-safe code
- Key observation: Copying pointers cannot throw
  - Solution: Use pImpl Idiom

struct Cimpl {
  A a;
  B b;
}
class C {
  unique_ptr<CImpl> pImpl;  // pointer to implementation
public:
  auto temp = make_unique<CImpl>(*pImpl);
  temp->a.method1();
  temp->b.method2();
  std::swap(pImpl, temp);
};  // Nothrow

Exception Safety and the STL vectors
- encapsulate heap-allocated array
- RAII when stack-allocated vector goes out of scope, the internal heap-allocated array is free
void f() {
  vector<MyClass> v;
}
- when v goes out of scope, MyClass dtor runs on all items in the array and the array is freed
void g(){
  vector<MyClass*> v;
}
- when v goes out of scope, pointers dont have dtors so only the array is freed while pointers are not
void g(){
  vector<MyClass*> v;
  for(auto &x: v) delete x;
}
// OR
void h() {
  vector<shared_ptr<MyClass>> v;
}
- when v goes out of scope, shared ptr dtors free objects once count of shared ptrs goes to zero

vector<T?::emplace_back: offers strong guarantee
- if array is full, it allocates a new, larger array
- copy the objects over (copy ctor)
- if a copy ctor throws:
  - destroys new array
  - old array is intact
  - strong guarantee
- else delete old array

- Allocate new larger array
- move the objects over
- delete old array

The problem:
- if move ctor were to throw, the vector<T>::emplace_back wouldnt offer strong guarantee because the original array would no longer be intact.
- But, emplace_back promises the strong guarantee.
- Therefore, if the move offers the nothrow guarantee, emplace_back will use the move ctor otherwise it will use the copy ctor which may be slower
- Move operations should provide nothrow guarantee if possible and should indicate that they do so
class MyClass {
public:
  MyClass(MyClass &&other) noexcept {}
  MyClass &operator=(MyClass &&other) noexcept {}
}
- If you know a function will never throw or propagate an exception, declare it noexcept
  - Will facilitate optimization of your code
  - Move & Swap should be noexcept
- In general, exceptions > error codes for program design
