//
// Created by Михаил Лобанов on 25.05.2020.
//

#include "Tree.h"

std::ostream & operator<<(std::ostream &out, const Tree::Node & node) {
    std::string s = node.to_string();
    out << s.substr(1, s.length() - 1);
    return out;
}

//std::string Tree::Node::to_string(const std::string & tabs) const {
//    std::string s;
//    s += tabs + std::to_string(_val) + " (sz" + std::to_string(_size) + ")\n";
//    if (_left) {
//        s += tabs + "left\n";
//        s += _left->to_string(tabs + "\t");
//    }
//    if (_right) {
//        s += tabs + "right\n";
//        s += _right->to_string(tabs + "\t");
//    }
//    return s;
//}

std::string Tree::Node::to_string() const {
    std::string ans;
    if (_left)
        ans += _left->to_string();
    ans += " " + std::to_string(_val);
    if (_right)
        ans += _right->to_string();
    return ans;
}

std::ostream & operator<<(std::ostream &out, const Tree & tree) {
    if (tree._root) {
        out << *tree._root;
    }
    else {
        out << "Empty tree (sz 0)\n";
    }
    return out;
}