#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<string>
#include<vector>
#include "MenuItem.h"
using namespace std;

class Restaurant {
private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menuItems;

public: 
    Restaurant(const string& name, const string& location) {
        this->name = name;
        this->location = location;
        this->restaurantId = nextRestaurantId;
    }

    string getName() {
        return name;
    }

    void setName(string &n) {
        name = n;
        return;
    }

    string getLocation () {
        return location;
    }

    void setLocaition(const string& loc) {
        location = loc;
    }

    void addMenuItems(const MenuItem& item) {
        menuItems.push_back(item);
    }

    const vector<MenuItem> getMenu() {
        return menuItems;
    }
};

int Restaurant::nextRestaurantId = 0;

#endif

