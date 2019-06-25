/*************************************************************************
	> File Name: haizei_54.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 二  6/25 19:55:15 2019
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
#define MAX_N 5000
int num[MAX_N + 5];
int ans[MAX_N + 5];

int main () {
    int x;
    while (~scanf("%d",&x)) {
        num[0] = num[1] = 1;
        for (int i = 1 ; i <= x; i++) {
            for (int j = 1; j <= num[0]; j++) num[j] *= i;
            for (int j = 1; j<= num[0]; j++) {
                if (num[j] < 10) continue;
                num[num[0] + 1] = 0;
                num[j + 1] += num[j] / 10;
                num[j] %= 10;
                num[0] += (j == num[0]);
            }
        }
        ans[0] = ans[1] = 1;
        for (int i = 1; i <= num[0]; i++) {
            if (num[i] == 0) continue;
            for (int j = 1; j <= ans[0]; j++) ans[j] *= num[i];
            for (int j = 1; j <= ans[0]; j++) {
                if (ans[j] < 10) continue;
                ans[ans[0] + 1] = 0;
                ans[j + 1] += ans[j] / 10;
                ans[j] %= 10;
                ans[0] += (j == ans[0]);
            }
        } 
        for (int i = ans[0]; i > 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
