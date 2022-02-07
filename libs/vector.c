#include "vector.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

vector createVector(size_t n) {
    int *x = (int *) malloc(sizeof(int) * n);
    if (x == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {x, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity != 0) {
        v->data = realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        } else
            v->data = NULL;
        if (newCapacity < v->size)
            v->size = newCapacity;
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}



