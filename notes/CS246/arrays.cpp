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


 Resizing a dynamic array
 1. Allocate a new[] array and store it in a temp pointer
 2. Copy over previous values
 3. Delete[] old array
 4. Change any necessary pointer to array and size
 int* newArr = new int[new_size];
 std::copy(oldArr, oldArr + std::min(old_size, new_size), newArr);
 delete[] oldArr;
 oldArr = newArr;


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
