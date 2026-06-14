#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<string>
#include<vector>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
using namespace std;

class Order {
protected: 
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem> menuItems;
    PaymentStrategy* paymentStrategy;
    double total;
    string scheduled;

public:
    Order() {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = nextOrderId;
    }

    virtual ~Order() {
        delete paymentStrategy;
    }

    bool processPayment() {
        if(paymentStrategy) {
            paymentStrategy->pay(total);
            return true;
        }

        cout<<"Please Select an Payment Statergy"<<endl;
        return false;
    }

    virtual string getType() const = 0;

    int getOrderId() {
        return orderId;
    }

    void setUser(User* u) {
        user = u;
    }

    User* getUser() {
        return user;
    }

    Restaurant* getRestaurant() {
        return restaurant;
    }

    void setRestaurant(Restaurant* rest) {
        restaurant = rest;
    }

    void setItems(const vector<MenuItem> item) {
        menuItems = item;
        total = 0;
        for (auto &i : menuItems) {
            total += i.getPrice();
        }
    }

    const vector<MenuItem> getMenu() {
        return menuItems;
    }

    void setPaymentStrategy(PaymentStrategy* p) {
        paymentStrategy = p;
    }

    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return total;
    }

    void setTotal(int total) {
        this->total = total;
    }

};

int Order::nextOrderId = 0;

#endif