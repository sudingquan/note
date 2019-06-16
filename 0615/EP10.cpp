/*************************************************************************
	> File Name: EP10.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  6/16 02:02:46 2019
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
#define MAX_N 2000000
int is_prime[MAX_N + 5];
int prime[MAX_N + 5];

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <=prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= MAX_N; i++) {
        if (prime[i] > MAX_N) break;
        ans += prime[i];
    }
    cout << ans << endl;
    return 0;
}
