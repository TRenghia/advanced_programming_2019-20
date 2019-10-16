#include <array>
#include <iostream>
// std arrays are static arrays, that live in the stacks, and they can be used to copy an array elementwise. This can't be done with static arrays.
// template <class T, std::size_t N>
// struct array;

int main() {
  std::array<int, 4> a{1, 2, 3, 4};
  std::array<int, 4> b{a};  // I can copy element-wise from another std::array
                            // this is not possible with plain built-in arrays
  b = a;
  for (auto x : a) //x is the name of each element of a, for knows the size because it was specified above, this was not true for built-in arrays.
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  a[0] = 0;  // same subscripting operator without bound checking

  for (const auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (const auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto& x : a) //In this case, x is a reference to each element of a, so multiplying x by 10, modifies each element of a, multiplying it by 10.
    x *= 10;

  for (auto i = 0u; i < a.size(); ++i)
    std::cout << "a[" << i << "] = " << a[i] << std::endl;

  b.at(90);  // bound checking at run-time, this is a special feature of std arrays (that built-in arrays haven't). Std arrays in general are as fast as built-in ones but they have this nice features.

  return 0;
}
