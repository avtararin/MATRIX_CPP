#include "s21_matrix_oop.h"

//Базовый конструктор, инициализирующий матрицу некоторой заранее заданной
//размерностью.
S21Matrix::S21Matrix() : rows_(3), cols_(3) {
  matrix_ = new double *[rows_];
  for (int i = 0; i != rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = 1.0;
    }
  }
}
//Параметризированный конструктор с количеством строк и столбцов.
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  matrix_ = new double *[rows_];
  for (int i = 0; i != rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = 1.0;
    }
  }
}
// Конструктор копирования.
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double *[rows_];
  for (int i = 0; i != rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
// Конструктор переноса.
S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = NULL;
}
// Деструктор
S21Matrix::~S21Matrix() {
  for (int i = 0; i != rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}
// Операции над матрицами

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    result = false;
  } else {
    for (int i = 0; i != rows_; ++i) {
      for (int j = 0; j != cols_; j++) {
        if (matrix_[i][j] != other.matrix_[i][j]) {
          result = false;
        }
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    for (int i = 0; i != rows_; ++i) {
      for (int j = 0; j != cols_; ++j) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    for (int i = 0; i != rows_; ++i) {
      for (int j = 0; j != cols_; ++j) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  S21Matrix result_matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      result_matrix(i, j) = 0;
      for (int k = 0; k < cols_; ++k) {
        result_matrix(i, j) += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  // Освобождаем память текущей матрицы
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  // Копируем данные из результата в текущую матрицу
  rows_ = result_matrix.rows_;
  cols_ = result_matrix.cols_;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = result_matrix(i, j);
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix matrix_transposed = S21Matrix(cols_, rows_);
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols_; ++j) {
      matrix_transposed(j, i) = matrix_[i][j];
    }
  }
  return matrix_transposed;
}

double S21Matrix::Determinant() {
  double determinant = 0;
  if (cols_ != rows_) {
    throw std::invalid_argument("To run determinant matrix should be square!");
  } else if (cols_ == 1) {
    determinant = matrix_[0][0];
  } else if (cols_ == 2) {
    determinant = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    double intermediate_result;
    for (int j = 0; j < cols_; j++) {
      S21Matrix intermediate_matrix = this->Decrease(j);
      intermediate_result = intermediate_matrix.Determinant();
      determinant += matrix_[0][j] * pow(-1, j) * intermediate_result;
    }
  }
  if (std::abs(determinant) < 1e-10) {
    determinant = 0;
  }
  return determinant;
}

S21Matrix S21Matrix::Decrease(int skip_col) {
  S21Matrix decreased_matrix = S21Matrix(cols_ - 1, rows_ - 1);
  int dst_i = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i == 0) {
      continue;
    }
    int dst_j = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == skip_col) {
        continue;
      }
      decreased_matrix(dst_i, dst_j) = matrix_[i][j];
      dst_j++;
    }
    dst_i++;
  }
  return decreased_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix calc_complements = S21Matrix(rows_, cols_);
  if (cols_ != rows_) {
    throw std::invalid_argument("To run determinant matrix should be square!");
  } else {
    double det;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        S21Matrix intermediate_matrix = this->CalcHelper(i, j);
        det = intermediate_matrix.Determinant();
        calc_complements(i, j) = pow(-1, i + j) * det;
      }
    }
  }
  return calc_complements;
}

S21Matrix S21Matrix::CalcHelper(int skip_row, int skip_col) {
  S21Matrix intermediate_matrix = S21Matrix(rows_ - 1, cols_ - 1);
  int dst_i = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i == skip_row) continue;
    int dst_j = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == skip_col) {
        continue;
      }
      intermediate_matrix(dst_i, dst_j) = matrix_[i][j];
      dst_j++;
    }
    dst_i++;
  }
  return intermediate_matrix;
}
S21Matrix S21Matrix::InverseMatrix() {
  if (cols_ != rows_) {
    throw std::invalid_argument("Matrix should be square");
  } else {
    double det = Determinant();
    if (std::abs(det) < EPSILON) {
      throw std::invalid_argument("Determinant should be zero");
    } else {
      S21Matrix intermediate_result = CalcComplements();
      S21Matrix inversed_matrix = intermediate_result.Transpose();
      for (int i = 0; i < inversed_matrix.GetRows(); i++) {
        for (int j = 0; j < inversed_matrix.GetCols(); j++) {
          inversed_matrix(i, j) = inversed_matrix(i, j) / det;
        }
      }
      return inversed_matrix;
    }
  }
}

// Перезгрузка операторов
double &S21Matrix::operator()(int rows, int cols) {
  if (rows >= rows_ || cols >= cols_)
    throw std::out_of_range("Incorrect input, index is out of range");
  return matrix_[rows][cols];
}

double S21Matrix::operator()(int rows, int cols) const {
  if (rows >= rows_ || cols >= cols_)
    throw std::out_of_range("Incorrect input, index is out of range");
  return matrix_[rows][cols];
}

S21Matrix S21Matrix::operator+(S21Matrix &other) {
  if (other.rows_ != rows_ || other.cols_ != cols_)
    throw std::invalid_argument("For sum matrixes should be eq size!");
  else {
    S21Matrix sum = S21Matrix(rows_, cols_);
    for (int i = 0; i != rows_; ++i) {
      for (int j = 0; j != cols_; ++j) {
        sum(i, j) = matrix_[i][j] + other(i, j);
      }
    }
    return sum;
  }
}

S21Matrix S21Matrix::operator-(S21Matrix &other) {
  if (other.rows_ != rows_ || other.cols_ != cols_)
    throw std::invalid_argument("For sum matrixes should be eq size!");
  else {
    S21Matrix sum = S21Matrix(rows_, cols_);
    for (int i = 0; i != rows_; ++i) {
      for (int j = 0; j != cols_; ++j) {
        sum(i, j) = matrix_[i][j] - other(i, j);
      }
    }
    return sum;
  }
}

S21Matrix S21Matrix::operator*(S21Matrix &other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "Number of columns in the first matrix should be equal to the number "
        "of rows in the second matrix!");

  S21Matrix result = S21Matrix(rows_, other.cols_);
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols_; ++j) {
      result(i, j) = 0;
    }
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result(i, j) += matrix_[i][k] * other(k, j);
      }
    }
  }

  return result;
}

S21Matrix S21Matrix::operator*(double scalar) {
  S21Matrix result = S21Matrix(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = matrix_[i][j] * scalar;
    }
  }

  return result;
}

void S21Matrix::operator=(const S21Matrix &other) {
  if (this == &other) return;  // Self-assignment guard

  // Clear existing data
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  // Copy size
  rows_ = other.rows_;
  cols_ = other.cols_;

  // Allocate new memory
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

bool S21Matrix::operator==(const S21Matrix &other) { return (EqMatrix(other)); }

void S21Matrix::operator+=(const S21Matrix &other) { this->SumMatrix(other); }
void S21Matrix::operator-=(const S21Matrix &other) { this->SubMatrix(other); }
void S21Matrix::operator*=(const S21Matrix &other) { this->MulMatrix(other); }
void S21Matrix::operator*=(const double num) { this->MulNumber(num); }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 1) {
    throw std::out_of_range(
        "Incorrect input, the number of rows must be greater than or equal to "
        "1 ");
  } else if (new_rows > rows_) {
    int old_rows = rows_;
    rows_ = new_rows;
    double **matrix_tmp = new double *[rows_];
    for (int i = 0; i != rows_; ++i) {
      if (i < old_rows) {
        matrix_tmp[i] = matrix_[i];
      } else {
        matrix_tmp[i] = new double[cols_];
        for (int j = 0; j < cols_; ++j) {
          matrix_tmp[i][j] = 0.0;
        }
      }
    }
    delete[] matrix_;
    matrix_ = matrix_tmp;
  } else if (new_rows < rows_) {
    for (int i = new_rows; i != rows_; ++i) {
      delete[] matrix_[i];
    }
    rows_ = new_rows;
  }
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 1) {
    throw std::out_of_range(
        "Incorrect input, the number of cols must be greater than or equal to "
        "1");
  }
  double **new_matrix = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    new_matrix[i] = new double[new_cols];
    for (int j = 0; j < std::min(cols_, new_cols); ++j) {
      new_matrix[i][j] = matrix_[i][j];
    }
    for (int j = cols_; j < new_cols; ++j) {
      new_matrix[i][j] = 0.0;
    }
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = new_matrix;
  cols_ = new_cols;
}

S21Matrix ZeroMat(int rows, int cols) {
  S21Matrix mat(rows, cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      mat(i, j) = 0;
    }
  }
  return mat;
}
