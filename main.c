#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdint-gcc.h>
#include "C:\Users\megam\CLionProjects\practice\libs\vector.h"


void test_pushBack_emptyVector() {
    vector v = createVector(5);
    pushBack(&v, 4);
    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 4);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);
    assert(v.size == 5);
    pushBack(&v, 10);
    assert(v.size == 6);
    assert(v.capacity == 10);
    assert(v.data[v.size - 1] == 10);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_popBack(){
    test_popBack_notEmptyVector();
}

void test() {
    test_pushBack();
    test_popBack();
}

int main() {
    test();
};

