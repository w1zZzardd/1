#include "matrix.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//2 блок
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
}

//3 блок
void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; ++j) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
    printf("\n");
}

//4 блок
void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

//5 блок
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        a[i] = criteria(m.values[i], m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        int max = i;
        for (int j = i; j < m.nRows; j++) {
            if (a[j] > a[max])
                max = j;
        }
        swap(&a[max], &a[i]);
        swapRows(m, i, max);
    }
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int *criteriaArr = (int *) malloc(sizeof(int) * m.nCols);
    int *additionalArr = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            additionalArr[j] = m.values[j][i];
        criteriaArr[i] = criteria(additionalArr, m.nRows);
    }
    for (int i = 0; i < m.nCols; i++) {
        for (int j = i; j > 0 && criteriaArr[j - 1] > criteriaArr[j]; j--) {
            swap(&criteriaArr[j - 1], &criteriaArr[j]);
            swapColumns(m, j, j - 1);
        }
    }
    free(criteriaArr);
    free(additionalArr);
}

//6 блок
bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows && m1.nCols != m2.nCols)
        return 0;
    else {
        bool isEqual = false;
        for (int i = 0; i < m1.nRows; i++) {
            for (int j = 0; j < m1.nCols; j++) {
                isEqual = (bool) (m1.values[i][j] == m2.values[i][j]);
                if (isEqual == false)
                    return false;
            }
        }
        return isEqual;
    }
}

bool isEMatrix(matrix m) {
    int isE = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i == j && m.values[i][j] == 1 || i != j && m.values[i][j] == 0)
                isE = 1;
            else
                return 0;
        }
    }
    return isE;
}

bool isSymmetricMatrix(matrix m) {
    int isSymmetric = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; ++j) {
            isSymmetric = (m.values[i][j] == m.values[j][i]);
        }
    }
    return isSymmetric;
}

//7 блок
void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i + 1; j < m.nCols; j++) {
            swap(&m.values[i][j], &m.values[j][i]);
        }
    }
}

//8 блок
position getMinValuePos(matrix m) {
    int minValue = m.values[0][0];
    position minPos = {0, 0};
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                minPos = (position) {i, j};
            }
        }
    }
    return minPos;
}

position getMaxValuePos(matrix m) {
    int maxValue = m.values[0][0];
    position maxPos = {0, 0};
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > maxValue) {
                maxValue = m.values[i][j];
                maxPos = (position) {i, j};
            }
        }
    }
    return maxPos;
}

//9 блок
matrix createMatrixFromArray(const int *a, size_t nRows,
                             size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

void task1(matrix m) {
    position maxIndex = getMaxValuePos(m);
    position minIndex = getMinValuePos(m);
    swapRows(m, maxIndex.rowIndex, minIndex.rowIndex);
}

int getMinNegative(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return -min;
}


void task2(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMinNegative);
}