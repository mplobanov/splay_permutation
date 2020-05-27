//
// Created by Михаил Лобанов on 25.05.2020.
//
#include "Tree.h"

void Tree::Node::_update() {
    _size = 1;
    _sum = _val;
    _push();
    _min = _val;
    leftest = _val;
    rightest = _val;
    if (_left){
        _left->_parent = this;
        _size += _left->_size;
        _sum += _left->_sum;
        _min = std::min(_min, _left->_min);
        leftest = _left->leftest;
    }
    if (_right) {
        _right->_parent = this;
        _size += _right->_size;
        _sum += _right->_sum;
        _min = std::min(_min, _right->_min);
        rightest = _right->rightest;
    }
    incSuff = 0;
    incPref = 0;
    decSuff = 0;
    decPref = 0;
    _update(&Tree::Node::incSuff, true, true);
    _update(&Tree::Node::incPref, true, false);
    _update(&Tree::Node::decSuff, false, true);
    _update(&Tree::Node::decPref, false, false);
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
    if (reversed) {
        std::swap(_left, _right);
        std::swap(incSuff, decPref);
        std::swap(decSuff, incPref);
        std::swap(leftest, rightest);
        if (_left) {
            _left->reversed = !(_left->reversed);
        }
        if (_right) {
            _right->reversed = !(_right->reversed);
        }
        reversed = false;
    }
    if (assigned) {
        _val = assign;
        leftest = assign;
        rightest = assign;
        _sum = _size * _val;
        incPref = _size;
        decPref = _size;
        incSuff = _size;
        decSuff = _size;
        Direction dir = Left;
        Node* child = this->*(_get_child(dir));
        if (child) {
            child->assigned = true;
            child->assign = _val;
            child->delta = 0;
        }
        dir = Right;
        child = this->*(_get_child(dir));
        if (child) {
            child->assigned = true;
            child->assign = _val;
            child->delta = 0;
        }
        assigned = false;
    }
    if (delta != 0) {
        _val += delta;
        leftest += delta;
        rightest += delta;
        _sum += _size * delta;
        Direction dir = Left;
        Node* child = this->*(_get_child(dir));
        if (child) {
            child->delta += delta;
        }
        dir = Right;
        child = this->*(_get_child(dir));
        if (child) {
            child->delta += delta;
        }
        delta = 0;
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

void Tree::Node::_update(int Node::*field, bool inc, bool suff) {
    _push();
    Node* child = suff ? _right : _left;
    Node* other_child = suff ? _left : _right;
    if ((!child) || (child->*field == child->_size)) {
        if (child) {
            int val = suff ? child->leftest : child->rightest;
            if (!((inc ^ suff) ? (val <= _val) : (val >= _val))) {
                this->*field = child->*field;
                return;
            }
        }
        this->*field = 1;
        if (child)
            this->*field += child->_size;

        if (!other_child) {
            return;
        }
        int val2 = suff ? other_child->rightest : other_child->leftest;
        if ((inc ^ suff) ? (val2 >= _val) : (val2 <= _val)) {
            this->*field += other_child->*field;
        }
    }
    else {
        this->*field = child->*field;
    }
}

void Tree::_swap(Node *a, Node *b) {
    _splay(a);
    a->_right->_parent = nullptr;
    a->_right = nullptr;
    a->_update();
    _splay(b);
    Node* a_left = a->_left;
    a->_left = b->_left;
    a->_right = b->_right;
    b->_left = a_left;
    b->_right = a;
    a->_update();
    b->_update();
    _root = b;
}