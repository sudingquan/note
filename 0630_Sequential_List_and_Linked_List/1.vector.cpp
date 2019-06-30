/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  6/30 15:18:10 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

//#define init(n) ((#n)[0] ? __init(n+0) : __init(10))
#define default_value(n, val) ((#n)[0] ? n + 0 : val)
#define init(n) __init(default_value(n, 10))

Vector *__init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expand(Vector *vec) {
    int new_size = vec->size * 2;
    int *p = (int *)realloc(vec->data, sizeof(int) * new_size);
    if (p == NULL) return 0;
    vec->size = new_size;
    vec->data = p;
    return 1;
}

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
        printf("expand vector size to %d success\n", vec->size);
    }
    if (ind < 0 || ind > vec->length) return 0;
    for (int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (vec->length == 0) return 0;
    if (ind < 0 && ind >= vec->length) return 0;
    for (int i = ind + 1; i < vec->length; i++) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 1;
}

void clear(Vector *vec) {
    if (vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}

void output(Vector *vec) {
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        if (i != 0) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n\n");
    return ;
}

void output_ind(Vector *vec, int val) {
    int sum = 0;
    sum += printf("Vector(%d) = [", vec->length);
    int ind = sum - 1;
    for (int i = 0; i < vec->length; i++) {
        if (i != 0) sum += printf(", ");
        sum += printf("%d", vec->data[i]);
        if (vec->data[i] == val) {
            ind = sum - 1;
        }
    }
    sum += printf("]");
    printf("\n");
    for (int i = 0; i < sum; i++) {
        if (i - ind) printf(" ");
        else printf("^");
    }
    printf("\n");
    for (int i = 0; i < sum; i++) {
        if (i - ind) printf(" ");
        else printf("|");
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    int op, ind, val;
    Vector *vec = init();
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;
        ind = rand() % (vec->length + 3);
        val = rand() % 10000;
        switch (op) {
            case 0: {
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 1: {
                printf("erase item at %d from vector = %d\n", ind, erase(vec, ind));
            } break;
            case 2: {
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 3: {
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
        }
        output(vec);
    }
    while (~scanf("%d", &val)) {
        output_ind(vec, val);
    }
    return 0;
}
