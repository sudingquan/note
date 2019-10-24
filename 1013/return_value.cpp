/*************************************************************************
	> File Name: test.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四 10/24 18:29:27 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

struct Data {
    Data(int x, int y) {
        this->x = x;
        this->y = y;
        cout << "parameter constructor" << endl;
    }
    Data(const Data &a) {
        this->x = a.x;
        this->y = a.y;
        cout << "copy constructor" << endl;
    }
    int x, y;
};

Data operator+(Data &a, Data &b) {
    return Data(a.x + b.x, a.y + b.y);
}

int main() {
    Data a(2, 3), b(5, 6);
    Data c = a + b;
    cout << sizeof(Data) << endl;
    return 0;
}
