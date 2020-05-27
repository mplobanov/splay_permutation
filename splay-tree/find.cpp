//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

Tree::Node * Tree::_get_most(Direction direction) {
    return get_most(_root, direction);
}

Tree::Node* Tree::find(int i, Tree::Node* node) {
    if (node == nullptr) {
        node = _root;
    }
    assert(node->_size >= i);
    node->_push();
    while (i != node->get_child_size(Left) + 1) {
        if (i < node->get_child_size(Left) + 1) {
            node = node->_left;
        }
        else {
            i -= node->get_child_size(Left) + 1;
            node = node->_right;
        }
        node->_push();
    }
    _splay(node);
    return node;
}

//Tree::Node* Tree::find(int i, Tree::Node *node) {
//    --i;
//    if (!node) {
//        return nullptr;
//    }
//    node->_push();
//    Node* res;
//    int cur_ind = node->get_child_size(Left);
//    if (cur_ind == i) {
//        res = node;
//        _splay(node);
//    }
//    else if (i < cur_ind && node->_left) {
//        res = find(i, node->_left);
//    }
//    else if (i > cur_ind && node->_right) {
//        res = find(i - cur_ind - 1, node->_right);
//    }
//    else {
//        res = node;
//        _splay(node);
//    }
//    return res;
//}

Tree::Node * Tree::get_most(Tree::Node* node, Direction direction) {
    if (!node)
        return node;
    while (true) {
        node->_push();
        if (node->*(Tree::Node::_get_child(direction)))
            node = node->*(Tree::Node::_get_child(direction));
        else {
            _splay(node);
            return node;
        }

    }
}

Tree::Node * Tree::find_big_sm(int x, bool big) {
    Node* node = _root;
    Node* ans = nullptr;
    while (node) {
        if (big ? (node->_val <= x) : (node->_val >= x)) {
            node = node->_left;
        }
        else {
            ans = node;
            node = node->_right;
        }
    }
    _splay(ans);
    return ans;
}