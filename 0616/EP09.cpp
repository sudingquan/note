/*************************************************************************
	> File Name: EP09.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  6/16 19:21:33 2019
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
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    int ans;
    for (int n = 1; n <= 33; n++) {
        for (int m = n + 1; m * m + n * n <= 1000; m++) {
            if (gcd(n, m) != 1) continue;
            int a = 2 * n * m;
            int b = m * m - n * n;
            int c = m * m + n * n;
            if (1000 % (a + b + c) == 0) {
                int k = 1000 / (a + b + c);
                cout << k << endl;
                ans = a * b * c * (int)pow(k, 3);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
