#include "s21_matrix_test.h"

TEST(s21_constructors_tests, constructor_1) {
  S21Matrix m1 = S21Matrix();
  for (int i = 0; i != 3; i++) {
    for (int j = 0; j != 3; j++) {
      EXPECT_EQ(m1(i, j), 1.0);
    }
  }
}

TEST(s21_constructors_tests, constructor_2) {
  S21Matrix m1 = S21Matrix();
  EXPECT_EQ(m1.GetCols(), 3);
  EXPECT_EQ(m1.GetRows(), 3);
}

TEST(s21_constructors_tests, constructor_3) {
  S21Matrix m1 = S21Matrix(3, 3);
  EXPECT_EQ(m1.GetCols(), 3);
  EXPECT_EQ(m1.GetRows(), 3);
}

TEST(s21_constructors_tests, constructor_4) {
  S21Matrix m1 = S21Matrix(3, 3);
  EXPECT_EQ(m1.GetCols(), 3);
  EXPECT_EQ(m1.GetRows(), 3);
}

TEST(S21MatrixTest, CopyConstructor) {
  // Создаем исходную матрицу
  S21Matrix original(3, 3);
  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(0, 2) = 3.0;
  original(1, 0) = 4.0;
  original(1, 1) = 5.0;
  original(1, 2) = 6.0;
  original(2, 0) = 7.0;
  original(2, 1) = 8.0;
  original(2, 2) = 9.0;

  // Создаем копию исходной матрицы с помощью конструктора копирования
  S21Matrix copy(original);

  // Проверяем, что размеры копии совпадают с исходной матрицей
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());

  // Проверяем, что значения копии совпадают с исходной матрицей
  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

// Дополнительные тесты

// Проверка копирования пустой матрицы
TEST(S21MatrixTest, CopyConstructorEmptyMatrix) {
  S21Matrix original;
  S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
}

// Проверка копирования матрицы с одним элементом
TEST(S21MatrixTest, CopyConstructorSingleElement) {
  S21Matrix original(1, 1);
  original(0, 0) = 42.0;
  S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  EXPECT_DOUBLE_EQ(copy(0, 0), original(0, 0));
}

// Проверка копирования матрицы с отрицательными значениями
TEST(S21MatrixTest, CopyConstructorNegativeValues) {
  S21Matrix original(2, 2);
  original(0, 0) = -1.0;
  original(0, 1) = -2.0;
  original(1, 0) = -3.0;
  original(1, 1) = -4.0;
  S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

// Проверка копирования большой матрицы
TEST(S21MatrixTest, CopyConstructorLargeMatrix) {
  const int rows = 100;
  const int cols = 100;
  S21Matrix original(rows, cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      original(i, j) = i * cols + j;
    }
  }
  S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

// Проверка копирования матрицы с разными размерами
TEST(S21MatrixTest, CopyConstructorDifferentSizes) {
  S21Matrix original(2, 3);
  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(0, 2) = 3.0;
  original(1, 0) = 4.0;
  original(1, 1) = 5.0;
  original(1, 2) = 6.0;
  S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

// Проверка копирования матрицы с нулевыми размерами
TEST(S21MatrixTest, CopyConstructorZeroSize) {
  S21Matrix original(0, 0);
  S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
}
