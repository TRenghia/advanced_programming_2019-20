#include <iostream>
#include <string>

struct S {
  int a;
  double b;
  std::string s;  // default ctor of string set s to empty string
};

int main() {
  S s1;  // calls default constructor, built-in type aren't initialized, so if we run this program, we get random values, except for the string, since the default ctor set s to empty string

  S s2{1, 2.3, "alberto"};  // if there are no custom ctors I can
                            // directly initialize the members. Note
                            // that I need access (i.e. they must be
                            // public)
  // it is called aggregate initialization (see
  // https://en.cppreference.com/w/cpp/language/aggregate_initialization). Different for each version of c++

  S s3{};  // calls {} on each member: S s3 { {}, {}, {} }; in this case we are constructing these objects using the default ctor, but the curly braces initialize the built-in type to 0, or empty string. It is more reasonable than the default random value, however it is less efficient 

  std::cout << s1.a << "--" << s1.b << "--" << s1.s << "\n";
  std::cout << s2.a << "--" << s2.b << "--" << s2.s << "\n";
  std::cout << s3.a << "--" << s3.b << "--" << s3.s << "\n";

  return 0;
}
