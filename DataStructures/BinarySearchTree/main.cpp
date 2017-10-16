//
//  main.cpp
//  BinarySearchTree
//
//  Created by Taras Nikulin on 09.10.2017.
//  Copyright © 2017 Taras Nikulin. All rights reserved.
//

#include <iostream>
#include <string>
#include "BSTWithoutParent.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Tree<int> rootTree = Tree<int>(10);
    
    rootTree.add(15);
    rootTree.add(12);
    rootTree.add(25);
    rootTree.add(5);
    rootTree.add(3);
    
    rootTree.printInOrder();
    cout << endl;
    
    int pointValue = 25;
    cout << "Predecessor for: " << pointValue << " is "  << rootTree.getPredecessodFor(pointValue) << endl;
    cout << "Successor for: " << pointValue << " is " << rootTree.getSuccessorFor(pointValue) << endl;
    
    cout << "Height is: " << rootTree.height() << endl;
    
    cout << "BFS: ";
    rootTree.printBFS();
    cout << endl;
    cout << "DFS: ";
    rootTree.printDFS();
    cout << endl;
    
    Tree<int> *removedTree = rootTree.remove(10, NULL);
    delete removedTree;
    
    rootTree.printInOrder();
    cout << endl;
    
    return 0;
}

