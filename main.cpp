#include <fstream>
#include "splay-tree/Tree.h"
#include <algorithm>

using namespace std;
using Nd = Tree::Node;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    long long n;
//    cin >> n;
//    Tree tree;
//    for (long long i = 1; i < n + 1; ++i) {
//        long long x;
//        cin >> x;
//        tree.push_back(x);
//    }
//    long long q;
//    cin >> q;
//    long long type, x, l, r, pos;
//    for (long long k = 0; k < q; ++k) {
//        cin >> type;
//        if (type == 1) {
//            cin >> l >> r;
//            cout << tree.sum_subsegment(l + 1, r + 1) << "\n";
//        }
//        else if (type == 2) {
//            cin >> x >> pos;
//            tree.insert_before(x, pos + 1);
//        }
//        else if (type == 3) {
//            cin >> pos;
//            tree.pop(pos + 1);
//        }
//        else if (type == 4) {
//            cin >> x >> l >> r;
//            tree.assign(l + 1, r + 1, x);
//        }
//        else if (type == 5) {
//            cin >> x >> l >> r;
//            tree.add_delta(l + 1, r + 1, x);
//        }
//        else if ((type == 6) || (type == 7)) {
//            cin >> l >> r;
//            tree.permutation(l + 1, r + 1, (type == 6));
//        }
//    }
//    cout << tree << "\n";
    Tree tree1;
    for(int x : {1, 2,3 ,4 })
        tree1.push_back(x);
    Tree tree2;
    for(int y : {6,7,8,9})
        tree2.push_back(y);
    Tree::Node* tr = tree1._node_merge(tree1._root, tree2._root);
    cout << *tr;
    return 0;
}
