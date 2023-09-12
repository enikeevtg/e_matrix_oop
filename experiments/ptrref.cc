//
// Example: function signature for pointer and reference
// compile with g++ -O1 -g0 -masm=intel -S ptrref.cc
//

int g;

void foo(int* x) { g = *x; }

void bar(int& x) { g = x; }
