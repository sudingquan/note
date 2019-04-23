/*************************************************************************
	> File Name: e3-4-21.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  4/21 18:47:08 2019
 ************************************************************************/

#include <iostream>

using namespace std;

int ex_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1, *y = 0;
        return a;
    }
    int r = ex_gcd(b, a % b, y, x);

}

