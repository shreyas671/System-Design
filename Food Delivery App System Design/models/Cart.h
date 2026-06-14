#ifndef CART_H
#define CART_H

#include<iostream>
#include<string>
#include<vector>
#include "Restaurant.h"
#include "MenuItem.h"
using namespace std;

class Cart {
private:
    Restaurant *restaurant;
    vector<MenuItem> cartItems;

public:
    Cart() {
        restaurant = nullptr;
    }

    void addItem(const MenuItem &item) {
        if(!restaurant) {
            cout<<"Set a restaurant before adding"<<endl;
            return;
        }
        cartItems.push_back(item);
    }

    double totalCartAmount() {
        double sum = 0;
        for(auto it: cartItems) {
            sum += it.getPrice();
        }
        return sum;
    }

    const vector<MenuItem> getCartItems() {
        return cartItems;
    }

    void clear() {
        cartItems.clear();
        restaurant = nullptr;
    }

    bool isCartEmpty() {
        return (!restaurant || cartItems.empty());
    }


};

#endif