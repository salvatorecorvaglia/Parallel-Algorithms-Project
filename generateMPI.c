#include "matrix.h"

int main(int argc, char **argv)
{
    // generate seed
    srand(time(NULL));
    if (argc != 2)
    {
       printf("You did not feed me arguments... \n");
       printf("Usage: %s [matrix size] \n", argv[0]);
       return 1;
    }

    int matrixSize = atoi(argv[1]);

    // Generate random Symmetric Positive-Definite matrix
    double** A = initializeMatrix(0, 10, matrixSize);
    double **L = initializeMatrix(0, 10, matrixSize);

    // Running Program: choleskyMPI() acts directly on the given matrix L

    choleskyMPI(A,L, matrixSize, argc, argv);

}
