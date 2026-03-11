#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 20

int main() {
    int N, M, new_M, i, j, k, col_remove, valid;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    setlocale(0, "");

    printf("Введите N и M: ");
    if (scanf("%d %d", &N, &M) != 2) {
        printf("Ошибка: введите числовые значения");
        return 0;
    }

    if (N >= MAX_SIZE || M >= MAX_SIZE) {
        printf("Ошибка: размеры должны быть меньше %d", MAX_SIZE);
        return 0;
    }

    printf("Введите матрицу A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    col_remove = -1; //поиск столбца
    for (j = 0; j < M; j++) {
        valid = 1;
        for (i = 0; i < N; i++) {
            if (A[i][j] > 0) {
                valid = 0;
                break;
            }
            if (i > 0 && A[i][j] < A[i - 1][j]) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            col_remove = j;
            break;
        }
    }

    if (col_remove != -1) { //создание матрицы В
        new_M = M - 1;
        for (i = 0; i < N; i++) {
            k = 0;
            for (j = 0; j < M; j++) {
                if (j != col_remove) {
                    B[i][k] = A[i][j];
                    k++;
                }
            }
        }
        printf("Удален столбец %d\n", col_remove);
    }
    else {
        new_M = M;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                B[i][j] = A[i][j];
            }
        }
        printf("Столбец для удаления не найден\n");
    }

    printf("Матрица A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

    printf("Матрица B:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < new_M; j++) {
            printf("%4d", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}