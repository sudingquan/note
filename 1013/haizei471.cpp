/*************************************************************************
	> File Name: haizei471.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日 10/13 14:53:35 2019
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

struct BigInt {
    BigInt() {
        num.push_back(0);
    }
    BigInt operator*(const BigInt &a) {
        BigInt c;
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < a.num.size(); j++) {
                if (i + j == c.num.size()) c.num.push_back(0);
                c.num[i + j] += num[i] * a.num[j];
            }
        }
        c.process_digit();
        return c;
    }
    void operator=(const string &str) {
        num.clear();
        for (int i = str.size() - 1; i >= 0; i--) {
            num.push_back(str[i] - '0');
        }
        return ;
    }
    void process_digit() {
        while (num.size() - 1 && num[num.size() - 1] == 0) num.pop_back();
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        return ;
    }
    vector<int> num;
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.num.size() - 1; i >= 0; i--) out << a.num[i];
    return out;
}

int main() {
    BigInt a, b;
    string str_a, str_b;
    cin >> str_a >> str_b;
    a = str_a;
    b = str_b;
    cout << a * b << endl;
    return 0;
}
