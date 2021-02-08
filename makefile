cholesky: choleskyMPI.c generateMPI.c matrix.c
	mpicc -Wall -o "cholesky" "choleskyMPI.c" "generateMPI.c" "matrix.c" -lm -O3
