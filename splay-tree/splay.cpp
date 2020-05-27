//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

Tree::Node* Tree::Node::* Tree::Node::_get_child(Direction direction) {
    return direction == Left ? &Tree::Node::_left : &Tree::Node::_right;
}

void Tree::Node::_rotate(Direction direction) {
    auto w_d = !direction; // working direction
    assert(this->*_get_child(w_d));
    Node* son = this->*_get_child(w_d);
    Node* grandson = son->*(son->_get_child(!w_d));
    Node* dad = _parent;
    if (dad)
        dad->_push();
    _push();
    son->_push();
    if (grandson)
        grandson->_push();
    son->*_get_child(!w_d) = this;
    this->*_get_child(w_d) = grandson;
    if (dad) {
        dad->*dad->_get_child(this->_my_direction()) = son;
    }
    _update();
    son->_update();
    if (dad) {
        dad->_update();
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