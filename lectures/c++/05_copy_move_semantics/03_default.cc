#include <iostream>

struct X {
  int a = 5;  // in-class initialization, now 5 is the defaul value of a, so the call X x1 will return 5 as a first value
  double b;
  char c = 'a';
  X() = default;  // in-class initializers are used by the constructors, we are asking the compiler to generate a default constructor. It makes the code more readable. This is just what the compiler does implicitly.
};

struct Y {
  int a = 77;
  double b; //unitialized --> random value only for built-in type, null var for custom types
  char c = 'a';
  Y() : a{5} {}  // what it is written here wins the in-class initialization, so the default ctor of Y will set the default value of a to 5, and not 77. 
  Y(const Y&) = delete;
};

int main() {
  X x1;    // compiler-generated default ctor
  X x2{};  // compiler-generated default ctor calls {} on uninitialized vars
  std::cout << x1.a << "--" << x1.b << "--" << x1.c << "\n";
  std::cout << x2.a << "--" << x2.b << "--" << x2.c << "\n\n";

  Y y1;    // default ctor
  Y y2{};  // default ctor
  std::cout << y1.a << "--" << y1.b << "--" << y1.c << "\n";
  std::cout << y2.a << "--" << y2.b << "--" << y2.c << "\n";

  // Y y3{y2}; // error: call to a deleted function

  return 0;
}
