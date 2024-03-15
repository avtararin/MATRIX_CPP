#include "s21_matrix_test.h"

TEST(s21_overloadings, Addition) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5;
  m2(0, 1) = 6;
  m2(1, 0) = 7;
  m2(1, 1) = 8;

  S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), 6);
  EXPECT_EQ(result(0, 1), 8);
  EXPECT_EQ(result(1, 0), 10);
  EXPECT_EQ(result(1, 1), 12);
}

TEST(s21_overloadings, AdditionDifferentSizes) {
  S21Matrix m1(2, 2);
  S21Matrix m2(3, 3);

  ASSERT_THROW({ S21Matrix result = m1 + m2; }, std::invalid_argument);
}

TEST(s21_overloadings, AdditionOnesMatrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), 2);
  EXPECT_EQ(result(0, 1), 2);
  EXPECT_EQ(result(1, 0), 2);
  EXPECT_EQ(result(1, 1), 2);
}

TEST(s21_overloadings, AdditionNegativeNumbers) {
  S21Matrix m1(2, 2);
  m1(0, 0) = -1;
  m1(0, 1) = -2;
  m1(1, 0) = -3;
  m1(1, 1) = -4;

  S21Matrix m2(2, 2);
  m2(0, 0) = -1;
  m2(0, 1) = -1;
  m2(1, 0) = -1;
  m2(1, 1) = -1;

  S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), -2);
  EXPECT_EQ(result(0, 1), -3);
  EXPECT_EQ(result(1, 0), -4);
  EXPECT_EQ(result(1, 1), -5);
}

TEST(s21_overloadings, AdditionLargeNumbers) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1000000000;
  m1(0, 1) = 2000000000;
  m1(1, 0) = 3000000000;
  m1(1, 1) = 4000000000;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5000000000;
  m2(0, 1) = 6000000000;
  m2(1, 0) = 7000000000;
  m2(1, 1) = 8000000000;

  S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), 6000000000);
  EXPECT_EQ(result(0, 1), 8000000000);
  EXPECT_EQ(result(1, 0), 10000000000);
  EXPECT_EQ(result(1, 1), 12000000000);
}

// operator -

TEST(s21_overloadings, Subtraction) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5;
  m2(0, 1) = 6;
  m2(1, 0) = 7;
  m2(1, 1) = 8;

  S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), -4);
  EXPECT_EQ(result(0, 1), -4);
  EXPECT_EQ(result(1, 0), -4);
  EXPECT_EQ(result(1, 1), -4);
}

TEST(s21_overloadings, SubtractionDifferentSizes) {
  S21Matrix m1(2, 2);
  S21Matrix m2(3, 3);

  ASSERT_THROW({ S21Matrix result = m1 - m2; }, std::invalid_argument);
}

TEST(s21_overloadings, SubtractionZeroMatrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(0, 1), 0);
  EXPECT_EQ(result(1, 0), 0);
  EXPECT_EQ(result(1, 1), 0);
}

TEST(s21_overloadings, SubtractionNegativeNumbers) {
  S21Matrix m1(2, 2);
  m1(0, 0) = -1;
  m1(0, 1) = -2;
  m1(1, 0) = -3;
  m1(1, 1) = -4;

  S21Matrix m2(2, 2);
  m2(0, 0) = -1;
  m2(0, 1) = -1;
  m2(1, 0) = -1;
  m2(1, 1) = -1;

  S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(0, 1), -1);
  EXPECT_EQ(result(1, 0), -2);
  EXPECT_EQ(result(1, 1), -3);
}

TEST(s21_overloadings, SubtractionLargeNumbers) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1000000000;
  m1(0, 1) = 2000000000;
  m1(1, 0) = 3000000000;
  m1(1, 1) = 4000000000;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5000000000;
  m2(0, 1) = 4000000000;
  m2(1, 0) = 3000000000;
  m2(1, 1) = 2000000000;

  S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), -4000000000);
  EXPECT_EQ(result(0, 1), -2000000000);
  EXPECT_EQ(result(1, 0), 0);
  EXPECT_EQ(result(1, 1), 2000000000);
}

TEST(s21_overloadings, MulNumber_Test1) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(0, 0), 2.0);
}

TEST(s21_overloadings, MulNumber_Test2) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(0, 1), 4.0);
}

TEST(s21_overloadings, MulNumber_Test3) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(1, 0), 6.0);
}

TEST(s21_overloadings, MulNumber_Test4) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(1, 1), 8.0);
}

TEST(s21_overloadings, MulNumber_Test5) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 0.5;
  mat(0, 1) = 2.5;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(0, 0), 1.0);
}

TEST(s21_overloadings, MulMatrix_Test1) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(0, 0), 4.0);
}

TEST(s21_overloadings, MulMatrix_Test2) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(0, 1), 4.0);
}

TEST(s21_overloadings, MulMatrix_Test3) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(1, 0), 10.0);
}

TEST(s21_overloadings, MulMatrix_Test4) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(1, 1), 8.0);
}

TEST(s21_overloadings, MulMatrix_Test5) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 0.0;
  mat1(1, 0) = 0.0;
  mat1(1, 1) = 1.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;

  S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(0, 0), 1.0);
}
TEST(s21_overloadings, MulMatrix_Test_throw) {
  S21Matrix mat1(2, 3);
  S21Matrix mat2(2, 2);
  ASSERT_THROW({ S21Matrix result = mat1 * mat2; }, std::invalid_argument);
}

TEST(AssignmentOperatorTest, SameSizeMatrix) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21Matrix mat2(2, 2);
  mat2 = mat1;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat2(i, j), mat1(i, j));
    }
  }
}

TEST(AssignmentOperatorTest, DifferentSizeMatrix) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21Matrix mat2(3, 2);
  mat2 = mat1;

  EXPECT_EQ(mat2.GetRows(), mat1.GetRows());
  EXPECT_EQ(mat2.GetCols(), mat1.GetCols());
  for (int i = 0; i < mat1.GetRows(); ++i) {
    for (int j = 0; j < mat1.GetCols(); ++j) {
      EXPECT_EQ(mat2(i, j), mat1(i, j));
    }
  }
}

TEST(AssignmentOperatorTest, AssignToItself) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  mat = mat;

  // Проверяем, что значения не изменились
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), i * 2 + j + 1);
    }
  }
}

TEST(AssignmentOperatorTest, AssignToItself2) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  mat = mat;

  // Проверяем, что значения не изменились
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), i * 2 + j + 1);
    }
  }
}

// Тест для сравнения матрицы с самой собой
TEST(EqualOperatorTest, CompareToItself) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  // Проверяем, что матрица равна самой себе
  EXPECT_TRUE(mat == mat);
}

// Тест для сравнения двух равных матриц
TEST(EqualOperatorTest, CompareEqualMatrices) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;

  // Проверяем, что две равные матрицы действительно равны
  EXPECT_TRUE(mat1 == mat2);
}

// Тест для сравнения двух разных матриц
TEST(EqualOperatorTest, CompareDifferentMatrices) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5;
  mat2(0, 1) = 6;
  mat2(1, 0) = 7;
  mat2(1, 1) = 8;

  // Проверяем, что две разные матрицы не равны
  EXPECT_FALSE(mat1 == mat2);
}

// Дополнительные тесты для матриц разного размера

// Тест для сравнения матриц разного размера
TEST(EqualOperatorTest, CompareMatricesOfDifferentSizes) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21Matrix mat2(3, 3);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(0, 2) = 0;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;
  mat2(1, 2) = 0;
  mat2(2, 0) = 0;
  mat2(2, 1) = 0;
  mat2(2, 2) = 0;

  // Проверяем, что матрицы разного размера не равны
  EXPECT_FALSE(mat1 == mat2);
}

// Дополнительные тесты для пустых матриц

// Тест для сравнения двух пустых матриц
TEST(EqualOperatorTest, CompareEmptyMatrices) {
  S21Matrix mat1(0, 0);
  S21Matrix mat2(0, 0);

  // Проверяем, что две пустые матрицы равны
  EXPECT_TRUE(mat1 == mat2);
}

// Тест для сравнения пустой матрицы с непустой
TEST(EqualOperatorTest, CompareEmptyMatrixToNonEmpty) {
  S21Matrix mat1(0, 0);
  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;

  // Проверяем, что пустая матрица не равна непустой
  EXPECT_FALSE(mat1 == mat2);
}

// Дополнительные тесты для матриц с разными значениями элементов

// Тест для сравнения двух матриц с разными значениями элементов
TEST(EqualOperatorTest, CompareMatricesWithDifferentValues) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 3;
  mat2(1, 0) = 5;
  mat2(1, 1) = 7;

  // Проверяем, что матрицы с разными значениями элементов не равны
  EXPECT_FALSE(mat1 == mat2);
}

// Тест для сравнения матриц с одинаковыми значениями элементов, но разным
// порядком
TEST(EqualOperatorTest, CompareMatricesWithSameValuesDifferentOrder) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 4;
  mat2(0, 1) = 3;
  mat2(1, 0) = 2;
  mat2(1, 1) = 1;
  EXPECT_FALSE(mat1 == mat2);
}

// Дополнительные тесты для матриц с отрицательными значениями элементов

// Тест для сравнения двух матриц с отрицательными значениями элементов
TEST(EqualOperatorTest, CompareMatricesWithNegativeValues) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = -1;
  mat1(0, 1) = -2;
  mat1(1, 0) = -3;
  mat1(1, 1) = -4;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = -1;
  mat2(0, 1) = -2;
  mat2(1, 0) = -3;
  mat2(1, 1) = -4;

  // Проверяем, что две матрицы с отрицательными значениями элементов равны
  EXPECT_TRUE(mat1 == mat2);
}

// Тест для добавления матрицы к самой себе
TEST(PlusEqualOperatorTest, AddToItself) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  mat += mat;

  // Проверяем, что значения удвоились
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), (i * 2 + j + 1) * 2);
    }
  }
}

// Тест для добавления нулевой матрицы
TEST(PlusEqualOperatorTest, AddZeroMatrix) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix zeroMat = ZeroMat(2, 2);

  mat += zeroMat;

  // Проверяем, что значения не изменились
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), i * 2 + j + 1);
    }
  }
}

// Тест для добавления к нулевой матрице
TEST(PlusEqualOperatorTest, AddToZeroMatrix) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix zeroMat = ZeroMat(2, 2);

  zeroMat += mat;

  // Проверяем, что значения стали такими же, как в матрице mat
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(zeroMat(i, j), i * 2 + j + 1);
    }
  }
}

TEST(MinusEqualOperatorTest, SubtractFromItself) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  mat -= mat;

  // Проверяем, что значения обнулились
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), 0);
    }
  }
}

// Тест для вычитания нулевой матрицы
TEST(MinusEqualOperatorTest, SubtractZeroMatrix) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix zeroMat = ZeroMat(2, 2);

  mat -= zeroMat;

  // Проверяем, что значения остались неизменными
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), i * 2 + j + 1);
    }
  }
}

// Тест для вычитания из нулевой матрицы
TEST(MinusEqualOperatorTest, SubtractFromZeroMatrix) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix zeroMat = ZeroMat(2, 2);

  zeroMat -= mat;

  // Проверяем, что значения стали противоположными числам в матрице mat
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(zeroMat(i, j), -(i * 2 + j + 1));
    }
  }
}

// Тест для умножения матрицы на саму себя
TEST(MultiplyEqualOperatorTest, MultiplyByItselfMatrix) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix expectedResult(2, 2);
  expectedResult(0, 0) = 7;
  expectedResult(0, 1) = 10;
  expectedResult(1, 0) = 15;
  expectedResult(1, 1) = 22;

  mat *= mat;

  // Проверяем, что результат соответствует ожидаемому
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), expectedResult(i, j));
    }
  }
}

// Тест для умножения на нулевую матрицу
TEST(MultiplyEqualOperatorTest, MultiplyByZeroMatrix) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix zeroMat = ZeroMat(2, 2);

  mat *= zeroMat;

  // Проверяем, что результат равен нулевой матрице
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), 0);
    }
  }
}

// Тест для перегрузки оператора ()
TEST(OverloadingBrackets, OverloadingBrackets_1) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(0, 0), 1);
}

TEST(OverloadingBrackets, OverloadingBrackets_throw) {
  S21Matrix mat(2, 2);
  EXPECT_THROW(mat(0, 3), std::out_of_range);
}

TEST(OverloadingBrackets, OverloadingBrackets_2) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(0, 1), 2);
}

TEST(OverloadingBrackets, OverloadingBrackets_3) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(1, 0), 3);
}

TEST(OverloadingBrackets, OverloadingBrackets_4) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(1, 1), 4);
}

TEST(S21MatrixTest, OperatorMulEqualsScalar) {
  // Создаем матрицу
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  // Умножаем матрицу на скаляр с помощью оператора *=
  matrix *= 2.0;

  // Проверяем, что матрица умножилась на скаляр правильно
  EXPECT_DOUBLE_EQ(matrix(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 8.0);
}