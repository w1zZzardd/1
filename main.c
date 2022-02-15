#include <assert.h>
#include "../practice/libs/matrix.h"


int main() {
    matrix m = getMemMatrix(4, 4);
    inputMatrix(m);

    position p = getMaxValuePos(m);

    printf("{%d ; %d}", p.rowIndex, p.colIndex);

    return 0;
}

