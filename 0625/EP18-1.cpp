/*************************************************************************
	> File Name: EP18-1.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 二  6/25 19:21:30 2019
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
#define MAX_N 100
int val[MAX_N + 5][MAX_N +5];
int keep[MAX_N + 5][MAX_N +5];

int dfs(int i, int j, int n) {
    if (i + 1 == n) { return val[i][j]; }
    if (keep[i][j] != 0) return keep[i][j];
    int val1 = dfs(i + 1, j, MAX_N);
    int val2 = dfs(i + 1, j + 1, MAX_N);
    return keep[i][j] = (val1 > val2 ? val1 : val2);
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, MAX_N) << endl;
    return 0;
}
