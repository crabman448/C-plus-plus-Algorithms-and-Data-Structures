//
//  BSTWithoutParent.h
//  BinarySearchTree
//
//  Created by Taras Nikulin on 12.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;

#ifndef BSTWithoutParent_h
#define BSTWithoutParent_h

template <class T>
class Tree {
    T value;
    Tree *left = NULL;
    Tree *right = NULL;
public:
    Tree(T value) {
        this->value = value;
    };
    
    void add(T newValue) {
        if (newValue >= this->value) {
            this->right ? this->right->add(newValue) : void(this->right = new Tree<T>(newValue));
        } else {
            this->left ? this->left->add(newValue) : void(this->left = new Tree<T>(newValue));
        }
    };
    
    Tree* getTreeWith(T value) {
        if (this->value == value) {
            return this;
        }
        if (value >= this->value) {
            return this->right ? this->right->getTreeWith(value) : NULL;
        } else {
            return this->left ? this->left->getTreeWith(value) : NULL;
        }
    };
    
    Tree *remove(T value, Tree<T> *parent) {
        if (this->value == value) {
            if (!this->left && !this->right) {
                //no children
                (parent->left == this) ? parent->left = NULL : parent->right = NULL;
                return this;
            } else if (this->left && !this->right) {
                //only left exist
                (parent->left == this) ? parent->left = this->left : parent->right = this->left;
                return this;
            } else if (!this->left && this->right) {
                //only right exist
                (parent->left == this) ? parent->left = this->right : parent->right = this->right;
                return this;
            } else {
                //2 children
                T minimum = this->right->minimum();
                this->value = minimum;
                return this->right->remove(minimum, this);
            }
        } else {
            if (value >= this->value) {
                return this->right ? this->right->remove(value, this) : NULL;
            } else {
                return this->left ? this->left->remove(value, this) : NULL;
            }
        }
    };
    
    T minimum() {
        return this->left ? this->left->minimum() : this->value;
    };
    
    T maximum() {
        return this->right ? this->right->maximum() : this->value;
    };
    
    void printInOrder() {
        this->left ? this->left->printInOrder() : void();
        cout << this->value << ", ";
        this->right ? this->right->printInOrder() : void();
    };
    
    void printPreOrder() {
        cout << this->value << ", ";
        this->left ? this->left->printInOrder() : void();
        this->right ? this->right->printInOrder() : void();
    };
    
    void printPostOrder() {
        this->left ? this->left->printInOrder() : void();
        this->right ? this->right->printInOrder() : void();
        cout << this->value << ", ";
    };
    
    T getSuccessorFor(T value) {
        Tree* wantedTree = this->getTreeWith(value);
        if (!wantedTree) {
            return 0;
        }
        if (wantedTree->right) {
            return wantedTree->right->minimum();
        } else {
            Tree *preAncestor = NULL;
            Tree *ancestor = this;
            while (ancestor->value != value) {
                if (ancestor->value > value) {
                    preAncestor = ancestor;
                    ancestor = ancestor->left;
                } else {
                    ancestor = ancestor->right;
                }
            }
            return preAncestor ? preAncestor->value : 0;
        }
    };
    
    T getPredecessodFor(T value) {
        Tree* wantedTree = this->getTreeWith(value);
        if (!wantedTree) {
            return 0;
        }
        if (wantedTree->left) {
            return wantedTree->left->maximum();
        } else {
            Tree *preAncestor = NULL;
            Tree *ancestor = this;
            while (ancestor->value < value) {
                if (ancestor->value < value) {
                    preAncestor = ancestor;
                    ancestor = ancestor->right;
                } else {
                    ancestor = ancestor->left;
                }
            }
            return preAncestor ? preAncestor->value : 0;
        }
    };
    
    int height() {
        return (this == NULL) ? -1 : max(this->left->height(), this->right->height()) + 1;
    };
    
    void printBFS() {
        list<Tree<T> *> queue;
        queue.push_back(this);
        while (!queue.empty()) {
            cout << queue.front()->value << ", ";
            queue.front()->left ? queue.push_back(queue.front()->left) : void();
            queue.front()->right ? queue.push_back(queue.front()->right) : void();
            queue.pop_front();
        }
    };
    
    void printDFS() {
        stack<Tree<T> *> stack;
        stack.push(this);
        while (!stack.empty()) {
            cout << stack.top()->value << ", ";
            Tree<T> *right = stack.top()->right;
            Tree<T> *left = stack.top()->left;
            stack.pop();
            right ? stack.push(right) : void();
            left ? stack.push(left) : void();
        }
    };
};

#endif /* BSTWithoutParent_h */
