/*************************************************************************
	> File Name: EP46.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/29 15:39:58 2019
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
#define MAX_N 100000
int prime[MAX_N + 5];
int is_prime[MAX_N + 5];

int func(int n) {
    return 2 * n * n;
}

bool binary_search(int (*f)(int), int l, int r, int val) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (f(mid) == val) return true;
    if (f(mid) > val) r = mid - 1;
    else l = mid + 1;
    return binary_search(f, l, r, val);
}

bool is_vaild(int x) {
    for (int i = 1; i <= prime[0] && prime[i] < x; i++) {
        // x = prime[i] + 两倍平方数
        int val = x - prime[i];
        if (!binary_search(func, 1, val, val)) continue;
        return true;
    }
    return false;
}

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 9; i <= MAX_N; i += 2) {
        if (is_prime[i] == 0) continue;
        if (!is_vaild(i)) {
            cout << i << endl;
            break;
        }
    }
}
