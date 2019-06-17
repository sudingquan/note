/*************************************************************************
	> File Name: EP15.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  6/16 20:59:59 2019
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

int main() {
    long long n = 40, m = 20, ans = 1;
    while (n != 20 || m != 0) {
        if (n != 20) ans *= (n--);
        if (m && ans % m == 0) ans /= (m--);
    }
    cout << ans << endl;
    return 0;
}
