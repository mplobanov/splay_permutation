//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

void Tree::push_back(int x) {
    if (!_root) {
        _root = new Node(x);
        return;
    }
    Node* max_node = _get_most(Right);
    _splay(max_node);
    max_node->_right = new Node(x);
    max_node->_update();
    max_node = max_node->_right;
    max_node->_update();
}

void Tree::pop(int i) {
    assert(find(i));
    Node* node = find(i);
    _splay(node);
    Tree* tr1 = new Tree(node->_left);
    Tree* tr2 = new Tree(node->_right);
    tr1->merge(*tr2, Right);
    _root = tr1->_root;
}

void Tree::insert_before(int x, int i) {
    if (i > size()) {
        push_back(x);
        return;
    }
    auto trs = split(i - 1);
    Tree* new_tree = new Tree(new Node(x));
    trs.first->merge(*new_tree);
    trs.first->merge(*trs.second);
    _root = trs.first->_root;
}

int Tree::sum_subsegment(int l, int r) {
    auto [a, b, c] = get_subsegemnt(l, r);
    int sum = b->_root->_sum;
    a->merge_subsegments(b, c);
    _root = a->_root;
    return sum;
}

int Tree::min_subsegment(int l, int r) {
    auto [a, b, c] = get_subsegemnt(l, r);
    int sum = b->_root->_min;
    a->merge_subsegments(b, c);
    _root = a->_root;
    return sum;
}

void Tree::assign(int l, int r, int x) {
    _make_changes(l, r, [x](Tree* node) {
        node->_root->assign = x;
        node->_root->assigned = true;
        node->_root->_push();
    });
}

void Tree::add_delta(int l, int r, int x) {
    _make_changes(l, r, [x](Tree* node) {
        node->_root->delta = x;
        node->_root->_push();
    });
}

void Tree::reverse(int l, int r) {
    _make_changes(l, r, [](Tree* node) {
        node->_root->reversed = true;
        node->_root->_push();
    });
}


