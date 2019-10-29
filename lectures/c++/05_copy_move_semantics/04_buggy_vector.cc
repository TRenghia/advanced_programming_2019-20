#include <iostream>

template <typename T>
class Vector { //costum class
  T* elem;
  std::size_t _size;

public: //costum constructor
  explicit Vector(const std::size_t length) // Without the explicit command, the compiler implicitly tries to build a vector from any input. With explicit the compiler is allowed to perform a conversion from size_t type to type T only. For example the command print(3), with explicit, gives error, without it, the compiler will interpret the input and it will build a vector with 3 elements initilized by default (in this case 0). Better to use explicit.
    : elem{new T[length]{}}, _size{length} {} //This will be an array of lenght "lenght" and elements of type T, with initilized values to null

  ~Vector() { delete[] elem; } //Calling the destructor to avoid memory leaks

  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i) { return elem[i]; }

  std::size_t size() const { return _size; }

  // range-for, to use a Vector object in a for cycle, we have to write to functions: begin, which returns a pointer to the first element and end, which returns a pointer to the "length"+1-th element
  const T* begin() const { return elem; }
  T* begin() { return elem; }

  const T* end() const { return elem + size(); }
  T* end() { return elem + size(); }
};

int main() {
  Vector<int> v1{3};
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  std::cout << "v1: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

//The for cycle is analogous to the follwing syntax
// auto it=v1.begin();
// auto stop.end();
// for (;it!=stop; ++it){body}
  
  Vector<int> v2{v1};  // default copy constructor, the program compiles but the copy is not element-wise, indeed the two elements are entagled, as happened with copy ctor for stdvector. Any modification to any of those two affects the other. The compiler gives also an error, because after the copy ctor, v2 and v1 points to the same region of memory so the destructor frees up memory when the variables go out of scope, hence when v2 goes out of scope, delete frees up the memory region pointed by v2, and then it does the same thing for v1. But that region has already been cleaned, leading to an error "double free detected in tcache 2". v2 is called a CHEAP copy of v1,

  std::cout << "v2 after default copy ctor: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v1[0] = 99;

  std::cout << "v2 after v1 has been changed: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v2[1] = -999;

  std::cout << "v1 after v2 has been changed: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
