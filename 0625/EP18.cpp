/*************************************************************************
	> File Name: 18.EP_2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年06月25日 星期二 19时01分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define MAX 100
int val[MAX + 5][MAX + 5];
int keep[MAX + 5][MAX + 5];

int dfs(int i, int j, int n) {
    if(i + 1 == n) { return val[i][j]; }
    if(keep[i][j] != 0) return keep[i][j];
    int val1 = dfs(i + 1, j, MAX);
    int val2 = dfs(i + 1, j + 1, MAX);
    if(val1 > val2) keep[i][j] =  val1 + val[i][j];
    if(val1 < val2) keep[i][j] =  val2 + val[i][j];
    return keep[i][j];
}

int main() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }

    int ans = dfs(0, 0, MAX);
    printf("%d\n", ans);
    
    
    return 0;
}
