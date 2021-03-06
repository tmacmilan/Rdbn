/*****************************************************************************************************
 * Naive implementation of matrix functions.
 *
 * Try to allow vectors to be either 1xN or Nx1 matrices.
 */

#include <R.h>
#include <Rmath.h> 
#include "matrix_functions.h"
 
matrix_t *alloc_matrix(int ncols, int nrows) {
  matrix_t *m= (matrix_t*)Calloc(1, matrix_t);
  m[0].matrix= (double*)Calloc(ncols*nrows, double);
  m[0].ncols= ncols;
  m[0].nrows= nrows;
  return(m);
}

/* Use this version for R_alloc function ... R's memory handler will free upon return to R envrioment. */
matrix_t *R_alloc_matrix(int ncols, int nrows) {
  matrix_t *m= (matrix_t*)R_alloc(1, sizeof(matrix_t));
  m[0].matrix= (double*)R_alloc(ncols*nrows, sizeof(double));
  m[0].ncols= ncols;
  m[0].nrows= nrows;
  return(m);
}

void init_matrix(matrix_t *m, double init_value) {
  for(int i=0;i<(m[0].ncols*m[0].nrows);i++)
	  m[0].matrix[i]= init_value;
}

void init_matrix_rnorm(matrix_t *m, double mean, double varience) {
  for(int i=0;i<(m[0].ncols*m[0].nrows);i++)
	  m[0].matrix[i]= rnorm(mean, varience);
}

void free_matrix(matrix_t *m) {
  Free(m[0].matrix);
  Free(m); // (??)
}

/*****************************************************************************************************
 * Some vector functions required for biases.
 */
 
void init_vector(double *vector, int n, double init_value) {
  for(int i=0;i<n;i++)
    vector[i]= init_value;
}

/*
 *  Copies a double *vector into a new vector.  Returns the copy.
 */
double *vector_copy(double *vector, int n) {
  double *v_copy= (double*)Calloc(n, double);
  for(int i=0;i<n;i++)
    v_copy[i]= vector[i];
  return(v_copy);
}
