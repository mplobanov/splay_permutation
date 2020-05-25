//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

std::pair<Tree*, Tree*> Tree::split(int x) {
    if (x == 0) {
        return {new Tree(), this};
    }
    Node* splitter = find(x);
    Node* r_child = splitter->_right;
    if (splitter->_right ) {
        splitter->_right->_parent = nullptr;
        splitter->_right = nullptr;
    }
    splitter->_make_me_parent();
    Tree* new_tree = new Tree(r_child);
//    if (new_tree->_root) {
//        new_tree->max_node = max_node;
//        Node * node = new_tree->_root;
//        while (node->_left)
//            node = node->_left;
//        new_tree->min_node = node;
//    }
//    max_node = _root;
    return {this, new_tree};
}

void Tree::merge(Most most, Tree &tree) {
    Node* node = _get_most(most);
    if (node) {
        _splay(node);
        Node* & child = _root->*Tree::Node::_get_child(most_to_direction(most));
        assert(child == nullptr);
        child = tree._root;
        _root->_make_me_parent();
//        if (tree._root) {
//            if (most == Big) {
//                max_node = tree.max_node;
//            }
//            else {
//                min_node = tree.min_node;
//            }
//        }
    }
    else {
        _root = tree._root;
    }
}
