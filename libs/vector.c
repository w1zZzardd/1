#include "vector.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

vector createVector(size_t n) {
    int *x = (int *) malloc(sizeof(int) * n);
    if (x == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {x, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
    } else {
        deleteVector(v);
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
    }
    return &v->data + index;
}

int *back(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
    return v->data + v->size - 1;
}

int *front(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
    return v->data;
}