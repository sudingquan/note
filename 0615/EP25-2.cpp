/*************************************************************************
	> File Name: EP25-2.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/15 20:02:48 2019
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

int f[2][1005];

int main() {
    int n = 2;
    f[0][0] = f[1][0] = f[0][1] = f[1][1] = 1;
    while (f[n % 2][0] < 1000) {
        n++;
        int n0 = n & 1, n1 = n0 ^ 1;
        for (int i = 1; i <= f[n1][0]; i++) {
            f[n0][i] += f[n1][i];
        }
        f[n0][0] = f[n1][0];
        for (int i = 1; i <= f[n0][0]; i++) {
            if (f[n0][i] < 10) continue;
            f[n0][i + 1] += f[n0][i] / 10;
            f[n0][i] %= 10;
            f[n0][0] += (f[n0][0] == i);
        }
    }
    cout << n << endl;
    return 0;
}
