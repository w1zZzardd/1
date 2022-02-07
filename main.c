#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "C:\Users\megam\CLionProjects\practice\libs\vector.h"


void test_pushBack_emptyVector() {
    vector v = createVector(0);
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

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int* index = atVector(&v, 3);
    assert(*index == 4);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int* index = atVector(&v, 4);
    assert(*index == 4);
}

void test_back_oneElementInVector (){
    vector v = createVector(1);
    pushBack(&v, 4);

    int *pBack = back(&v);
    assert(*pBack == 5);
}

void test_front_oneElementInVector (){
    vector v = createVector(1);
    pushBack(&v, 5);

    int *pFront = front(&v);
    assert(*pFront == 5);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_popBack(){
    test_popBack_notEmptyVector();
}

void test_atVector() {
    void test_atVector_notEmptyVector();
    void test_atVector_requestToLastElement();
}

void test_oneElement (){
    void test_back_oneElementInVector ();
    void test_front_oneElementInVector ();
}

void test() {
    test_pushBack();
    test_popBack();
    test_atVector();
    void test_oneElement();
}

int main() {
    test();
};

