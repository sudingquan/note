/*************************************************************************
	> File Name: EP14-1.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  6/15 19:04:47 2019
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

int get_chain_lenth(long long x) {
    if (x == 1) return 1;
    if (x & 1) return get_chain_lenth(3 * x + 1) + 1;
    return get_chain_lenth(x / 2) + 1;
}

int main() {
    int max_len = 0, num = 0;
    for (int i = 1 ;i <= 1000000; i++) {
        int l = get_chain_lenth(i);
        if (l > max_len) max_len = l, num = i;
    }
    cout << num << " " << max_len << endl;
    return 0;
}
