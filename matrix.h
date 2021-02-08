#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

double** matrixMultiply(double **matrix1, double **matrix2, int matrixSize);
double** matrixAddition(double **matrix1, double **matrix2, int matrixSize);
double** initializeMatrix(int minValue, int maxValue, int matrixSize);
double** transpose(double **matrix, int matrixSize);
void copyMatrix(double ** source, double ** dest, int size);
void print(double **matrix, int matrixSize);
