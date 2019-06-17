/*************************************************************************
	> File Name: EP44.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  6/16 15:52:08 2019
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define INF 0x7fffffffffffffffLL

long long Pentagonal(long long n) {
    return n * (n * 3 - 1) / 2;
}

int binary_search(long long (*func)(long long), long long n, long long x) {
    long long head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main () {
    long long D = INF;
    long long pk, pj, n = 2;
    while (Pentagonal(n) - Pentagonal(n - 1) < D) {
        pk = Pentagonal(n);
        for (int j = n - 1; j >= 1; j--) {
            pj = Pentagonal(j);
            if (pk- pj >= D) break;
            int ind1 = binary_search(Pentagonal, 2 * n, pk + pj);
            int ind2 = binary_search(Pentagonal, n, pk - pj);
            if (ind1 && ind2) {
                D = pk - pj;
            }
        }
        n++;
    }
    printf("%lld\n", D);
    return 0;
}
