/*************************************************************************
	> File Name: heap_sort.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 五  8/ 9 19:52:30 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

void down_updata(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; --i) {
        down_updata(arr, n, i);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[1], arr[i]);
        down_updata(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("arr[%d] = [", n);
    for (int i = 0; i < n; i++)  {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        arr[i] =  rand() % 100;
    }
    output(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    output(arr, MAX_OP);
    return 0;
}
