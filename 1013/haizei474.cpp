/*************************************************************************
	> File Name: haizei474.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日 10/13 15:38:27 2019
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
#include <deque>
using namespace std;
typedef long long ll;

struct BigFloat {
    BigFloat(int x) {
        lpart.push_back(x);
        proccess_digit();
    }
    void operator*=(int x) {
        for (int i = 0; i < lpart.size(); i++) lpart[i] *= x;
        for (int i = 0; i < rpart.size(); i++) rpart[i] *= x;
        proccess_digit();
        return ;
    }
    void operator<<=(int x) {
        while (x--) {
            if (lpart.size()) {
                rpart.push_front(lpart[lpart.size() - 1]);
                lpart.pop_back();
            } else {
                rpart.push_front(0);
            }
        }
        if (lpart.size() == 0) lpart.push_front(0);
        trim();
        return ;
    }
    void trim() {
        while (lpart.size() > 1 && lpart[0] == 0) lpart.pop_front();
        while (rpart.size() && rpart[rpart.size() - 1] == 0) rpart.pop_back();
        return ;
    }
    void proccess_digit() {
        for (int i = rpart.size() - 1; i >= 0; i--) {
            if (rpart[i] < 10) continue;
            if (i == 0) {
                lpart[lpart.size() - 1] += rpart[i] / 10;
            } else {
                rpart[i - 1] += rpart[i] / 10;
            }
            rpart[i] %= 10;
        }
        for (int i = lpart.size(); i >= 0; i--) {
            if (lpart[i] < 10) continue;
            if (i == 0) lpart.push_front(0), ++i;
            lpart[i - 1] += lpart[i] / 10;
            lpart[i] %= 10;
        }
        trim();
    }
    deque<int> lpart, rpart;
};

ostream &operator<<(ostream &out, const BigFloat &a) {
    for (int i = 0; i < a.lpart.size(); i++) {
        out << a.lpart[i];
    }
    if (a.rpart.size() == 0) return out;
    out << ".";
    for (int i = 0; i < a.rpart.size(); i++) {
        out << a.rpart[i];
    }
    return out;
}

int main() {
    int n, p[4];
    string str;
    cin >> n >> str;
    BigFloat ans = 1;
    for(int i = 0; i < n; i++) {
        char ch;
        for (int j = 0; j < 4; j++) {
            cin >> p[j] >> ch;
        }
        ans *= p[str[i] - 'A'];
        ans <<= 2;
    }
    cout << ans << endl;
    return 0;
}
