#include <iomanip>
#include <iostream>

void print_ma(int m[][5], int dim1);  // ugly and not flexible
// void print_ma(int m[][], int dim1, int dim2); // error second
// dimension must be
// knwon at compile time

void print_ma(int* p, int row, int col);  // the only possible solution

int main() {
  int ma[6][5];  // matrix: 6 rows, 5 columns each. Not flexible. Real shit.

  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 5; ++j)
      ma[i][j] = 10 * i + j;

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << std::setw(3) << ma[i][j];
    std::cout << std::endl;
  }

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << &ma[i][j] << " "; //Print the adresses of the elements of the matrix, it turns out that a static matrix is stored as a long array
    std::cout << std::endl;
  }

  // int *pma = ma; 		// error
  // int *pma[5] = ma;		// error
  int* p = &ma[0][0];

  // print_ma(ma, 6, 5); 	// error
  print_ma(p, 6, 5);

  int* d_ma = new int[6 * 5]{}; // (DEF_MAT) It's the same defn as above, but it stores the matrix in a long array and it allocates the matrix it in the heap, which is better since in general the stack is small, but the matrix is big (in term of memory)

  std::cout << std::endl;

  print_ma(d_ma, 6, 5);
  delete[] d_ma;

  return 0;
}

void print_ma(int* p, int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j)
      std::cout << std::setw(2) << p[i * col + j] << " "; //In the memory the elements of the matrix are stored in one line, so to access the ith element of the jth columns, we have to access to the i*j th element. This is why we need the number of columns to explore a matrix. Indeed, to define matrices, we actually define a long array as in (DEF_MAT)
    std::cout << std::endl;
  }
}
