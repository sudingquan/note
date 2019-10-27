/*************************************************************************
	> File Name: virtual.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六 10/26 15:38:22 2019
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
#include <time.h>
using namespace std;
typedef long long ll;

struct Animal {
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
    virtual void test(int x) {
        cout << this << endl;
        cout << x << endl;
        cout << "class Animal test" << endl;
    }
};

struct Cat : Animal {
    void run() {
        cout << "I can run like a cat" << endl;
    }
};

struct Dog : Animal {
    void run() {
        cout << "I can run like a dog" << endl;
    }
    void test() {
        cout << "class Dog test" << endl;
    }
};

typedef void (*(func_t))();
typedef void (*(func_t1))(void *, int);

int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) {
            arr[i] = new Cat;
        } else {
            arr[i] = new Dog;
        }
    }
    arr[8]->run();
    Cat a;
    ((func_t **)(&a))[0][0]();
    ((func_t1 **)(&a))[0][1](&a, 123);
    return 0;
}
