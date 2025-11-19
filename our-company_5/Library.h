#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Publication.h"
using namespace std;

class Library
{
    string name;
    vector<Publication*> items;

public:
    Library(string n) : name(n) {}

    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    void add(Publication* p) {
        items.push_back(p);
    }

    void show() {
        cout << "=== Бібліотека: " << name << " ===\n";
        for (auto p : items) p->Description();
    }

    void find(const string& text) {
        cout << "\nПошук: " << text << "\n";
        for (auto p : items) {
            if (p->getName() == text) p->Description();
        }
    }

    void remove(const string& text) {

        items.erase(remove_if(items.begin(), items.end(),//

            [&](Publication* p) { return p->getName() == text; }), items.end());
    }
};