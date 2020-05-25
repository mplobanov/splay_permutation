//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

void Tree::move_to_start(int i, int j) {
    if (i == 1)
        return;
    int before = i - 1;
    int amount = j - i + 1;
    auto trs1 = split(before);
    auto trs2 = trs1.second->split(amount);
    trs2.first->merge(Big, *trs1.first);
    trs2.first->merge(Big, *trs2.second);
    _root = trs2.first->_root;
}

void Tree::add(int x) {
    if (!_root) {
        _root = new Node(x);
//        max_node = _root;
//        min_node = _root;
        return;
    }
    Node* max_node = _get_most(Big);
    _splay(max_node);
    max_node->_right = new Node(x);
    max_node->_make_me_parent();
    max_node = max_node->_right;
    max_node->_make_me_parent();
}

void Tree::remove(int x) {
    assert(find(x));
    Node* node = find(x);
    _splay(node);
    Tree* tr1 = new Tree(node->_left);
    Tree* tr2 = new Tree(node->_right);
    tr1->merge(Big, *tr2);
    _root = tr1->_root;
}

