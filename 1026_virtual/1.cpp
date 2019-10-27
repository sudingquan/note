/*************************************************************************
	> File Name: 1.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六 10/26 14:52:28 2019
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

class Animal {
public :
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
};

class Cat : public Animal {
public:
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

int main() {
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    return 0;
}
