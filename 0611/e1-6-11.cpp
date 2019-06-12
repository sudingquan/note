/*************************************************************************
	> File Name: e1-6-11.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 二  6/11 18:10:32 2019
 ************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;
#define MAX_N 100000
int arr [MAX_N + 5];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    nth_element(arr, arr + n / 2, arr + n);
    int pos = arr[n / 2], ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(arr[i] - pos);
    }
    cout << ans << endl;
    return 0;
}
