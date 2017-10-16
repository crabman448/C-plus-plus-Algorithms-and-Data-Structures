//
//  main.cpp
//  LinkedList
//
//  Created by Taras Nikulin on 11.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
class LinkedList {
    template <class Type>
    struct Node {
        Node *nextNode;
        Type value;
        
        Node(Type newValue) {
            value = newValue;
        }
        
        Node *addNodeWith(Type newValue) {
            if (this->nextNode) {
                return this->nextNode->addNodeWith(newValue);
            } else {
                this->nextNode = new Node<Type>(newValue);
                return this->nextNode;
            }
        };
        
        Node *remove(Node *parent, Type valueToRemove) {
            if (this->value == valueToRemove) {
                parent->nextNode = this->nextNode;
                return this;
            }
            if (this->nextNode) {
                return this->nextNode->remove(this, valueToRemove);
            } else {
                return NULL;
            }
        };
        
        void print() {
            cout << "(" << value << ")" << "->";
            if (this->nextNode) {
                this->nextNode->print();
            } else {
                cout << "END";
            }
        }
        
        void changeNext(Node<T> newNext) {
            this->nextNode = newNext;
        };
    };
public:
    Node<T> *rootNode = NULL;
    Node<T> *tailNode = NULL;
    
    LinkedList(T newValue) {
        this->rootNode = this->tailNode = new Node<T>(newValue);
    };
    
    void print() {
        rootNode->print();
    }
    
    void addNodeAtTheBeginning(T newValue) {
        Node<T> *newNode = new Node<T>(newValue);
        newNode->nextNode = this->rootNode;
        this->rootNode = newNode;
    };
    
    void addNodeAtTheEnd(T newValue) {
        Node<T> *newNode = new Node<T>(newValue);
        this->tailNode->nextNode = newNode;
        this->tailNode = newNode;
    };
    
    void remove(T valueToRemove) {
        Node<T> *removedNode = rootNode->remove(NULL, valueToRemove);
        if (removedNode) {
            delete removedNode;
        }
    };
    
    void reverse(Node<T> *parent, Node<T> *current) {
        if (current == NULL) {
            this->rootNode = parent;
            return;
        }
        this->reverse(current, current->nextNode);
        current->nextNode = parent;
        this->tailNode = current;
    };
};

int main(int argc, const char * argv[]) {
    LinkedList<int> list = LinkedList<int>(10);
    
    list.addNodeAtTheBeginning(5);
    list.addNodeAtTheBeginning(0);
    list.addNodeAtTheEnd(15);
    list.addNodeAtTheEnd(40);
    list.addNodeAtTheBeginning(-10);
    
    cout << "Linked list is:\n";
    list.print();
    cout << "\n";
    
    list.remove(15);
    
    cout << "Linked list is:\n";
    list.print();
    cout << "\n";
    
    list.reverse(NULL, list.rootNode);
    
    cout << "Linked list is:\n";
    list.print();
    cout << "\n";
    
    return 0;
}
