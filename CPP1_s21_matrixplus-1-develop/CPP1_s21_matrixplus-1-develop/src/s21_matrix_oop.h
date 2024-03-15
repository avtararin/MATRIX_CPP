// In this file is defined signatures of class S21Matrix.
#include <math.h>

#include <cstring>
#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>

const double EPSILON = std::numeric_limits<double>::epsilon();

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  //Конуструкторы
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  // Деструктор
  ~S21Matrix();

  // Getters and setters
  int GetRows() const { return rows_; }
  int GetCols() const { return cols_; }
  void SetRows(int new_rows);
  void SetCols(int new_cols);
  //Операции над матрицами
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix Decrease(int skip_col);
  S21Matrix CalcComplements();
  S21Matrix CalcHelper(int skip_row, int skip_col);
  S21Matrix InverseMatrix();
  // Перегрузка операторов
  double& operator()(int rows, int cols);
  double operator()(int rows, int cols) const;
  S21Matrix operator+(S21Matrix& other);
  S21Matrix operator-(S21Matrix& other);
  S21Matrix operator*(S21Matrix& other);
  S21Matrix operator*(const double num);
  void operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double num);
};

std::ostream& operator<<(std::ostream& out, const S21Matrix& matrix);
S21Matrix ZeroMat(int rows, int cols);
S21Matrix EmptyMat();