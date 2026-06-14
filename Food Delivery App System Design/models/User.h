#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include<vector>
#include "Cart.h"
using namespace std;

class User {
private:
    int userId;
    string userName;
    string userAddress;
    Cart* cart;

public:
    User(int userId, const string &name, const string &address) {
        this->userId = userId;
        this->userName = name;
        this->userAddress = address;
        cart = new Cart();
    }

    int getUserId() {
        return userId;
    }

    void setUserId(int id) {
        userId = id;
    }

    string getUserAddress() {
        return userAddress;
    }

    void setUserAddress(const string& address) {
        userAddress = address;
    }

    string getUserName() {
        return userName;
    }

    void setUserName(const string &name) {
        userName = name;
    }
};

#endif