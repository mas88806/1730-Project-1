#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;

/*
A Basic constructor of the Matrix class.
@param uint rows, Number of rows in the matrix.
@param uint cols, Number of columns in the matrix.
*/

Matrix::Matrix(uint rows, uint cols){
  double **matrix = new double*[rows];
  r = rows;
  c = cols;
  for(uint i = 0; i < rows; ++i)
    matrix[i] = new double[cols];
}

//Matrix::Matrix(const i_list & list){

//}

Matrix::Matrix(const Matrix & m){
  r = m.numRows();
  c = m.numCols();
  Matrix m2 = Matrix(m.numRows(),m.numCols());
  for(uint i = 0; i < m.numRows(); i++)
    for(uint j = 0; j < m.numCols(); j++)
      m2.at(i,j) = m.at(i,j);
}

Matrix::~Matrix(){
 
}

Matrix Matrix::add(double s) const{
  Matrix m(this->numRows(),this->numCols());
  for(uint i = 0; i < m.numRows(); ++i){
    for(uint j = 0; j < m.numCols(); ++j){
      double x = this->at(i,j);
      x += s;
      m.at(i,j) = x;
    }
      }
  return m;
  }//add (scaler)

Matrix Matrix::operator+(const Matrix & m) const{
 return this->add(m);
}//+ overload (matrix)

Matrix Matrix::operator+(double s) const{
 return this->add(s);
}//overload (scaler)

Matrix Matrix::add(const Matrix & m) const{
  uint x = m.numRows();
  uint y = m.numCols();
  Matrix matrix(x,y);
  for(uint i = 0; i < x; ++i){
    for(uint j = 0; j < y; ++j){
      matrix.at(i,j) = (m.at(i,j)+this->at(i,j));
    }
  }//for loops
  return matrix;
}//add (matrix)

Matrix Matrix::subtract(double s) const{
  Matrix m(this->numRows(), this->numCols());
  for(uint i = 0; i < m.numRows(); ++i){
    for(uint j = 0; j < m.numCols(); ++j){
      double x = this->at(i,j);
      x -= s;
      m.at(i,j) = x;
    }
  }
  return m;
}//subtract

Matrix Matrix::subtract(const Matrix & m) const{
  Matrix matrix(m.numRows(),m.numCols());
  for(uint i = 0; i < m.numRows(); ++i){
    for(uint j = 0; j < m.numCols(); ++j){
      matrix.at(i,j) = (this->at(i,j)-m.at(i,j));
    }
  }//for loops
  return matrix;
}//subtract (matrix)

Matrix Matrix::operator-(const Matrix & m) const{
 return this->subtract(m);
}//- overload (matrix)

Matrix Matrix::operator-(double s) const{
 return this->subtract(s);
}//- overload (scaler)

Matrix Matrix::multiply(double s) const{
  Matrix m(this->numRows(), this->numCols());
  for (uint i = 0; i < m.numRows(); ++i){
    for(uint j = 0; j < m.numCols(); ++j){
      double x = this->at(i,j);
      x *= s;
      m.at(i,j) = x;
    }
  }//for loops
  return m;
}//multiply

Matrix Matrix::multiply(const Matrix & m) const{
  Matrix matrix(this->numRows(), m.numCols());
  for(uint i = 0; i < this->numRows(); ++i){
    for(uint j = 0; j < m.numCols(); ++j){
      for(uint k = 0; k < m.numRows(); ++k){
	matrix.at(i,j) += (this->at(i,k) * m.at(k,j));
      }
    }
  }//for loops
    return matrix;
}//multiply (matrix)

Matrix Matrix::operator*(const Matrix & m) const{
 return this->multiply(m);
}//* overload (matrix)

Matrix Matrix::operator*(double s) const{
 return this->multiply(s);
}//* overload (scaler)

Matrix Matrix::divide(double s) const{
  Matrix m(this->numRows(), this->numCols());
  for (uint i = 0; i < m.numRows(); ++i){
    for (uint j = 0; j < m.numCols(); ++j){
      double x = this->at(i,j);
      x /= s;
      m.at(i,j) = x;
    }
  }//for loops
  return m;
}//divide

Matrix Matrix::operator/(double s) const{
  return this->divide(s);
}// / overload

Matrix Matrix::t() const{
  Matrix m(this->numRows(),this->numCols());
  for(uint i = 0; i < this->numRows(); ++i){
    for(uint j = 0; j < this->numCols(); ++j){
      m.at(i,j)=this->at(i,j);
    }
  }//for loops
  return m;
}//transpose

//double & Matrix::at(uint row, uint col){
  //  Matrix values(this);
  // return values[row][col]; 
//at (non-const) cant figure this out!

/*
The next two functions are simple getters.
 */
const uint Matrix::numRows() const{
  return this->r;
}//numRows

const uint Matrix::numCols() const{
  return this->c;
}//numCols
