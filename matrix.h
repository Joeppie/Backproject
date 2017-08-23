#ifndef BACKPROJECT_MATRIX_H
#define BACKPROJECT_MATRIX_H


/**
 * represents a 2d matrix of double values using a std::vector<std::vector<double>>
 */
using matrix = std::vector<std::vector<double>>;
/**
 * represents a vector- or list- of double  values using a std::vector<double>
 */
using vector = std::vector<double>;

/**
 * Multiplies two matrices to create a new one with the result of the mulitplication.
 * @param a right-hand side matrix
 * @param b left-hand size matrix
 */
matrix multiply(const matrix &a, const matrix &b);

/**
 * Pretty-Prints the matrix, but only if verbose_back_project has been #defined to a nonzero value.
 * @param matrix the matrix to print to std::cout.
 * @param description the description to be printed out above the matrix.
 */
void printMatrix(const matrix &matrix,const std::string &description);

/**
 * swaps the sign on every value inside the matrix; e.g. a column with 1 becomes -1 and vice versa
 * @param a
 */
matrix negate(const matrix &a);

/**
 * Transposes a matrix
 * @param original the matrix to transpose
 * @return a transposed copy of the matrix
 */
matrix transpose(const matrix &original);

/**
 * 'Concatenates' a matrix b, to matrix A; this fills result matrix C with all rows and columns of A, and each row ends with the columns of B.
 * @param a original matrix
 * @param b matrix to concatenate with, number of rows must match A.
 */
matrix concatenate(const matrix &a, const matrix &b);



#endif //BACKPROJECT_MATRIX_H
