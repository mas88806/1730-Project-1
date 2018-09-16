#ifndef MATRIX_H
#define MATRIX_H
#include <initializer_list>

using std::initializer_list;

typedef unsigned int uint;
typedef initializer_list<initializer_list<double>> i_list;

class Matrix {

  uint r;
  uint c;

 public:

  Matrix(uint rows, uint cols);
  Matrix(const i_list & list);
  Matrix(const Matrix & m);
  ~Matrix();

  Matrix add(double s) const;
  Matrix add(const Matrix & m) const;

  Matrix subtract(double s) const;
  Matrix subtract(const Matrix & m) const;

  Matrix multiply(double s) const;
  Matrix multiply(const Matrix & m) const;

  Matrix divide(double s) const;
  Matrix t() const;

  const uint numRows() const;
  const uint numCols() const;

  double & at(uint row, uint col);
  const double & at (uint row, uint col) const;

  Matrix operator+ (const Matrix & m) const;
  Matrix operator+ (double s) const;

  Matrix operator- (const Matrix & m) const;
  Matrix operator- (double s) const;

  Matrix operator* (const Matrix & m) const;
  Matrix operator* (double s) const;

  Matrix operator/ (double s) const;
};

#endif
