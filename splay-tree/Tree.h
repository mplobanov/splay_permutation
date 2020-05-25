//
// Created by Михаил Лобанов on 22.05.2020.
//

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <iostream>
#include <cassert>

enum Direction {Left, Right, Root};
enum Most {Big, Small};

auto inv_dir = [](Direction direction) {
    return direction == Left ? Right : Left;
};

auto most_to_direction = [](Most most) {
    return most == Small ? Left : Right;
};

class Tree {
public:
    struct Node {
        // fields
        int _val;
        int _size = 1;
        Tree::Node* _left = nullptr;
        Tree::Node* _right = nullptr;
        Tree::Node* _parent = nullptr;

        // constructors-destructors
        explicit Node() = default;
        explicit Node(int val);
        Node(Tree::Node* left, int val, Tree::Node* right);


        //std in & out
        friend std::ostream & operator << (std::ostream & out, const Tree::Node & node);
//      std::string to_string(const std::string & s = "") const;
        std::string to_string() const;

        // utilties
        Direction _my_direction();

    public:
        void _rotate(Direction direction);
        void _make_me_parent();
        static Tree::Node* Tree::Node::* _get_child(Direction);
        int get_child_size(Direction direction);
    };

public:

    Tree::Node* _root = nullptr;
    //Tree::Node* min_node = nullptr;
    //Tree::Node* max_node = nullptr;

    void _splay(Tree::Node* node); // node MUST be valid (nullptr not suitable)

//  Tree::Node* _lower_bound(Tree::Node* node, int x); // returns biggest member <= x, if there is no such member, returns nullptr

    Tree::Node* _get_most(Most most); // return pointer to bi..,mggest(Big), smallest(Small) member of tree

    std::pair<Tree*, Tree*> split (int x); // splits tree. After splitting initial tree is NOT VALID any more!

    void merge(Most most, Tree & tree); // Merges a bigger (Big) or smaller(Tree) to existing tree. Old tree is not valid after merge!

    Tree::Node* _get_k(Tree::Node* node, int k); // 1-numeration

    explicit Tree(Tree::Node*);
public:
    Tree::Node* find(int x);
//    Tree::Node* lower_bound(int x);

    int size();
    void add(int x);
    void remove(int x);
    int get_k_min(int k);
    int get_k_max(int k);

    explicit Tree() = default;

    ~Tree();
    void destroy(Tree::Node* node);

    friend std::ostream & operator << (std::ostream & out, const Tree & tree);

    void move_to_start(int i, int j);
};
#endif //SPLAY_TREE_H
