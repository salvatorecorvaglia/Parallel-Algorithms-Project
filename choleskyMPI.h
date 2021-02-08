#include "matrix.h"
#include <mpi.h>

typedef int bool;
#define true 1
#define false 0

void choleskyMPI(double ** L, int n, int argc, char ** argv);
