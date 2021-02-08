#include "matrix.h"

//Multiply two square matrices of the same size.
	double** matrixMultiply(double **matrix1, double **matrix2, int matrixSize){

//Allocates memory for a matrix of doubles.
	int i, j, k;
	double **matrixOut = (double **)malloc(matrixSize * sizeof(double*));
	for (i = 0; i < matrixSize; i++){
		matrixOut[i] = (double *) malloc(matrixSize * sizeof(double));
	}

	double result = 0;
	//Fill each cell of the matrix output.
	for(i = 0 ; i < matrixSize ; i++){
		for (j = 0; j < matrixSize ; j++){
			//Multiply each row of matrix 1 with each column of matrix 2.
			for(k = 0; k < matrixSize; k++){
				result += matrix1[i][k] * matrix2[k][j];
			}

			matrixOut[i][j] = result;
			result = 0; //Reset;
		}
	}

	return matrixOut;
}

//Add two square matrices of the same size.
	double** matrixAddition(double **matrix1, double **matrix2, int matrixSize){
		//Allocates memory for a matrix of doubles.
		int i, j;
		double **matrixOut = (double **)malloc(matrixSize * sizeof(double*));
		for (i = 0; i < matrixSize; i++){
			matrixOut[i] = (double *) malloc(matrixSize * sizeof(double));
		}

//Fill each cell of the matrix output.
	for(i = 0 ; i < matrixSize ; i++){
		for (j = 0; j < matrixSize ; j++){
			matrixOut[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	return matrixOut;
}

	//Return the transpose of a square matrix.
	double** transpose(double **matrix, int matrixSize){

	//Allocates memory for a matrix of doubles.
	int i, j;
	double **matrixOut = (double **)malloc(matrixSize * sizeof(double*));
	for (i = 0; i < matrixSize; i++){
		matrixOut[i] = (double *) malloc(matrixSize * sizeof(double));
	}

	//Transpose the matrix.
	for(i = 0 ; i < matrixSize ; i++){
		for (j = 0; j < matrixSize ; j++){
			matrixOut[i][j] = matrix[j][i];
		}
	}

	return matrixOut;
}

	//Create a real positive-definite matrix.
	double** initializeMatrix(int minValue, int maxValue, int matrixSize){

    //Allocates memory for a matrices of doubles.
	int i, j;
	double **matrix = (double **)malloc(matrixSize * sizeof(double*));
	double **identity = (double **)malloc(matrixSize * sizeof(double*));
	for (i = 0; i < matrixSize; i++){
		matrix[i] = (double *) malloc(matrixSize * sizeof(double));
		identity[i] = (double *) malloc(matrixSize * sizeof(double));
	}

	//Creates an upper-triangular matrix of random numbers between minValue and maxValue.
	//Creates an identity matrix multiplied by maxValue.
	double random;
	for(i = 0 ; i < matrixSize ; i++){

		identity[i][i] = maxValue * matrixSize;

		for(j = 0 ; j < matrixSize ; j++){

			random = (maxValue - minValue) *
				((double)rand() / (double)RAND_MAX) + minValue;
			if(random == 0.0){
				random = 1.0; //Avoid division by 0.
			}
			matrix[i][j] = random;
		}
	}

	//Transform to positive-definite.
	double **transposed = transpose(matrix, matrixSize);
	matrix = matrixAddition(matrix, transposed, matrixSize);
	matrix = matrixAddition(matrix, identity, matrixSize);

	return matrix;
}

void print(double **matrix, int matrixSize){
    int i, j;
    for (i = 0; i < matrixSize; i++) {
            for (j = 0; j < matrixSize; j++) {
                    printf("%.2f\t", matrix[i][j]);
            }
            printf("\n");
    }
    printf("\n");
}
