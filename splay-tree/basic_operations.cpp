//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

std::pair<Tree*, Tree*> Tree::split(int x) {
    if (x == 0) {
        return {new Tree(), this};
    }
    Node* splitter = find(x);
    splitter->_push();
    Node* r_child = splitter->_right;
    if (splitter->_right ) {
        splitter->_right->_parent = nullptr;
        splitter->_right = nullptr;
    }
    splitter->_update();
    _root = splitter;
    Tree* new_tree = new Tree(r_child);
    return {this, new_tree};
}


void Tree::merge(Tree &tree, Direction direction) {
    if (!tree._root) {
//        if (abs(_root->get_child_size(Left) - _root->get_child_size(Right)) > 10) {
//            find(_root->_size / 2);
//        }
        return;
    }
    if (!_root) {
        _root = tree._root;
//        if (abs(_root->get_child_size(Left) - _root->get_child_size(Right)) > 10) {
//            find(_root->_size / 2);
//        }
        return;
    }
    _root->_push();
    if (tree._root)
        tree._root->_push();
    Node* node = _get_most(direction);
    if (node) {
        _splay(node);
        Node* & child = _root->*Tree::Node::_get_child(direction);
        assert(child == nullptr);
        child = tree._root;
        _root->_update();
    }
    else {
        _root = tree._root;
    }
//    if (abs(_root->get_child_size(Left) - _root->get_child_size(Right)) > 10) {
//        find(_root->_size / 2);
//    }
}

Tree::Node* Tree::_node_merge(Tree::Node *node1, Tree::Node *node2) {
    if (!node1)
        return node2;
    if (!node2)
        return node1;
    node1->_push();
    node2->_push();
    node1 = find(node1->_size, node1);
    node1->_right = node2;
    node1->_update();
    return node1;
}


