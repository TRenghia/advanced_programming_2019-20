#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);

int main() {
  int a{8};
  int* pi{&a};

  char** ppc;

  int* ap[7]; //This is an array of pointers of integers

  void* pv{pi}; //void* is a special type of pointer, indeed any pointer can be tacitly converted to void*
  // *pv; // we cannot dereference void*, because to deference we need to know the type of the pointer.
  // ++pv; // we cannot increment. We don't need the size of the pointers in the array.
  int* pi2{static_cast<int*>(pv)}; //static_cast is a conversion to two different types, if that conversion can be performed at compile time (since static_cast is checked at compile time), so static_cast<int*> takes pv a void*, and converts it in int*.

  pv = ppc;
  pv = ap;
  pv = pi;

  pi = nullptr; //Another special pointer
  ppc = nullptr;
  // ap = nullptr;  // One cannot dereference a null pointer --> segmentation fall  0-->False || rest-->True
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr

  // pi = NULL; // please don't do this

  double* da{new double[5]{}};
  delete[] da;  // dangling pointer, da points to a valid memory location, but its value could be whatever
  da = nullptr;

  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi) //abbreviation for pi != nullptr, since if (pi) means that I'm accessing to pi, and this operation gives true iff pi has a value, so it's not a nullptr.
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  if (!pi)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[]
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0}; //strcmp is a function for string comparison
  if (strcmp(word, word2) == 0)  // For C, one may use word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  int (*fp)(const char*); //I'm defining a pointer to a function that takes (const char*) and returns an integer. N.B.: The parenthesis are crucial, since otherwise the compiler would interpret it as a defn of a function.
  fp = func1;

  fp("hello");

  fp = &func2; //It's the same of doing fp=func2
  fp("world");

  // fp = func3; // error: wrong signature
  auto xx = func3;

  xx("auto");

  decltype(&func3) x = func3; //Decltype allows to define the type of the var x according to the type of the pointer &func3
  x("decltype");

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
