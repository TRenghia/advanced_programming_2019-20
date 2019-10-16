#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc{&a};//const int* means that the pointer pc to a cannot be change in any way. Indeed if we try to compile the command *pc = 7; we get a compile error
  a = 15;  // I can obviously change a

  int* const cp{&a};//In this case, I can change the value of cp but not its adress
  a = b;
  *cp = 33;
  // cp = &b;   // error

  const int* const cpc{&a}; //Both the value and the adress of cpc cannot be change

  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}

template <typename T>
void print_sentinel(const T* a, const std::size_t N) {
  const T* const endarray{a + N};
  for (; a != endarray; ++a)//This cycle returns a pointer to the last element of the array +1, indeed it goes on until a is equal to the end of the array 
    std::cout << *a << std::endl;
}
