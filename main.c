#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point {
    int x;
    int y;
    int z;
};

typedef struct point p;

void outputPoint(p point) {
    printf("x=%d  y=%d  z=%d", point.x, point.y, point.z);
}

void setPoint(p *point, int xPos, int yPos, int zPos) {
    if (point != NULL) {
        (*point).x = xPos;
        (*point).y = yPos;
        (*point).z = zPos;
    }
}

void freeMem(int **p) {
    free(*p);
    *p = NULL;
}

int sumOfNum(float a, float b) {
    return a + b;
}

int ofNum(float a, float b) {
    return a * b;
}
/*
  int *arr = NULL;

    arr = malloc(sizeof (int) * 10);

    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
        printf("%d\t", arr[i]);
    }

    arr = realloc(arr, sizeof (int) * 14);
    for (int i = 0; i < 4; i++) {
        arr[i + 11] = 7;
        printf("%d\t", arr[i + 11]);
    }

    freeMem(&arr);

*/

/*
 float (*function[2]) (float, float);
    function[0] = sumOfNum;
    function [1] = ofNum;

    printf("%f\t", function[0] (12.3345, 783.12432));
    printf("%f\t", function[1] (12.3345, 783.12432));
 */

int degreeOfNum(const int num, int degree) {
    if (degree > 1)
        return num * degreeOfNum(num, degree - 1);
    else if (degree == 0)
        return 1;
    else
        return num;
}

/*srand(time(NULL));
    int i = rand() % 5;
*/

typedef struct nameNhigh {
    char name[20];
    short high;
} haract;

void inputHaract(haract *h) {
    scanf("%s", h->name);
    scanf(" %d", h->high);
}

void outputHaract(haract *h) {

};

typedef struct nameNhigh haract;

/*int main() {
    char c[2][10] = {"qqq", "eee"};
    printf("size = %d\n", sizeof (c));
    for (int i = 0; i < 2; i++) {
        printf("%s\n", c[i]);
    }
    return 0;
}
*/

