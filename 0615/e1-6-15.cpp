/*************************************************************************
	> File Name: e1-6-15.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/15 15:04:07 2019
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
#define MAX_N 200000
int prime[MAX_N + 5];

int main() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[i] = i;
        for (int j = i * i; j <= MAX_N; j += i) {
            if (prime[j] == 0) prime[j] = i;
        }
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("is_prime[%d] = %d\n", n, prime[n]);
    }
    return 0;
}
