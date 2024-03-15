#include "s21_matrix_oop.h"

// Определение перегруженного оператора <<
std::ostream &operator<<(std::ostream &out, const S21Matrix &matrix) {
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      out << matrix(i, j) << " ";
    }
    out << std::endl;
  }
  return out;
}

S21Matrix EmptyMat() { return S21Matrix(0, 0); }