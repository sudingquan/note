/*************************************************************************
	> File Name: EP07-3.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/15 15:52:57 2019
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
int is_prime[MAX_N + 5];
int prime[MAX_N + 5];

int main() {
    for (int M = 2; M <= MAX_N; M++) {
        if (is_prime[M] == 0) {
            prime[++prime[0]] = M;
        }
        for(int j = 1; j<= prime[0]; j++) {
            if (prime[j] * M > MAX_N) break;
            is_prime[prime[j] * M] = 1;
            if (M % prime[j] == 0) break;
        }
    }
    cout << prime[10001] << endl;
    return 0;
}
