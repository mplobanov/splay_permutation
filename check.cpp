//
// Created by Михаил Лобанов on 25.05.2020.
//
#include <iostream>
#include <cassert>
#include "splay-tree/Tree.h"

using Nd = Tree::Node;
using namespace std;

int main(){
    Tree* tree;
    for (int i = 0; i < 10; ++i) {
        tree->add(i);
    }
    cout << *tree << endl;
    tree->move_to_start(2, 3);
    cout << *tree << endl;
    return 0;
}