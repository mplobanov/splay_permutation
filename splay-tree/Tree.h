#include <climits>
//
// Created by Михаил Лобанов on 22.05.2020.
//

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <functional>
#include <iostream>
#include <cassert>
#include <vector>

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
        bool reversed = false;
        void _push();

        int incSuff = 0;
        int incPref = 0;
        int decSuff = 0;
        int decPref = 0;

        int leftest = 0;
        int rightest = 0;

        explicit Node() = default;
        explicit Node(int val);

        Node(Tree::Node* left, int val, Tree::Node* right);

        friend std::ostream & operator << (std::ostream & out, Tree::Node & node);
        std::string to_string();

        Direction _my_direction();

    public:
        void _rotate(Direction direction);
        void _update();
        void _update(int Tree::Node::* field, bool inc, bool suff);
        static Tree::Node* Tree::Node::* _get_child(Direction);
        int get_child_size(Direction direction);
    };

public:

    Tree::Node* get_most(Tree::Node* node, Direction direction);

    Tree::Node* _root = nullptr;

    void _splay(Tree::Node* node);

    Node * _get_most(Direction direction = Right); // return pointer to bi..,mggest(Big), smallest(Small) member of tree

    std::pair<Tree*, Tree*> split (int i); // i'th element and before in one tree, rest in another

    void merge(Tree &tree, Direction direction = Right); // Merges a bigger (Big) or smaller(Tree) to existing tree. Old tree is not valid after merge!
    Tree::Node* _node_merge(Tree::Node* node1, Tree::Node* node2);

    Tree::Node* find(int i, Tree::Node* node = nullptr); // 1-numeration

    explicit Tree(Tree::Node*);

    std::tuple<Tree*, Tree*, Tree*> get_subsegemnt(int l, int r);
    void merge_subsegments(Tree* n2, Tree* n3);

    void _make_changes(int l, int r, std::function<void(Tree *)> tree);

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
    void permutation(int l, int r, bool next);
    Node* find_big_sm(int x, bool big = true);
    void _swap(Node* a, Node* b);



    explicit Tree() = default;
    ~Tree();
    void destroy(Tree::Node* node);

    friend std::ostream & operator << (std::ostream & out, const Tree & tree);
};


#endif //SPLAY_TREE_H
