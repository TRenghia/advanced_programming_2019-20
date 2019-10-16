#include <iostream>

int main(int argc, char* argv[]) { //two args for the function main: an integer and an array of pointers to char, i.e. an array of pointers to strings
  for (auto i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  return 0;
}
