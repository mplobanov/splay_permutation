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
    if (!tree._root)
        return;
    if (!_root) {
        _root = tree._root;
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
}
