#include <cmath>
#include <iostream>

#if __cplusplus > 201103L //This string verifies if our system has c++14 or higher installed. Starting from c++14, we can use init with the command auto
                          //201103L is the official string for c++11

//auto keyword allows the compiler to deduce the type of variable, indeed c++ always needs to know the type of variable because it is extremely rigid
template <class T>
auto init(const std::size_t l) { //const is something that shouldn't change during the code, and we may check it through this command, therefore const helps the compiler to optimize
  return new T[l]{};
}

#else

template <class T>
T* init(const std::size_t l) {
  return new T[l]{};
}

#endif

template <typename T> //Function to reveal the type of variable. Notice that this function is not defined, so when we call it, it will give a compile error which in turn will reveal the type of the original varibale.
void debug(T)

//When declaring a variable type with auto, the syntax is with =, otherwise use {}

int main() {
  auto b = true;          // a bool
  auto ch = 'x';          // a char
  auto i = 123;           // an int (in this case 123 is an integer, therefore auto is deducing the type in the most natural way, could also be an unisigned int or long int, etc, but this must be prescribed)
  auto d = 1.2;           // a double
  auto z = std::sqrt(d);  // z has the type of whatever sqrt(d) returns
  auto ui = 0u;           // unsigned int
  auto llui = 0llu;       // long long unsigned int

  for (auto i = 0; i < 7; ++i)
    std::cout << i << std::endl;

  auto pb = &b;  // pb is a pointer to a boolean since in the RHS we have &b and b was a boolean

  auto ps = init<double>(11); // To recover the type of variable, we may ask to the compiler, forcing a compile error through debug(), which is an undefined function.
  debug(pb);
  debug(ps);
  //ABOUT INIT: 
  delete[] ps;
  return 0;
}
