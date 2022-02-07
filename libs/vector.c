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

bool isEmpty (vector *v){
    return v->size == 0;
}

bool isFull (vector *v){
    return v->size == v->capacity;
}

int getVectorValue (vector *v, size_t i){
    return v->data [i];
}

void pushBack(vector *v, int x){
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data [v->size++] = x;
}

void popBack (vector *v){
    if (isEmpty(v)){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->size--;
}



