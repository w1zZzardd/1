#include <assert.h>
#include "../practice/libs/matrix.h"


void test_swapRows_changeFirstAndSecondRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 1, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 5, 6,
                                                           1, 2, 3,
                                                           7, 8, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            if (m.values[i][j] == expectedMatrix.values[i][j])
                isEqual = true;
            else
                isEqual = false;
            assert(isEqual == true);
        }
    }
}

void test_swapRows_changeFirstAndThirdRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 1, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 8, 9,
                                                           4, 5, 6,
                                                           1, 2, 3}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            if (m.values[i][j] == expectedMatrix.values[i][j])
                isEqual = true;
            else
                isEqual = false;
            assert(isEqual == 0);
        }
    }
}

void test_swapColumns_swapFirstAndSecondColumns() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3}, 3, 3);
    swapColumns(m, 0, 1);
    matrix expectedMatrix = createMatrixFromArray((int[]) {2, 1, 3,
                                                           2, 1, 3,
                                                           2, 1, 3}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapCols_changeFirstAndThirdCols() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapColumns(m, 0, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {3, 2, 1,
                                                           6, 5, 4,
                                                           9, 8, 7}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_SORT_changeFirstAndSecondCols() {
    matrix m = createMatrixFromArray((int[]) {4, 5, 6,
                                              7, 8, 9,
                                              1, 2, 3}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);

    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_SORT_changeFirstAndSecondCols2() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              13, 12, 4,
                                              7, 5, 8}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 5, 8,
                                                           7, 8, 9,
                                                           13, 12, 4}, 3, 3);

    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4, 5,
                                              2, 9, 5, 6,
                                              3, 10, 6, 11}, 3, 4);
    insertionSortColsMatrixByColCriteria(m, maxElementInCol);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 4, 8, 5,
                                                           2, 5, 9, 6,
                                                           3, 6, 10, 11}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }

}

void test_isEMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    assert(isEMatrix(m));
}

void test_isSymmetricMatrix_isSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 10,
                                              6, 1, 3,
                                              10, 3, 1}, 3, 3);
    assert(isSymmetricMatrix(m));
}

void test_isSymmetricMatrix_isNotSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 10,
                                              3, 1, 3,
                                              10, 3, 1}, 3, 3);
    assert(!isSymmetricMatrix(m));
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    transposeSquareMatrix(m);
    matrix answerMatrix = createMatrixFromArray((int[]) {1, 10, 3,
                                                         8, 9, 8,
                                                         3, 11, 9}, 3, 3);

    assert(twoMatricesEqual(m, answerMatrix) == 1);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    position expectedMinPos = (position) {0, 0};
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == expectedMinPos.rowIndex);
    assert(minPos.colIndex == expectedMinPos.colIndex);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    position expectedMaxPos = (position) {2, 1};
    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == expectedMaxPos.rowIndex);
    assert(maxPos.colIndex == expectedMaxPos.colIndex);
}

int main() {
    test_SORT_changeFirstAndSecondCols();
    test_getMinValuePos();
    test_getMaxValuePos();

    return 0;
}

