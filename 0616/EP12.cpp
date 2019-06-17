/*************************************************************************
	> File Name: EP12.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  6/16 20:01:07 2019
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
#define MAX_N 1000000
int prime[MAX_N + 5];//同时做为素数表和标记素数的表
int f[MAX_N + 5];//因子数
int cnt[MAX_N + 5];//最小素因子

int main() {
    f[1] = 1;
    for (int i = 2; 2 * i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; prime[j] * i <= MAX_N; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[prime[j] * i] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[prime[j] * i] = cnt[i] + 1;
                break;
            } else {
                f[prime[j] * i] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
    long long n = 1;
    while (true) {
        int f_nums;
        if (n % 2) {
            f_nums = f[n] * f[(n + 1) / 2];
        } else {
            f_nums = f[n / 2] * f[n + 1];
        }
        if (f_nums > 500) break;
        n++;
    }
    cout << n * (n + 1) / 2 << endl;
    return 0 ;
}
