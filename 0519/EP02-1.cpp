/*************************************************************************
	> File Name: EP02-1.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  5/19 18:14:27 2019
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 44
#define MAX_M 4000000

int fib[MAX_N + 5];

int main() {
    int n = 2;
    fib[1] = 1;
    fib[2] = 2;
    while (fib[n] + fib[n - 1] < MAX_M) {
        fib[n + 1] = fib[n] + fib[n - 1];
        n += 1;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (fib[i] % 2) continue;
        sum += fib[i];
    }
    printf("%lld\n", sum);
    return 0;
}
