//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

Tree::Node* Tree::Node::* Tree::Node::_get_child(Direction direction) {
    return direction == Left ? &Tree::Node::_left : &Tree::Node::_right;
}

void Tree::Node::_rotate(Direction direction) {
    auto w_d = inv_dir(direction); // working direction
    assert(this->*_get_child(w_d));
    Node* son = this->*_get_child(w_d);
    Node* grandson = son->*(son->_get_child(inv_dir(w_d)));
    Node* dad = _parent;
    son->*_get_child(inv_dir(w_d)) = this;
    this->*_get_child(w_d) = grandson;
    if (dad) {
        dad->*dad->_get_child(this->_my_direction()) = son;
    }
    _make_me_parent();
    son->_make_me_parent();
    if (dad) {
        dad->_make_me_parent();
    }
    else {
        son->_parent = nullptr;
    }
}

void Tree::_splay(Node *node) {
    assert(node);
    while (node->_parent) {
        if (node->_parent->_left == node) {
            node->_parent->_rotate(Right);
        }
        else {
            node->_parent->_rotate(Left);
        }
    }
    _root = node;
}