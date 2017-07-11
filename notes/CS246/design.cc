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

Advice:
Use shared_ptr and unique_ptr instead of raw pointers as much as possible.  They will dramatically reduce memory leaks
