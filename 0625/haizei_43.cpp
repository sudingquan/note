/*************************************************************************
	> File Name: EP18-2.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 二  6/25 18:49:33 2019
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
#define MAX_N 1000
int val[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i ;j++) {
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    cout << val[0][0] << endl;
    return 0;
}
