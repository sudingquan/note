/*************************************************************************
	> File Name: e1-4-21.c
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  4/21 14:49:22 2019
 ************************************************************************/

#include <stdio.h>
int Pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}
int Hexagonal(int n) {
    return n * (2 * n - 1);
}
int binary_search(int (*num) (int), int n, int val) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if(num(mid) == val) return mid;
        if(num(mid) < val) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}


int main() {
    int n = 166;
    while (binary_search(Hexagonal, n, Pentagonal(n)) == -1) ++n;
    printf("%d\n", Pentagonal(n));
    return 0;
}
