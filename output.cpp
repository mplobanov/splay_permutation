// This file is autogenerated by the script
// It contains all source and headers files from the project
// without unnecessary `#include` and `#pragma` directives
// Special for Y.Contest



#include <climits>
#include <functional>
#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/Tree.h BEGINS HERE
//----------------------------------------------------------------------------------------------------
//
// Created by Михаил Лобанов on 22.05.2020.
//



enum Direction {Left, Right, Root};

Direction operator!(const Direction & direction);

class Tree {
public:
    struct Node {
        int _val = 0;
        int _size = 1;
        Tree::Node* _left = nullptr;
        Tree::Node* _right = nullptr;
        Tree::Node* _parent = nullptr;

        int _sum = 0;
        int _min = 0;
        int assign = 0;
        bool assigned = false;
        int delta = 0;
        bool reversed;
        void _push();

        explicit Node() = default;
        explicit Node(int val);

        Node(Tree::Node* left, int val, Tree::Node* right);

        friend std::ostream & operator << (std::ostream & out, Tree::Node & node);
        std::string to_string();

        Direction _my_direction();

    public:
        void _rotate(Direction direction);
        void _update();
        static Tree::Node* Tree::Node::* _get_child(Direction);
        int get_child_size(Direction direction);
    };

public:

    Tree::Node* _root = nullptr;

    void _splay(Tree::Node* node);

    Tree::Node *_get_most(Direction direction = Right) const; // return pointer to bi..,mggest(Big), smallest(Small) member of tree

    std::pair<Tree*, Tree*> split (int i); // i'th element and before in one tree, rest in another

    void merge(Tree &tree, Direction direction = Right); // Merges a bigger (Big) or smaller(Tree) to existing tree. Old tree is not valid after merge!

    Tree::Node* find(int i, Tree::Node* node = nullptr); // 1-numeration

    explicit Tree(Tree::Node*);

    std::tuple<Tree*, Tree*, Tree*> get_subsegemnt(int l, int r);
    void merge_subsegments(Tree* n2, Tree* n3);

    void _make_changes(int l, int r, std::function<void(Tree*)>);

public:
    int size() const;
    void push_back(int x);
    void pop(int x);
    void insert_before(int x, int i);
    int sum_subsegment(int l, int r);
    int min_subsegment(int l, int r);
    void assign(int l, int r, int x);
    void add_delta(int l, int r, int x);
    void reverse(int l, int r);

    explicit Tree() = default;
    ~Tree();
    void destroy(Tree::Node* node);

    friend std::ostream & operator << (std::ostream & out, const Tree & tree);
};



//----------------------------------------------------------------------------------------------------
// FILE splay-tree/Tree.h ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/construct.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------

//
// Created by Михаил Лобанов on 25.05.2020.
//

Tree::Node::Node(int val) : _val(val) {}

Tree::Node::Node(Node *left, int val, Node *right) : _left(left), _val(val), _right(right) {
    _update();
}

Tree::Tree(Node * node) : _root(node) {
    if (_root) {
        _root->_parent = nullptr;
    }
}

void Tree::destroy(Tree::Node *node) {
    if (node) {
        destroy(node->_left);
        destroy(node->_right);
        delete node;
    }
}

Tree::~Tree() {
    destroy(_root);
}

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/construct.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/std_in_out.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------
//
// Created by Михаил Лобанов on 25.05.2020.
//


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
//----------------------------------------------------------------------------------------------------
// FILE splay-tree/std_in_out.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/splay.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------
//
// Created by Михаил Лобанов on 25.05.2020.
//

Tree::Node* Tree::Node::* Tree::Node::_get_child(Direction direction) {
    return direction == Left ? &Tree::Node::_left : &Tree::Node::_right;
}

void Tree::Node::_rotate(Direction direction) {
    auto w_d = !direction; // working direction
    assert(this->*_get_child(w_d));
    Node* son = this->*_get_child(w_d);
    Node* grandson = son->*(son->_get_child(!w_d));
    Node* dad = _parent;
    if (dad)
        dad->_push();
    _push();
    son->_push();
    if (grandson)
        grandson->_push();
    son->*_get_child(!w_d) = this;
    this->*_get_child(w_d) = grandson;
    if (dad) {
        dad->*dad->_get_child(this->_my_direction()) = son;
    }
    _update();
    son->_update();
    if (dad) {
        dad->_update();
    }
    else {
        son->_parent = nullptr;
    }
}

void Tree::_splay(Node *node) {
    assert(node);
    while (node->_parent) {
        if (node->_parent->_left == node) {
            node->_parent->_rotate(Right);
        }
        else {
            node->_parent->_rotate(Left);
        }
    }
    _root = node;
}
//----------------------------------------------------------------------------------------------------
// FILE splay-tree/splay.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/utilitites.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------
//
// Created by Михаил Лобанов on 25.05.2020.
//

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
//----------------------------------------------------------------------------------------------------
// FILE splay-tree/utilitites.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/find.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------
//
// Created by Михаил Лобанов on 25.05.2020.
//

Tree::Node * Tree::_get_most(Direction direction) const {
    Node* node = _root;
    if (!node)
        return node;
    while (true) {
        node->_push();
        if (node->*(Tree::Node::_get_child(direction)))
            node = node->*(Tree::Node::_get_child(direction));
        else
            return node;
    }
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
//----------------------------------------------------------------------------------------------------
// FILE splay-tree/find.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/basic_operations.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------
//
// Created by Михаил Лобанов on 25.05.2020.
//

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

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/basic_operations.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE splay-tree/operations.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------
//
// Created by Михаил Лобанов on 25.05.2020.
//

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



//----------------------------------------------------------------------------------------------------
// FILE splay-tree/operations.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// FILE main.cpp BEGINS HERE
//----------------------------------------------------------------------------------------------------

using namespace std;
using Nd = Tree::Node;

int main() {
    int n;
    Tree tree;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (s == "+") {
            tree.insert_before(b, a + 1);
        }
        if (s == "?") {
            cout << tree.min_subsegment(a, b) << endl;
        }
    }
}

//----------------------------------------------------------------------------------------------------
// FILE main.cpp ENDS HERE
//----------------------------------------------------------------------------------------------------

// Generated by the script
