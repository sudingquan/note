/*************************************************************************
	> File Name: operator.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四 10/24 19:10:41 2019
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

//左右值引用判断方法 看声明和定义形式
//左右值判断方法 看下一行这个变量是否存在

struct Data {
    Data(int x, int y) : x(x), y(y) {}
    Data operator+(const Data &a) const {
        return Data(x + a.x, y + a.y);
    }
    Data &operator+=(Data &b) {
        x += b.x;
        y += b.y;
        return *this;
    }
    Data &operator++() {
        x++;
        y++;
        return *this;
    }
    Data operator++(int) {
        Data ret(*this);
        x++;
        y++;
        return ret;
    }
    Data *operator->() {
        return p;
    }
    int x, y;
    Data *p;
};

void func2(Data &b) {
    cout << 1 << endl;
}

void func2(Data &&b) {
    cout << 2 << endl;
}

void func(Data &a) {
    cout << 1 << endl;
    func2(a);
}

void func(Data &&a) {
    cout << 2 << endl;
    func2(a); //不完美绑定
    //完美绑定
    //func2(std::forward();
}

ostream &operator<<(ostream &out, const Data &a) {
    out << "class<Data> " << a.x << " " << a.y;
    return out;
}

int main() {
    Data a(2, 4), b(5, 6);
    func(a);
    func(a + b);
    cout << a.operator+(b) << endl;
    cout << a + b << endl;
    cout << (a += b) << endl;
    cout << (++a) << endl;
    cout << (a++) << endl;
    cout << a << endl;
    //a->x <==> ((a->).x)
    a.p = &b;
    cout << (a->x) << endl;
    //a->x ==> a.operator->()->x;
    //a.x ==> a.operator.operator. ... 产生递归, 所以不可以重载.运算符
    // ?: 三目运算符不能
    // sizeof 不能 因为这个是编译时确定的值
    // :: 域运算符不可以
    // new 和 del 可以重载
    return 0;
}
