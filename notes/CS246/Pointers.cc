Pointers
- memory address of a var
- DataType *var1, *var2, ...;

Dereferencing Operator '*': *p1
Addressof Operator '&': &v1

v1 = 0;
p1 = &v1;
  -> v1 is the same as *p1


new Operator:
- creates a new dynamic var of a specified type and returns a pointer that points to this new var
MyType *p;
p = new MyType;
- If the type is a class type, the default constructor is called for the newly created dynamic var.  We can specify a different constructor by invludign args, as follows:
MyType *p;
p = new MyType(32, 17);
- Similarly, we can initialize dynamic vars of nonclass types
int *n = new int(17);  // *n == 17


Basic Memory Management
- Freestore or heap is reserved for dynamically-allocated vars
- new dynamic vars consumes memory in the heap
- if there is inssufficient memory to create the new var:
  -> in earlier versions, new returns NULL
    - NULL is actually the number 0
  -> newer stndards, new terminates program
- Good practice to recycle any freestore memory used by dynamic vars
- delete operator eliminates a dynamic var and returns the memory to the freestore manager so that the memory can be reused
delete p;  // value of p is undefined
- the undefined pointer vars are called dangling pointers
- GOOD PRACTICE: set dangling pointer vars equal to NULL

Automatic vars: local vars, automatically created when function is declared and destroyed when call ends

Global Vars/Statically Allocated Vars: vars declared outside of any function or class definition

typedef: define an alias for any type name or definition
  - usually placed outside the body of main so that it is available to entire program

Dynamically Allocated Arrays
- an array whose size is not specified when writing the program
- use new keyword
- instead of a[10], we have a = new double[size];

delete[] : destroys a dynamically allocated array


Returning an Array
- cannot return an array type
- must return a pointer to the array


-> Operator
- combines dereferencing and caling a member of a struct or class object pointed to by a given pointer
e.g.
Record *p;
p = new Record;
p->number = 2001;
p->grade = 'A';  // same as (*p).grade

this Pointer
- refer to calling object

Shallow Copy vs Deep Copy
- Shallow Copy: copy contents of member vars from one object to the other
  - fine if not pointers involved
- Deep copy: creates copies of what each member var is pointing to
  - creates a separate but identical copy
