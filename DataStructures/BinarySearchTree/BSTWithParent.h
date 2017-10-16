//
//  main.cpp
//  BinarySearchTree
//
//  Created by Taras Nikulin on 09.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T value;
    
    Node *parent = NULL;
    Node *leftNode = NULL;
    Node *rightNode = NULL;
    
    Node(int val) {
        this->value = val;
    }
    
    void add(int newValue) {
        if (newValue >= this->value) {
            if (this->rightNode) {
                this->rightNode->add(newValue);
            } else {
                Node *newNode = new Node(newValue);
                newNode->parent = this;
                this->rightNode = newNode;
            }
        } else {
            if (this->leftNode) {
                this->leftNode->add(newValue);
            } else {
                Node *newNode = new Node(newValue);
                newNode->parent = this;
                this->leftNode = newNode;
            }
        }
    };
    
    bool contains(T value) {
        if (value == this->value) {
            return true;
        }
        if (value < this->value) {
            if (this->leftNode) {
                return this->leftNode->contains(value);
            } else {
                return false;
            }
        } else {
            if (this->rightNode) {
                return this->rightNode->contains(value);
            } else {
                return false;
            }
        }
    };
    
    Node *minimum() {
        if (this->leftNode) {
            return this->leftNode->minimum();
        } else {
            return this;
        }
    }
    
    Node *maximum() {
        if (this->rightNode) {
            return this->rightNode->maximum();
        } else {
            return this;
        }
    }
    
    Node *removeIfExist(T value) {
        if (this->value == value) {
            if (!this->leftNode && !this->rightNode) {
                //removing leaf
                if (this->parent->value > this->value) {
                    this->parent->leftNode = NULL;
                } else {
                    this->parent->rightNode = NULL;
                }
                this->parent = NULL;
            } else if (this->leftNode && !this->rightNode) {
                //removing node with only left child
                if (this->parent->value > this->value) {
                    this->parent->leftNode = this->leftNode;
                } else {
                    this->parent->rightNode = this->leftNode;
                }
                this->leftNode->parent = this->parent;
                this->leftNode = NULL;
                this->parent = NULL;
            } else if (!this->leftNode && this->rightNode) {
                //removing node with only right child
                if (this->parent->value > this->value) {
                    this->parent->leftNode = this->rightNode;
                } else {
                    this->parent->rightNode = this->rightNode;
                }
                this->rightNode->parent = this->parent;
                this->rightNode = NULL;
                this->parent = NULL;
            } else {
                //removing node with 2 or more children
                Node *replacementNode = this->rightNode->minimum();
                this->value = replacementNode->value;
                replacementNode->removeIfExist(replacementNode->value);
            }
            return this;
        } else {
            if (value > this->value) {
                if (this->rightNode) {
                    return this->rightNode->removeIfExist(value);
                } else {
                    return NULL;
                }
            } else {
                if (this->leftNode) {
                    return this->leftNode->removeIfExist(value);
                } else {
                    return NULL;
                }
            }
        }
    };
    
    void printInOrder() {
        if (this->leftNode != NULL) {
            this->leftNode->printInOrder();
        }
        cout << this->value << ",";
        if (this->rightNode != NULL) {
            this->rightNode->printInOrder();
        }
    };
    
    void printPreOrder() {
        cout << this->value << ",";
        if (this->leftNode != NULL) {
            this->leftNode->printPreOrder();
        }
        if (this->rightNode != NULL) {
            this->rightNode->printPreOrder();
        }
    };
    
    void printPostOrder() {
        if (this->leftNode != NULL) {
            this->leftNode->printPostOrder();
        }
        if (this->rightNode != NULL) {
            this->rightNode->printPostOrder();
        }
        cout << this->value << ",";
    };
    
    string description() {
        string s;
        if (this->leftNode != NULL) {
            s += "(" + this->leftNode->description() + " <-";
        }
        s += to_string(this->value);
        if (this->rightNode != NULL) {
            s += "-> " + this->rightNode->description() + ")";
        }
        return s;
    };
};

//int main(int argc, const char * argv[]) {
//    Node<int> rootNode = Node<int>(50);
//    
//    rootNode.add(20);
//    rootNode.add(10);
//    rootNode.add(30);
//    rootNode.add(25);
//    rootNode.add(40);
//    rootNode.add(40);
//    rootNode.add(60);
//    rootNode.add(55);
//    rootNode.add(80);
//    rootNode.add(90);
//    rootNode.add(90);
//    rootNode.add(70);
//    rootNode.add(70);
//    rootNode.add(65);
//    rootNode.add(75);
//    rootNode.add(25);
//    rootNode.add(26);
//    rootNode.add(43);
//    rootNode.add(25);
//    
//    cout << rootNode.description() << endl;
//    
//    cout << "I will print in order" << endl;
//    rootNode.printInOrder();
//    cout << endl;
//    
//    int removeValue = 26;
//    cout << "Trying to remove: " << removeValue << ". Success: " << (rootNode.removeIfExist(removeValue) != NULL) << endl;
//    
//    cout << "I will print in order" << endl;
//    rootNode.printInOrder();
//    cout << endl;
//    
//    cout << rootNode.description() << endl;
//    
//    return 0;
//}

