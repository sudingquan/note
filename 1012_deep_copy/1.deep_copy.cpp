/*************************************************************************
	> File Name: 1.deep_copy.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六 10/12 18:43:45 2019
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

class A{
public:
    A() {
        n = 100;
        str = new char[n];
    }
    A(const A &obj) : A() {
        memcpy(str, obj.str, sizeof(char) * n);
    }
    ~A() {
        printf("%p\n", str);
        fflush(stdout);
        delete[] str;
    }
private:
    int n;
    char *str;
};

int main() {
    A a, b = a;
    cout << "hello haizei" << endl;
    return 0;
}
