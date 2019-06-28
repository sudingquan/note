/*************************************************************************
	> File Name: EP26.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四  6/27 18:45:15 2019
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
int r_len[MAX_N + 5];

int get_length(int x, int y) {
    int r = x % y, t = 1;
    memset(r_len, 0, sizeof(r_len));
    r_len[r] = 1;
    while (r) {
        r = r * 10 % y;
        t += 1;
        if (r_len[r]) return t - r_len[r];
        r_len[r] = t;
    }
    return 0;
}

int main() {
    int d = 0, len = -1;
    for (int i = 2; i < MAX_N; i++) {
        int temp = get_length(1, i);
        if (temp > len) {
            len = temp;
            d = i;
        }
    }
    cout << d << endl;
    cout << len << endl;
    return 0;
}
