#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "matrix.h"

/****************************************************************************
 * Creates and returns a pointer to a matrix object with the specified		*
 * number of rows and columns. The "data" field is set to a dynamically 	*
 * created array of ints of size rows * columns.							*
 *																			*
 * If the value of rows or columns is zero or negative, return NULL.		*
 ***************************************************************************/
Matrix *create(int rows, int columns)
{
	Matrix *result = NULL;
	char input[100];
	char *tokens;
	
	if((rows || columns) == 0) {
		return NULL;
	}

	for(int i = 0; i < rows-1; i++) {
		printf("Enter %d integer values for row %d: ", &columns, &i);

		scanf("%[^\n]", input);
		*tokens = strtok (input," ");

		while (*tokens != NULL)
 		{
 			for(int j = 0; j < rows-1; j++) {
    			setValueAt(&result, i, j, *tokens);
    			*tokens = strtok (NULL, " ");
    		}
  		}
	}

	return result;
}

/****************************************************************************
 * Returns the matrix element at (row,column). Return INT_MIN (limits.h)	*
 * if either row and/or column is invalid. Row and column values start at 	*
 * zero. DO NOT modify the input matrix.									*
 ***************************************************************************/
int getValueAt(Matrix *m, int row, int column)
{
	int value = NULL;

	if((row > 0 && row >= *m.rows) && (column > 0 && column >= *m.columns)) {
		value = *m.data(row,column);
		return value;
	}
	
	return INT_MIN;
}

/****************************************************************************
 * If the row and column values are valid, sets the matrix element at 		*
 * (row,column) with the parameter value. Row and column values start at	*
 * zero.																	*
 ***************************************************************************/
void setValueAt(Matrix *m, int row, int column, int value)
{
	if((row > 0 && row >= *m.rows) && (column > 0 && column >= *m.columns)) {
		*m.data(row,column) = value; 
	}
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
	Matrix *result = NULL;
	
	// TO DO

	return result;
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
	Matrix *result = NULL;
	
	// TO DO

	return result;
}

/****************************************************************************
 * Creates the transpose matrix of the input matrix and returns a pointer	*
 * to the result matrix. Use create(), getValueAt(), and setValueAt() 		*
 * functions to implement this function.									*
 * DO NOT modify the input matrix.											*
 ***************************************************************************/
Matrix *transpose(Matrix *m)
{
	Matrix *result = NULL;
	
	// TO DO

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
	Matrix *result = NULL;
	
	// TO DO

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
	Matrix *result = NULL;
	
	// TO DO

	return result;
}



