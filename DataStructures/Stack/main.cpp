//
//  main.cpp
//  Stack
//
//  Created by Taras Nikulin on 07.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#include <iostream>
#include "GenericStack.hpp"
#include "Person.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Stack<Person> stack = Stack<Person>();
    stack.push({"Ivan", "Ivanov"});
    stack.push({"Petr", "Petvov"});
    
    Person *poppedPerson = stack.pop();
    cout << "PoppedPerson: " << poppedPerson << endl;
    cout << "PoppedPerson: " << *poppedPerson << endl << endl;
    
    stack.push({"Nikolay", "Sidorov"});
    stack.pop();
    stack.push({"Taras", "Nikulin"});
    stack.push({"Daria", "Nikulina"});
    stack.print();
    
    Person *lastPerson = stack.last();
    cout << endl << "LastPerson: " << lastPerson << endl;
    cout << "LastPerson: " << *lastPerson << endl << endl;
    
    Stack<int> stackInt = Stack<int>();
    stackInt.push(5);
    stackInt.pop();
    stackInt.push(10);
    stackInt.push(15);
    stackInt.print();
    
    cout << stackInt.pop() << endl;
    cout << stackInt.pop() << endl;
    cout << stackInt.pop() << endl;
    cout << stackInt.pop() << endl;
    cout << stackInt.pop() << endl;
    cout << stackInt.pop() << endl;
    
    return 0;
}
