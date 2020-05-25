//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

Tree::Node::Node(int val) : _val(val) {}

Tree::Node::Node(Node *left, int val, Node *right) : _left(left), _val(val), _right(right) {
    _make_me_parent();
}

Tree::Tree(Node * node) : _root(node) {
    if (_root) {
        _root->_parent = nullptr;
    }
}

void Tree::destroy(Tree::Node *node) {
    if (node) {
        destroy(node->_left);
        destroy(node->_right);
        delete node;
    }
}

Tree::~Tree() {
    destroy(_root);
}
