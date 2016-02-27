#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/****************************************************************************
 * Matrix Operations
 * CIS 343 - Project 2
 * Professor Nandigam
 *
 * Authors: Morrie Cunningham & Devin Brown
 ***************************************************************************/


/****************************************************************************
 * Creates and returns a pointer to a matrix object with the specified		*
 * number of rows and columns. The "data" field is set to a dynamically 	*
 * created array of ints of size rows * columns.							*
 *																			*
 * If the value of rows or columns is zero or negative, return NULL.		*
 ***************************************************************************/
Matrix *create(int rows, int columns)
{

 	Matrix *matrix = malloc(sizeof *matrix);
  	matrix->rows = rows;
  	matrix->columns = columns;

	if(!(rows && columns) > 0) {
		return NULL;
	}

  matrix->data = (int *) malloc(sizeof(int *) * (columns*rows));

	return matrix;
}

/****************************************************************************
 * Returns the matrix element at (row,column). Return INT_MIN (limits.h)	*
 * if either row and/or column is invalid. Row and column values start at 	*
 * zero. DO NOT modify the input matrix.									*
 ***************************************************************************/
int getValueAt(Matrix *m, int row, int column)
{
	if(row < 0 || column < 0 || row > (m->rows-1) || column > (m->columns-1)) {
    return INT_MIN;
  }

  return m->data[(row*(m->columns)) + column];
}

/****************************************************************************
 * If the row and column values are valid, sets the matrix element at 		*
 * (row,column) with the parameter value. Row and column values start at	*
 * zero.																	*
 ***************************************************************************/
void setValueAt(Matrix *m, int row, int column, int value)
{
  if(row < 0 || column < 0 || row > (m->rows-1) || column > (m->columns-1)) {
    return;
  }
  m->data[(row*(m->columns)) + column] = value;
}

/****************************************************************************
 * If the input matrices are compatible, then performs matrix addition and	*
 * returns a pointer to the result matrix.									*
 * Use create(), getValueAt(), and setValueAt() functions to implement this	*
 * function. If the input matrices are not compatible, return NULL.			*
 * DO NOT modify the input matrices.										*
 ***************************************************************************/
Matrix *add(Matrix *m1, Matrix *m2)
{
	if((m1->rows != m2->rows) && (m1->columns != m2->columns)) {
    return NULL;
  }

  Matrix *m3 = create(m1->rows, m1->columns);

  for(int i = 0; i < m1->rows; i++) {
    for(int j = 0; j < m1->columns; j++) {
      setValueAt(m3,i,j,(getValueAt(m1,i,j) + getValueAt(m2,i,j)));
    }
  }

	return m3;
}

/****************************************************************************
 * If the input matrices are compatible, then performs matrix subtraction	*
 * and returns a pointer to the result matrix.								*
 * Use create(), getValueAt(), and setValueAt() functions to implement this	*
 * function. If the input matrices are not compatible, return NULL.			*
 * DO NOT modify the input matrices.										*
 ***************************************************************************/
Matrix *subtract(Matrix *m1, Matrix *m2)
{
  if((m1->rows != m2->rows) && (m1->columns != m2->columns)) {
    return NULL;
  }

  Matrix *m3 = create(m1->rows, m1->columns);

  for(int i = 0; i < m1->rows; i++) {
    for(int j = 0; j < m1->columns; j++) {
      setValueAt(m3,i,j,(getValueAt(m1,i,j) - getValueAt(m2,i,j)));
    }
  }

	return m3;
}

/****************************************************************************
 * Creates the transpose matrix of the input matrix and returns a pointer	*
 * to the result matrix. Use create(), getValueAt(), and setValueAt() 		*
 * functions to implement this function.									*
 * DO NOT modify the input matrix.											*
 ***************************************************************************/
Matrix *transpose(Matrix *m)
{
  if(m->rows < 0 || m->columns < 0) {
    return NULL;
  }

  Matrix *result = create(m->columns, m->rows);

  for(int i = 0; i < m->columns; i++) {
    for(int j = 0; j < m->rows; j++) {
      setValueAt(result,i,j,getValueAt(m,j,i));
    }
  }

	return result;
}

/****************************************************************************
 * Creates a matrix that is the product of the given scalar value and		*
 * the input matrix and returns a pointer to the result matrix.				*
 * Use create(), getValueAt(), and setValueAt() functions to implement 		*
 * this function.															*
 * DO NOT modify the input matrix.											*
 ***************************************************************************/
Matrix *scalarMultiply(Matrix *m, int scalar)
{
  if(m->rows < 0 || m->columns < 0) {
    return NULL;
  }

  Matrix *result = create(m->rows, m->columns);

  for(int i = 0; i < m->rows; i++) {
    for(int j = 0; j < m->columns; j++) {
      setValueAt(result,i,j,(getValueAt(m,i,j) * scalar));
    }
  }

	return result;
}

/****************************************************************************
 * If the input matrices are compatible, then multiplies the input matrices	*
 * and returns a pointer to the result matrix. Use create(), getValueAt(), 	*
 * and setValueAt() functions to implement this function.					*
 *																			*
 * If the input matrices are not compatible, return NULL.					*
 * DO NOT modify the input matrices.										*
 ***************************************************************************/
Matrix *multiply(Matrix *m1, Matrix *m2)
{
  if(m1->columns != m2->rows) {
    return NULL;
  }

  Matrix *m3 = create(m1->rows, m2->columns);

  int result = 0;
  for(int i = 0; i < m1->rows; i++) {
    for(int j = 0; j < m2->columns; j++) {
      for(int k = 0; k < m1->columns; k++) {
          result = getValueAt(m3,i,j);
          result += (getValueAt(m1,i,k) * getValueAt(m2,k,j));
          setValueAt(m3,i,j,result);
      }
    }
  }

	return m3;
}
