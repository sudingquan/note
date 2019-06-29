/*************************************************************************
	> File Name: EP39.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/29 14:50:30 2019
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

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    for (int n = 1; n <= 32; n++) {
        for (int m = n + 1; m <=32; m++) {
            if (gcd(n, m) - 1) continue;
            int a = m * m - n * n;
            int b = 2 * n * m;
            int c = m * m + n * n;
            for (int p = a + b + c; p <= MAX_N; p += (a + b + c)) {
                cnt[p] += 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= MAX_N; i++) {
        if (cnt[i] > cnt[ans]) ans = i;
    }
    cout << ans << endl;
}
