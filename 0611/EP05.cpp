/*************************************************************************
	> File Name: EP05.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 二  6/11 20:17:02 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    return (b ? gcd(b, a % b) : a);
}

long long ex_gcd(long long a, long long b, int &x, int &y) {
    if (b == 0) {
         x = 1, y = 0;
        return a;
    }
    int ret = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}

int main() {
    long long ans = 1;
    for (int i = 2; i <= 20; i++) {
        ans = ans * i / gcd(ans, i);
    }
    cout << ans <<endl;
    return 0;
}
