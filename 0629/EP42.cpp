/*************************************************************************
	> File Name: 42.EP.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年06月29日 星期六 15时06分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include "EP42_input"

using namespace std;

int triangle(int x) {
    return x * (x + 1) / 2;
}

bool binary_search(int (*func)(int), int l, int r, int x) {
    if(l > r) return false;
    int mid = (l + r) / 2;
    if(func(mid) == x) return true;
    if(func(mid) > x) r = mid - 1;
    else l = mid + 1;
    return binary_search(func, l, r, x);
}

bool is_valid(char *str) {
    int sum = 0;
    for(int i = 0; str[i]; i++) {
        sum += (str[i] - 'A' + 1);
    }
    return binary_search(triangle, 1, sum, sum);
}

int main() {
    int n = sizeof(str) / 100; 
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(is_valid(str[i])) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
