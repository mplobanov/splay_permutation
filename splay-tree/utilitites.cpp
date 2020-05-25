//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

void Tree::Node::_make_me_parent() {
    _size = 1;
    if (_left){
        _left->_parent = this;
        _size += _left->_size;
    }
    if (_right) {
        _right->_parent = this;
        _size += _right->_size;
    }
}

Direction Tree::Node::_my_direction() {
    if (_parent) {
        return (_parent->_left == this) ? Left : Right;
    }
    else {
        return Root;
    }
}

int Tree::Node::get_child_size(Direction direction) {
    if (this->*_get_child(direction)) {
        return (this->*_get_child(direction))->_size;
    }
    else {
        return 0;
    }
}

int Tree::size() {
    if (_root)
        return _root->_size;
    return 0;
}
