#pragma once // NOLINT

#include <vector>
#include <istream>

#define EPS 1e-7

namespace prep {
class Matrix {
 public:
  explicit Matrix(size_t rows = 0, size_t cols = 0);
  explicit Matrix(std::istream& is);
  Matrix(const Matrix& rhs) = default;
  Matrix& operator=(const Matrix& rhs) = default;
  ~Matrix() = default;

  size_t getRows() const;
  size_t getCols() const;

  double operator()(size_t i, size_t j) const;
  double& operator()(size_t i, size_t j);

  bool operator==(const Matrix& rhs) const;
  bool operator!=(const Matrix& rhs) const;

  Matrix operator+(const Matrix& rhs) const;
  Matrix operator-(const Matrix& rhs) const;
  Matrix operator*(const Matrix& rhs) const;

  Matrix operator*(double val) const;

  friend Matrix operator*(double val, const Matrix& matrix);
  friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

  Matrix transp() const;
  double det() const;
  Matrix adj() const;
  Matrix inv() const;

 private:
  Matrix create_minor(const size_t row, const size_t col) const;
  bool check_null_row(const size_t row) const;
  bool check_null_col(const size_t col) const;
  void plus_col(const size_t target, const size_t col);
  bool check_null_diag_el(const size_t pos);
  bool step_view();

  size_t m_rows{};
  size_t m_cols{};
  std::vector<std::vector<double>> m_data{};
};

Matrix operator*(double val, const Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

}  // namespace prep