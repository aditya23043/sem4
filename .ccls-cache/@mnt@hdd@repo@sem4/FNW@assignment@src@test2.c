#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>

typedef struct Point {
    int potential;
    int x;
    int y;
} Point;

#define N 16
#define V 10

void print(Point points[][(int)sqrt(N)], int side);

int main(void) {

    int side = sqrt(N);
    if (side * side != N) {
        fprintf(stderr, "N is not a perfect square!\n");
        exit(-1);
    }

    Point points[side][side];
    memset(points, 0, sizeof(points));

    // INIT
    for (int i = 0; i < side; i++) {
        points[i][0].potential = V;
        for (int j = 0; j < side; j++) {
            points[i][j].x = i;
            points[i][j].y = j;
            if (j != 0 && i != 0 && j != side - 1 && i != side - 1) {
                points[i][j].potential = -1;
            }
        }
    }

    gsl_matrix *A = gsl_matrix_alloc(side-1, side-1);
    gsl_matrix_set_zero(A);
    gsl_vector *x = gsl_vector_alloc(side-1);
    gsl_vector *b = gsl_vector_alloc(side-1);
    gsl_vector_set_zero(b);
    gsl_permutation *p = gsl_permutation_alloc(side-1);
    int s;

    for (int j = 1; j < side-1; j++) {
        if (j - 1 == 0) {
            gsl_vector_set(b, j-1, -V);
        }
        for (int i = 1; i < side-1; i++) {
        }
    }

    print(points, side);

    gsl_permutation_free(p);
    gsl_vector_free(x);
    gsl_vector_free(b);
    gsl_matrix_free(A);

    return 0;
}

void print(Point points[][(int)sqrt(N)], int side) {
    for (int j = 0; j < side; j++) {
        for (int i = 0; i < side; i++) {
            printf("%d ", points[i][j].potential);
        }
        printf("\n");
    }
}
