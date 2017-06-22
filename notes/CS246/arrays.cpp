int foo [5] = { 16, 2, 77, 40, 12071 };
int baz [5] = { };   // all 0


- call-by-reference
- value can be changed

for (datatype varname : array) {

}

e.g.
'
for(int x : arr) {
cout << x << endl;
}
'

Pass by Reference
int name(int& b) {
b = 3;  // b is now 3
return 0;
}
int& a = b;  // sets a's address to b's address


Multi-dimensional array
- first dimension not given, but second dimension is given
- e.g. const char p[][100]

Static Arrays
- arrays are CONSTANT pointers (cannot change where they point to)

Dynamically Allocated Arrays
- an array whose size is not specified when writing the program
- use new keyword
- instead of a[10], we have a = new double[size];

delete[] : destroys a dynamically allocated array

Returning an Array
- cannot return an array type
- must return a pointer to the array
- int[] function(); // ILLEGAL
- int *function(); // LEGAL

Pointer Arithmetic
- d = new double[10];
- d => address of d[0]
- d + 1 => address of d[1]
- d + 2 => address of d[2]

Resizing a dynamic array
1. Allocate a new[] array and store it in a temp pointer
2. Copy over previous values
3. Delete[] old array
4. Change any necessary pointer to array and size
int* newArr = new int[new_size];
std::copy(oldArr, oldArr + std::min(old_size, new_size), newArr);
delete[] oldArr;
oldArr = newArr;

Multi-dimensional Dynamic Arrays
typedef int* IntArrayPtr;
IntArrayPtr *m = new IntArrayPtr[3];
for (int i = 0; i < 3; i++) {
  m[i] = new int[4];
}
  - creates an array of 3 pointers
  - allocates each an array of 4 ints


Vectors
- arrays that grow and shrink
- vector<Base_Type>
- indicates template class
- e.g. vector<int> v;
- Add elements: v.push_back(x);
- Get the size: v.size();
- Get memory currently allocated: v.capacity();
- different than size()
- capacity > size
- Set capacity: v.reserve(size);
