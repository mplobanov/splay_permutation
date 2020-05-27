//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

void Tree::Node::_update() {
    _size = 1;
    _sum = _val;
    _push();
    _min = _val;
    if (_left){
        _left->_parent = this;
        _size += _left->_size;
        _sum += _left->_sum;
        _min = std::min(_min, _left->_min);
    }
    if (_right) {
        _right->_parent = this;
        _size += _right->_size;
        _sum += _right->_sum;
        _min = std::min(_min, _right->_min);
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
    if (this->*(_get_child(direction))) {
        return (this->*(_get_child(direction)))->_size;
    }
    else {
        return 0;
    }
}

int Tree::size() const {
    if (_root)
        return _root->_size;
    return 0;
}

Direction operator!(const Direction & direction) {
    if (direction == Root)
        return Root;
    if (direction == Left)
        return Right;
    else
        return Left;
}

void Tree::Node::_push() {
    Node* node = this;
    if (node->reversed) {
        std::swap(node->_left, node->_right);
        if (node->_left) {
            node->_left->reversed = !(node->_left->reversed);
        }
        if (node->_right) {
            node->_right->reversed = !(node->_right->reversed);
        }
        node->reversed = false;
    }
    if (node->assigned) {
        node->_val = node->assign;
        node->_sum = node->_size * node->_val;
        for(Direction dir : std::vector<Direction>({Left, Right})) {
            Node* child = node->*(Tree::Node::_get_child(dir));
            if (child) {
                child->assigned = true;
                child->assign = node->_val;
                child->delta = 0;
            }
        }
        node->assigned = false;
    }
    if (node->delta != 0) {
        node->_val += node->delta;
        node->_sum += node->_size * node->delta;
        for (Direction dir: std::vector<Direction>({Left, Right})) {
            Node* child = node->*(Tree::Node::_get_child(dir));
            if (child) {
                child->delta += node->delta;
            }
        }
        node->delta = 0;
    }
}

std::tuple<Tree *, Tree *, Tree *> Tree::get_subsegemnt(int l, int r) {
    auto [tr1, tr2] = split(l - 1);
    auto [tr2_1, tr2_2] = tr2->split(r - l + 1);
    return {tr1, tr2_1, tr2_2};
}

void Tree::merge_subsegments(Tree *n2, Tree *n3) {
    Tree* n1 = this;
    n1->merge(*n2);
    n1->merge(*n3);
}

void Tree::_make_changes(int l, int r, std::function<void(Tree *)> f) {
    auto [a, b, c] = get_subsegemnt(l, r);
    f(b);
    a->merge_subsegments(b, c);
    _root = a->_root;
}