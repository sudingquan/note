/*************************************************************************
	> File Name: haizei_53.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四  6/27 19:14:00 2019
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
int prime[MAX_N + 5];
long long sum_num[MAX_N + 5];
//long long mnum[MAX_N + 5];

int main() {
    sum_num[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]]  = i;
            sum_num[i] = i + 1;
            //mnum[i] = i;
        }
        for (int j = 1; j < prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                sum_num[i * prime[j]] = sum_num[i] * sum_num[prime[j]];
                //mnum[i * prime[j]] = prime[j];
            } else {
                //mnum[i * prime[j]] = mnum[i] * mnum[prime[j]];
                //int min_prime = mnum[i] * prime[j], rest = i * prime[j] / min_prime;
                int min_prime = prime[j];
                int rest = i;
                while (rest % prime[j] == 0) {
                    rest /= prime[j];
                    min_prime *= prime[j];
                }
                sum_num[i * prime[j]] = sum_num[min_prime] * sum_num[rest];
                if (rest == 1) sum_num[i * prime[j]] = (min_prime * prime[j] - 1) / (prime[j] - 1);
                break;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (sum_num[i] > ans) ans = sum_num[i];
    }
    cout << ans << endl;
}
