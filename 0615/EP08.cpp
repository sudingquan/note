/*************************************************************************
	> File Name: EP08.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/15 16:37:45 2019
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
char num[MAX_N + 5];

int main() {
    int len = 0;
    // num + strlen(num)
    while (~scanf("%s", num + len)) {
        len += strlen(num + len);
    }
    long long p = 1, zero_cnt = 0, ans = 0;
    for (int i = 0; num[i]; i++) {
        num[i] -= '0';
        if (num[i]) p *= num[i];
        else zero_cnt += 1;
        if (i - 13 < 0) continue;
        if (num[i - 13]) p /= num[i - 13];
        else zero_cnt -= 1;
        if (zero_cnt == 0 && p > ans) ans = p;
    }
    printf("%lld\n", ans);
    return 0; 
}
