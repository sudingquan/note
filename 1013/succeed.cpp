/*************************************************************************
	> File Name: succeed.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日 10/13 18:24:47 2019
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
#define P_ADD(x) cout << #x << " : " << &(x)

class Animal {
public:
    Animal(string name) : _name(name) {
        cout << "Animal : " << this << endl;
    }
    const string &name() const { return this->_name; }
    void say() {
        cout << "I'm an Animal" << endl;
    }
    int x, y;
private:
    string _name;
};

class Cat : public Animal {
public:
    Cat() : Animal("hello kitty") {
        cout << "Cat : " << this << endl; 
    }
    void say() {
        cout << "I'm a Cat" << endl;
    }
    int z;
};

class Dog : public Animal {
public:
    Dog() : Animal("Anby") {}
};

class Monkey : public Animal {
public:
    Monkey() : Animal("Monkey 666") {}
};

ostream &operator<<(ostream &out, const Cat &a) {
    out << "<class Cat(" << sizeof(a) << ")> : " << a.name() << endl;
    P_ADD(a.x) << endl;
    P_ADD(a.y) << endl;
    P_ADD(a.z) << endl;
    return out;
}

ostream &operator<<(ostream &out, const Dog &a) {
    out << "<class Dog> : " << a.name();
    return out;
}

ostream &operator<<(ostream &out, const Monkey &a) {
    out << "<class Monkey> : " << a.name();
    return out;
}

int main() {
    Cat a;
    Dog b;
    Monkey c;
    cout << a << endl << b << endl << c << endl;
    Animal *p = &a;
    a.say();
    p->say();
    return 0;
}
