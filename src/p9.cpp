#include <iostream>

int main(int argc, char** argv) {

  for (int a = 1; a < 500; a++) {
    for (int b = a+1; b < 500; b++) {
      int c = 1000 - a - b;
      if (a*a + b*b == c*c) {
        std::cout << a << " ";
        std::cout << b << " ";
        std::cout << c << " : ";
        std::cout << a*b*c << std::endl;
      }
    }
  }

  return 0;
}
