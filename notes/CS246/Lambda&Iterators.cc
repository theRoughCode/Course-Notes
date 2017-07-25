- constuct an unnamed function object capable of capturing variables in scop
[capture](params)->{}

Capture
- a comma-separated list of zero or more captures
- e.g. [a, &b] a is captured by copy and b is captured by reference

e.g. [&]{std::cout << x << '\n';}
     [x](int ) { return n < x;}


Iterators
#include <iterator>
- an object that points to some elementin a range of elements
- most obvious form is a pointer that can be iterated with increment operator

istream_iterator
e.g. std::istream_iterator<double> eos;

ostream_iterator
e.g. std::ostream_iterator<int> out_it(std::cout, ",");
     std::copy(myvector.begin(), myvector.end(), out_it);

inserter
- insert iterators are special output iterators that inserts new elements at a specific position in the container
- container needs to have an insert member function

front_inserter
- inserts at the front
