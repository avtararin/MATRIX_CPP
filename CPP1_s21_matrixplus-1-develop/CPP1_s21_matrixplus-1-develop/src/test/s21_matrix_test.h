#include <gtest/gtest.h>

#include <stdexcept>

#include "../s21_matrix_oop.h"

#define FILL_MATRIX(m, arr_values)          \
  for (int i = 0; i < m.GetRows(); i++) {   \
    for (int j = 0; j < m.GetCols(); j++) { \
      m(i, j) = arr_values[i][j];           \
    }                                       \
  }
