//
// Created by Михаил Лобанов on 25.05.2020.
//

#include "Tree.h"

std::ostream & operator<<(std::ostream &out, Tree::Node & node) {
    std::string s = node.to_string();
    out << s.substr(1, s.length() - 1);
    return out;
}

std::string Tree::Node::to_string() {
    std::string ans;
    _push();
    if (_left)
        ans += _left->to_string();
    ans += " " + std::to_string(_val);
    if (_right)
        ans += _right->to_string();
    return ans;
}

std::ostream & operator<<(std::ostream &out, const Tree & tree) {
    if (tree._root) {
        std::string s = tree._root->to_string();
        out << s.substr(1, s.length() - 1);
    }
    else {
        out << "Empty tree (sz 0)";
    }
    return out;
}