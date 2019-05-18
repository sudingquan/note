/*************************************************************************
	> File Name: e2-4-21.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  4/21 16:32:34 2019
 ************************************************************************/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
int x,y;
int gcd2(int a, int b) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int r = gcd2(b, a % b), t = x;
    x = y;
    y = t - y * (a / b);
    return r;
}

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        gcd2(n, m);
        printf("%d * %d + %d * %d = %d\n", n, x, m, y, n * x + m * y);
    }
    return 0; 
}
