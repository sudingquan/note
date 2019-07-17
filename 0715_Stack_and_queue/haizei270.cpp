/*************************************************************************
	> File Name: haizei270.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 三  7/17 15:47:52 2019
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
#define MAX_N 300000

int q[MAX_N + 5], head, tail;
int arr[MAX_N + 5];

int main() {
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0;
    ans = arr[1];
    for (int i = 1; i <=n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail --;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    cout << ans << endl;
    return 0;
}
