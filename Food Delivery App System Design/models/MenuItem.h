#ifndef MENUITEM_H
#define MENUITEM_H
using namespace std;

#include<iostream>
#include<string>
#include<vector>

class MenuItem {
private: 
    string menuCode;
    string name;
    int price;

public:
    MenuItem(string &menuCode, string &name, int price) {
        this->menuCode = menuCode;
        this->name = name;
        this->price = price;
    }

    string getCode() const {
        return menuCode;
    }

    void setCode(const string &code) {
        menuCode = code;
    }

    void setName(const string& n) {
        name = n;
    }

    int getPrice() {
        return price;
    }

    void setPrice(int p) {
        price = p;
    }
};

#endif