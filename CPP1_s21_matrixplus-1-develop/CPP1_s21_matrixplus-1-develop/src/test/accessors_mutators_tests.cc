#include "s21_matrix_test.h"

TEST(s21_mutator_tests, set_rows_1) {
  S21Matrix m1 = S21Matrix();
  m1.SetRows(5);
  EXPECT_EQ(m1.GetRows(), 5);
}

TEST(s21_mutator_tests, set_rows_2) {
  S21Matrix m1 = S21Matrix();
  m1.SetRows(5);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      if (i > 2) {
        EXPECT_EQ(m1(i, j), 0.0);
      }
    }
  }
}

TEST(s21_mutator_tests, set_rows_3) {
  S21Matrix m1 = S21Matrix();
  m1.SetRows(2);
  EXPECT_EQ(m1.GetRows(), 2);
}

TEST(s21_mutator_tests, set_rows_4) {
  S21Matrix m1 = S21Matrix();
  m1.SetRows(2);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      EXPECT_EQ(m1(i, j), 1.0);
    }
  }
}

TEST(s21_mutator_tests, SetRows_InvalidInput_ThrowsOutOfRange) {
  S21Matrix m1 = S21Matrix();
  EXPECT_THROW(m1.SetRows(0), std::out_of_range);
}

TEST(s21_mutator_tests, set_cols_1) {
  S21Matrix m1 = S21Matrix();
  m1.SetCols(5);
  EXPECT_EQ(m1.GetCols(), 5);
}

TEST(s21_mutator_tests, set_cols_2) {
  S21Matrix m1 = S21Matrix();
  m1.SetCols(5);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      if (j > 2) {
        EXPECT_EQ(m1(i, j), 0.0);
      }
    }
  }
}

TEST(s21_mutator_tests, set_cols_3) {
  S21Matrix m1 = S21Matrix();
  m1.SetCols(2);
  EXPECT_EQ(m1.GetCols(), 2);
}

TEST(s21_mutator_tests, set_cols_4) {
  S21Matrix m1 = S21Matrix();
  m1.SetCols(2);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      EXPECT_EQ(m1(i, j), 1.0);
    }
  }
}

TEST(s21_mutator_tests, SetCols_InvalidInput_ThrowsOutOfRange) {
  S21Matrix m1 = S21Matrix();
  EXPECT_THROW(m1.SetCols(0), std::out_of_range);
}