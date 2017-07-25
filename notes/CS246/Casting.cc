Type Casting
- '(data type to cast)'
- static_cast<Type> (Expression)
  - function that takes in a type and returns an "equivalent" value of type Type
  - superclass pointer to subclass pointer
  - does not change the value of variable in expression
- const_cast<Type> (Expression)
  - cast away constantness or volatile
  void g(int *p);
  void f(const int *p) {
    g(const_cast<int*>(p));
  }
- dynamic_cast<Type> (Expression)
  - type safe downcasting
  - downcasting from a type to a descendent type
  - safer than static_cast, but less efficient
  - returns null if different types
  Book *pb;
  Text *pt = static_cast<Text>(pb)->getTopic();  // might throw error
  // alternative
  Book *pb;
  Text *pt = dynamic_cast<Text>(pb);  // might throw error
  if(pt) cout << pt-?getTopic();
  else cout << "Not a Text";
  - if cast works => pt points to object
  - otherwise => nullptr
  - only works on classes that have at least one virtual method

- reinterpret_cast<Type> (Expression)
  - implementation-dependent cast, unsafe
  Student s;
  Turtle *t = reinterpret_cast<Turtle*>(&s);
  - forces student to be treated as turtle



Downcasting
- Dilemma: how to safely downcast
- Why use downcast? Should be using polymorphism
- dynamic_cast: type-safe downcast operation
  - return value is pointer to desired type only if cast is proper and successful otherwise returns nullptr
  Pet *b = new Cat; // Upcast
  Dog *d1 = dynamic_cast<Dog*>(b); // returns nullptr
  Cat *c1 = dynamic_cast<Cat*>(b);  // OK
- Using typeid(in <typeinfo>) and static_cast
  Circle c;
  Shape *s = &c; // Upcast
  s = static_cast<Shape*>(&c);
  if (typeid(s) == typeid)
- C++ RTTI(run-time type information)
  - discover info lost by Upcasting
  - dynamic_cast is a form of RTTI
  - typeid is used to detedct the types of the pointers
    - typeid takes an object, reference, or plinter and returns a reference to a global const object of type typeinfo
    - can be compared to each other with == and !=
    - can ask for name() of type which returns a string representation of the type name
- Polymorphic assignment problem
- Difference betweeen reference and pointer: reference is a constant pointer that is automatically dereferenced
Text t;
Book &b = t;
Text &tc = dynamic_cast<Text&>(b);
- throw bad_cast because there is no such thing as a null reference
Text &Text::operator=(const Book &other) {
  Text &textother = dynamic_cast<Text&>(other);
  if(this == &other) return *this;
  Book::operator=(other);
  topic = textother.topic;
  return *this;
}

Mechanism of RTTI (dynamic_cast)
When dynamic_cast<destination*> (src) is used:
1. source pointers RTTI info is retrieved
2. RTTI info of destination is fetched
3. Library routine then determines whether source pointers type is of destination type or base class type

Creating Your Own RTTI
- static_pointer_cast, const_pointer_cast, dynamic_pointer_cast all use share_ptr in <memory>
void whatid(shared_pointer<Book> b) {
  if(dynamic_pointer_cast<Comic>(b)) cout << "Comic";
  else if(dynamic_pointer_cast<Text>(b)) cout << "Text";
  else cout << "Normal Book";
}
- highly coupled with Book class hierarchy
- may indicated bad design
- Alternatives:
  - write virtual methods (polymorphism)
  - write visitor pattern
