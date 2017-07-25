- concurrency and multithreading is a powerful tool to make your program run faster
- multithreading can be used to improve responsiveness

Concurrency
- 2 or more separate activities hapenning simultaneously
- Context switching: performed each time the computer switches from one task to another

Approaches to Concurrency
1. concurrency with multiple processes: divide app into multiple single threaded processes
  - pass msg to each other through interprocess communication channels
  - slow because OS provides protection to prevent one process to modify the data of other
  - processes communicate to each other through interprocess communication
2. concurrency with multiple threads: each thread runs independently of each other
  -share same address space
  - most data can be accessed from all threads
  - less overhead because OS has less book keeping to do
  - lack of protection
  - programmer must ensure data is consistent whenever accessed
  - rely on platform specific API

When not to use concurrency:
- when benefit not worth cost
- code harder to understand, more bugs
- unless potential performance gain is large enough
- having too many threads consume OS resources and might make the system run slower as a whole
- can exhaust available memory and address space because each thread require separate stack space
- more threads = more context switching -> takes time


Basic Thread Management
- every program has at least one thread, started at runtime
- program can launch additional threads
- threads can run concurrently
= when specified entry point function returns, the thread exits (e.g. main())

Launching a Thread
- Threads are started by constructing std::thread objects that specify the task to run
e.g.
Function
void fun();
std::thread mythread(fun);

Function Object
class Fun {
public:
  void operator() () const {

  }
}
Fun  fun;
std::thread mythread(fun);
