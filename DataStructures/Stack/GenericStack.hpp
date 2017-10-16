//
//  Stack.hpp
//  Stack
//
//  Created by Taras Nikulin on 07.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template<class Element> class Stack {
private:
    vector<Element> storage = {};
public:
    
    void push(Element element) {
        storage.push_back(element);
    }
    
    Element * pop() {
        Element *last = this->last();
        if (last) {
            storage.pop_back();
        }
        return last;
    }
    
    Element * last() {
        if (storage.empty()) {
            return nullptr;
        } else {
            return &storage.back();
        }
    }
    
    int count() {
        return int(sizeof(storage));
    }
    
    bool isEmpty() {
        return storage.empty();
    }
    
    void print() {
        cout << "Stack is: " << endl;
        for (auto item : storage) {
            cout << "\t" << item << endl;
        }
        cout << "Stack fully printed" << endl;
    }
};

#endif /* Stack_hpp */
