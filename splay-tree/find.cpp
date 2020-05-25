//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

Tree::Node* Tree::find(int x) {
    Node* node = _root;
    return _get_k(node, x);
}

Tree::Node * Tree::_get_most(Most most) {
//    if (_root) {
//        return most == Big ? max_node : min_node;
//    }
    Node* node = _root;
    while (node->*(node->_get_child(most_to_direction(most)))) {
        node = node->*(node->_get_child(most_to_direction(most)));
    }
    return node;
    return nullptr;
}

Tree::Node* Tree::_get_k(Tree::Node *node, int k) {
    assert(node->_size >= k);
    while (k != node->get_child_size(Left) + 1) {
        if (k < node->get_child_size(Left) + 1) {
            node = node->_left;
        }
        else {
            k -= node->get_child_size(Left) + 1;
            node = node->_right;
        }
    }
    _splay(node);
    return node;
}

//int Tree::get_k_min(int k) {
//    k--;
//    assert(_root->_size > k);
//    return _get_k(_root, k);
//}

//int Tree::get_k_max(int k) {
//    return get_k_min(_root->_size - (k - 1));
//}

//Tree::Node * Tree::lower_bound(int x) {
//    if (find(x)) {
//        return find(x);
//    }
//    Node* ans =  _lower_bound(_root, x);
//    if (ans) {
//        _splay(ans);
//    }
//    return ans;
//}

//Tree::Node * Tree::_lower_bound(Node * node, int x) {
//    if (node == nullptr)
//        return nullptr;
//    if (node->_val > x) {
//        return _lower_bound(node->_left, x);
//    }
//    else {
//        Node* ans = _lower_bound(node->_right, x);
//        if (ans) {
//            return ans;
//        }
//        return node;
//    }
//}
