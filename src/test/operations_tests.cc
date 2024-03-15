#include "s21_matrix_test.h"

TEST(s21_operation_tests, sum_matrix_1) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix();
  m1.SumMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 2);
    }
  }
}

TEST(s21_operation_tests, sum_matrix_incorrect_size_2) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix(5, 5);
  EXPECT_THROW(m1.SumMatrix(m2), std::invalid_argument);
}

TEST(s21_operation_tests, sum_matrix_3) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix();
  double matrix[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  FILL_MATRIX(m1, matrix);
  FILL_MATRIX(m2, matrix)
  double matrix_res[3][3] = {{2, 4, 6}, {2, 4, 6}, {2, 4, 6}};
  m1.SumMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), matrix_res[i][j]);
    }
  }
}

TEST(s21_operation_tests, sub_matrix_1) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix();
  m1.SubMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

TEST(s21_operation_tests, sub_matrix_2) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix();
  double matrix[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  FILL_MATRIX(m1, matrix);
  FILL_MATRIX(m2, matrix);
  m1.SubMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

TEST(s21_operation_tests, sum_matrix_incorrect_size_3) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix(5, 5);
  EXPECT_THROW(m1.SubMatrix(m2), std::invalid_argument);
}

TEST(s21_operation_tests, mul_number_1) {
  S21Matrix m1 = S21Matrix();
  m1.MulNumber(10);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 10);
    }
  }
}

TEST(s21_operation_tests, mul_number_2) {
  S21Matrix m1 = S21Matrix();
  m1.MulNumber(0.5);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0.5);
    }
  }
}

TEST(s21_operation_tests, mul_number_3) {
  S21Matrix m1 = S21Matrix();
  m1.MulNumber(0);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

TEST(s21_operation_tests, mul_matrix_1) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix();
  m1.MulMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 3);
    }
  }
}

TEST(s21_operation_tests, mul_matrix_throw) {
  S21Matrix m1 = S21Matrix();
  S21Matrix m2 = S21Matrix(5, 5);
  EXPECT_THROW(m1.MulMatrix(m2), std::invalid_argument);
}

TEST(s21_operation_tests, mul_matrix_2) {
  S21Matrix m1 = S21Matrix(1, 3);
  S21Matrix m2 = S21Matrix(3, 2);
  m1.MulMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 3);
    }
  }
}

TEST(s21_operation_tests, mul_matrix_3) {
  S21Matrix m1 = S21Matrix(1, 3);
  S21Matrix m2 = S21Matrix(3, 2);
  m1.MulMatrix(m2);
  EXPECT_EQ(m1.GetRows(), 1);
  EXPECT_EQ(m1.GetCols(), 2);
}

TEST(s21_operation_tests, mul_matrix_4) {
  double mnozh1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  double mnozh2[3][2] = {{7, 8}, {9, 1}, {2, 3}};
  double proizv[2][2] = {{31, 19}, {85, 55}};
  S21Matrix m1 = S21Matrix(2, 3);
  S21Matrix m2 = S21Matrix(3, 2);
  FILL_MATRIX(m1, mnozh1);
  FILL_MATRIX(m2, mnozh2);
  m1.MulMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), proizv[i][j]);
    }
  }
}

TEST(s21_operation_tests, mul_matrix_5) {
  double mnozh1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  double mnozh2[3][2] = {{7, 8}, {9, 1}, {2, 3}};
  S21Matrix m1 = S21Matrix(2, 3);
  S21Matrix m2 = S21Matrix(3, 2);
  FILL_MATRIX(m1, mnozh1);
  FILL_MATRIX(m2, mnozh2);
  m1.MulMatrix(m2);
  EXPECT_EQ(2, m1.GetCols());
  EXPECT_EQ(2, m1.GetRows());
}

TEST(s21_operation_tests, transpose_1) {
  S21Matrix origin_matrix = S21Matrix(2, 3);
  S21Matrix transposed_matrix = origin_matrix.Transpose();
  EXPECT_EQ(3, transposed_matrix.GetRows());
  EXPECT_EQ(2, transposed_matrix.GetCols());
}

TEST(s21_operation_tests, transpose_2) {
  S21Matrix origin_matrix = S21Matrix(2, 3);
  S21Matrix transposed_matrix = origin_matrix.Transpose();
  for (int i = 0; i != transposed_matrix.GetRows(); ++i) {
    for (int j = 0; j != transposed_matrix.GetCols(); ++j) {
      EXPECT_EQ(1, transposed_matrix(i, j));
    }
  }
}
TEST(s21_operation_tests, transpose_3) {
  S21Matrix origin_matrix = S21Matrix(2, 3);
  double o_m[2][3] = {{1, 2, 3}, {4, 5, 6}};
  double t_m[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix transposed_matrix = origin_matrix.Transpose();
  for (int i = 0; i != transposed_matrix.GetRows(); ++i) {
    for (int j = 0; j != transposed_matrix.GetCols(); ++j) {
      EXPECT_EQ(t_m[i][j], transposed_matrix(i, j));
    }
  }
}

TEST(s21_operation_tests, transpose_4) {
  S21Matrix origin_matrix = S21Matrix(3, 2);
  double o_m[3][2] = {{5, 4}, {5, 4}, {5, 4}};
  double t_m[2][3] = {{5, 5, 5}, {4, 4, 4}};
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix transposed_matrix = origin_matrix.Transpose();
  for (int i = 0; i != transposed_matrix.GetRows(); ++i) {
    for (int j = 0; j != transposed_matrix.GetCols(); ++j) {
      EXPECT_EQ(t_m[i][j], transposed_matrix(i, j));
    }
  }
}

TEST(s21_operation_tests, determinant_1) {
  S21Matrix origin_matrix = S21Matrix(1, 1);
  EXPECT_EQ(origin_matrix.Determinant(), 1);
}

TEST(s21_operation_tests, determinant_throw) {
  S21Matrix origin_matrix = S21Matrix(1, 2);
  EXPECT_THROW(origin_matrix.Determinant(), std::invalid_argument);
}

TEST(s21_operation_tests, determinant_2) {
  S21Matrix origin_matrix = S21Matrix(2, 2);
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

TEST(s21_operation_tests, determinant_3) {
  S21Matrix origin_matrix = S21Matrix();
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

TEST(s21_operation_tests, determinant_4) {
  S21Matrix origin_matrix = S21Matrix();
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

TEST(s21_operation_tests, determinant_5) {
  S21Matrix origin_matrix = S21Matrix(4, 4);
  double o_m[4][4];
  int cnt = 0;
  for (int i = 0; i != 4; ++i) {
    for (int j = 0; j != 4; ++j) {
      o_m[i][j] = cnt % 10;
      cnt++;
    }
  }
  FILL_MATRIX(origin_matrix, o_m);
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

TEST(s21_operation_tests, determinant_6) {
  S21Matrix origin_matrix = S21Matrix(3, 3);
  double o_m[3][3];
  int cnt = 0;
  for (int i = 0; i != 3; ++i) {
    for (int j = 0; j != 3; ++j) {
      o_m[i][j] = cnt;
      cnt++;
    }
  }
  FILL_MATRIX(origin_matrix, o_m);
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

TEST(s21_operation_tests, calccomplements_1) {
  S21Matrix origin_matrix = S21Matrix(3, 3);
  double o_m[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      o_m[i][j] = i + 1;
    }
  }
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i != 3; ++i) {
    for (int j = 0; j != 3; ++j) {
      EXPECT_EQ(0, calcs(i, j));
    }
  }
}

TEST(s21_operation_tests, calccomplements_throw) {
  S21Matrix origin_matrix = S21Matrix(3, 4);
  EXPECT_THROW(origin_matrix.CalcComplements(), std::invalid_argument);
}

TEST(s21_operation_tests, calccomplements_2) {
  S21Matrix origin_matrix = S21Matrix(2, 2);
  double o_m[2][2], calcs_d[2][2];
  o_m[0][0] = 1;
  o_m[0][1] = 2;
  o_m[1][0] = 1;
  o_m[1][1] = 1;
  calcs_d[0][0] = 1;
  calcs_d[0][1] = -1;
  calcs_d[1][0] = -2;
  calcs_d[1][1] = 1;
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i != 2; ++i) {
    for (int j = 0; j != 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

TEST(s21_operation_tests, calccomplements_3) {
  S21Matrix origin_matrix = S21Matrix(2, 2);
  double o_m[2][2] = {{1, 2}, {1, 1}};
  double calcs_d[2][2] = {{1, -1}, {-2, 1}};
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

TEST(s21_operation_tests, calccomplements_4) {
  S21Matrix origin_matrix = S21Matrix(3, 3);
  double o_m[3][3] = {{1, 2, 3}, {2, -1, 3}, {3, 4, -1}};
  double calcs_d[3][3] = {{-11, 11, 11}, {14, -10, 2}, {9, 3, -5}};
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

TEST(s21_operation_tests, calccomplements_5) {
  S21Matrix origin_matrix = S21Matrix(2, 2);
  double o_m[2][2] = {{1, 2}, {3, 4}};
  double calcs_d[2][2] = {{4, -3}, {-2, 1}};
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

TEST(s21_operation_tests, calccomplements_6) {
  S21Matrix origin_matrix = S21Matrix(3, 3);
  double o_m[3][3] = {{2, -1, 3}, {0, 1, -2}, {5, 4, 1}};
  double calcs_d[3][3] = {{9, -10, -5}, {13, -13, -13}, {-1, 4, 2}};
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

TEST(s21_operation_tests, calccomplements_7) {
  S21Matrix origin_matrix = S21Matrix(2, 2);
  double o_m[2][2] = {{3, 0}, {0, 2}};
  double calcs_d[2][2] = {{2, 0}, {0, 3}};
  FILL_MATRIX(origin_matrix, o_m);
  S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

TEST(inverse_matrix_tests, inverse_matrix_1) {
  S21Matrix matrix = S21Matrix(2, 2);
  double m[2][2] = {{1, 2}, {1, 1}};
  FILL_MATRIX(matrix, m);
  S21Matrix origin = S21Matrix(2, 2);
  double o[2][2] = {{-1, 2}, {1, -1}};
  FILL_MATRIX(origin, o);
  S21Matrix test = matrix.InverseMatrix();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(o[i][j], test(i, j));
    }
  }
}

TEST(inverse_matrix_tests, inverse_matrix_throw_incorrect_size) {
  S21Matrix matrix = S21Matrix(3, 2);
  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}
TEST(inverse_matrix_tests, inverse_matrix_throw_zero_determinant) {
  S21Matrix matrix = S21Matrix(2, 2);
  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

TEST(inverse_matrix_tests, inverse_matrix_2) {
  S21Matrix matrix = S21Matrix(2, 2);
  double m[2][2] = {{1, 2}, {3, 4}};
  FILL_MATRIX(matrix, m);
  S21Matrix origin = S21Matrix(2, 2);
  double o[2][2] = {{-2, 1}, {1.5, -0.5}};
  FILL_MATRIX(origin, o);
  S21Matrix test = matrix.InverseMatrix();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(o[i][j], test(i, j));
    }
  }
}