/* ===========================================================================
COMP-1410 Lab 3
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// matrix_equals(n, m, a, b) returns true exactly when the n x m matrices
//   pointed to by a and b are equal
// requires: n >= 1, m >= 1
//           a and b point to the (0, 0) element of an n x m matrix
bool matrix_equals(const int n, const int m, const int * a, const int * b)
{
  
  const int * max = n*m + a; // The first slot in memory that's outside of the 2D array
  
  while (a < max)
  {
    
    if (*a != *b) // checks if the value at a specific index are equal or not
    {
      return false;
    }
    
    a++; // points to the very next address in memory (+4 bytes)
    b++;

  }
  
  return true;

}

// negate_row(n, m, a, r) negates the entries in row r of matrix a
// requires: n >= 1, m >= 1, 0 <= r < n
//           a points to the (0, 0) element of an n x m matrix
void negate_row(const int n, const int m, int * a, const int r)
{
  
  for (int * p = a + r*m; p < a + (r+1)*m; p++)
  {
    *p = *p * -1;
  }

}

// negate_col(n, m, a, c) negates the entries in column c of matrix a
// requires: n >= 1, m >= 1, 0 <= c < m
//           a points to the (0, 0) element of an n x m matrix
void negate_col(const int n, const int m, int * a, const int c)
{
  
  for (int * p = a + c*m; p < a + (c+1)*m; p++)
  {
    *p *= -1;
  }

}

// matrix_add(n, m, a, b, c) computes the sum of the matrices a and b;
//   the result is stored in the matrix c
// requires: n >= 1, m >= 1
//           a, b, and c point to the (0, 0) element of an n x m matrix
//           the memory c points to can be modified
void matrix_add(const int n, const int m, const int * a, const int * b, int * c)
{
  
  const int * max = n*m + a; // The first slot in memory that's outside of the 2D array
  
  while (a < max)
  {
    
    *c = *a + *b; // sums the value that pointers 'a' and 'b' points to and it's stored as a value that c points to
    a++; // points to the very next address in memory (+4 bytes)
    b++; 
    c++; 

  }

}

int main(void) 
{

// ------------------------- TEST 1 -------------------------------- //  

  int a1[2][3] = {{3, 4, 2}, {5, 9, 3}};
  int b1[2][3] = {{3, 4, 2}, {5, 9, 3}};
  
  int sumChecker1[2][3] = {{6, 8, 4}, {10, 18, 6}};
  int c1[2][3] = {{}};
  
  matrix_add(2, 3, &a1[0][0], &b1[0][0], &c1[0][0]);
  assert(matrix_equals(2, 3, &sumChecker1[0][0], &c1[0][0]));

// ------------------------- TEST 2 -------------------------------- //  
  
  int a2[2][1] = {{7}, {-2}};
  int b2[2][1] = {{2}, {1}};
  
  int sumChecker2[2][1] = {{9}, {-1}};
  int c2[2][1] = {{}};
  
  matrix_add(2, 1, &a2[0][0], &b2[0][0], &c2[0][0]);
  assert(matrix_equals(2, 1, &sumChecker2[0][0], &c2[0][0]));

// ------------------------- TEST 3 -------------------------------- //  
  
  int a3[4][2] = {{7, 4}, {-2, 11}, {6, -3}, {1, 0}};
  int b3[4][2] = {{2, -6}, {1, 0}, {3, 3}, {0, -2}};
  
  int sumChecker3[4][2] = {{9, -2}, {-1, 11}, {9, 0}, {1, -2}};
  int c3[4][2] = {{}};
  
  matrix_add(4, 2, &a3[0][0], &b3[0][0], &c3[0][0]);
  assert(matrix_equals(4, 2, &sumChecker3[0][0], &c3[0][0]));

// ------------------------- TEST 4 -------------------------------- //  
  
  int a4[1][4] = {{7, 4, -3, 1}};
  int b4[1][4] = {{2, -6, 10, 7}};
  
  int sumChecker4[1][4] = {{9, -2, 7, 8}};
  int c4[1][4] = {{}};
  
  matrix_add(1, 4, &a4[0][0], &b4[0][0], &c4[0][0]);
  assert(matrix_equals(1, 4, &sumChecker4[0][0], &c4[0][0]));

// ------------------------- TEST 5 -------------------------------- //  
  
  int a5[1][1] = {{4}};
  int b5[1][1] = {{-2}};
  
  int sumChecker5[1][1] = {{2}};
  int c5[1][1] = {{}};
  
  matrix_add(1, 1, &a5[0][0], &b5[0][0], &c5[0][0]);
  assert(matrix_equals(1, 1, &sumChecker5[0][0], &c5[0][0]));

  printf("All tests passed successfully.\n");

}