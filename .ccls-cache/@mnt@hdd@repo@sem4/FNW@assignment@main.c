#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void print_mat(gsl_matrix *m);
int index_mat(int i, int j, int Nside) { return i * Nside + j; }

int main(int argc, char** argv) {

    printf("%d\n", argc);
    if (argc == 2) {
        printf("%s\n", argv[1]);
        if (strcmp(argv[1], "plot") == 0) {
            system("notify-send something");
            return 0;
        }
    }

    if (argc != 3) {
        printf("Usage: ./a.out <number of POINTS> <FILENAME>\n");
        exit(-1);
    }

    int N = atoi(argv[1]);
    int Nside = sqrt(N);

    if (Nside * Nside != N) {
        printf("N is not a perfect square!\n");
        exit(-1);
    }

    gsl_matrix *A = gsl_matrix_calloc(N, N);
    gsl_vector *b = gsl_vector_calloc(N);
    gsl_vector *x = gsl_vector_alloc(N);

    for (int j = 1; j <= Nside; j++) {
        for (int i = 1; i <= Nside; i++) {
            int k = (j - 1) * Nside + (i - 1);
            gsl_vector_set(b, k, 0);
            gsl_matrix_set(A, k, k, -4);

            if (i > 1) {
                int left = k - 1;
                gsl_matrix_set(A, k, left, 1);
            } else {
                gsl_vector_set(b, k, gsl_vector_get(b, k) - 0);
            }

            if (i < Nside) {
                int right = k + 1;
                gsl_matrix_set(A, k, right, 1);
            } else {
                gsl_vector_set(b, k, gsl_vector_get(b, k) - 0);
            }

            if (j > 1) {
                int bottom = k - Nside;
                gsl_matrix_set(A, k, bottom, 1);
            } else {
                gsl_vector_set(b, k, gsl_vector_get(b, k) - 10);
            }

            if (j < Nside) {
                int top = k + Nside;
                gsl_matrix_set(A, k, top, 1);
            } else {
                gsl_vector_set(b, k, gsl_vector_get(b, k) - 0);
            }
        }
    }

    /* print_mat(A); */

    gsl_permutation *p = gsl_permutation_alloc(N);
    int signum;

    gsl_linalg_LU_decomp(A, p, &signum);
    gsl_linalg_LU_solve(A, p, b, x);

    FILE* fp = fopen(argv[2], "w");

    for (int i = 0; i < Nside+2; i++) {
        fprintf(fp, "%4.2d ", 10);
    }
    fprintf(fp, "\n");

    for (int i = 0; i < Nside; i++) {
        fprintf(fp, "%4.1d ", 0);
        for (int j = 0; j < Nside; j++) {
            fprintf(fp, "%4.2f ", gsl_vector_get(x, index_mat(i, j, Nside)));
        }
        fprintf(fp, "%4.1d \n", 0);
    }
    for (int i = 0; i < Nside+2; i++) {
        fprintf(fp, "%4.1d ", 0);
    }
    fprintf(fp, "\n");

    fclose(fp);

    gsl_permutation_free(p);
    gsl_matrix_free(A);
    gsl_vector_free(b);
    gsl_vector_free(x);

    return 0;
}

void print_mat(gsl_matrix *m) {
    for (int j = 0; j < m->size1; j++) {
        for (int i = 0; i < m->size2; i++) {
            printf("%2.0f ", gsl_matrix_get(m, i, j));
        }
        printf("\n");
    }
}
