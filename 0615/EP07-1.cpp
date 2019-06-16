/*************************************************************************
	> File Name: EP07-1.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/15 14:29:28 2019
 ************************************************************************/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

inline int is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int cnt = 0, i = 1;
    while (cnt < 10001) {
        i++;
        if (is_prime(i)) cnt += 1;
    }
    printf("%d\n",i);
    return 0;
}
