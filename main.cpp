#include <fstream>
#include "splay-tree/Tree.h"
#include <algorithm>

using namespace std;
using Nd = Tree::Node;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Tree tree;
    for (int i = 1; i < n + 1; ++i) {
        int x;
        cin >> x;
        tree.push_back(x);
        if (i % 1000 == 0)
            tree.find(i / 2);
    }
    int q;
    cin >> q;
    int type, x, l, r, pos;
    for (int k = 0; k < q; ++k) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            cout << tree.sum_subsegment(l + 1, r + 1) << "\n";
        }
        else if (type == 2) {
            cin >> x >> pos;
            tree.insert_before(x, pos + 1);
        }
        else if (type == 3) {
            cin >> pos;
            tree.pop(pos + 1);
        }
        else if (type == 4) {
            cin >> x >> l >> r;
            tree.assign(l + 1, r + 1, x);
        }
        else if (type == 5) {
            cin >> x >> l >> r;
            tree.add_delta(l + 1, r + 1, x);
        }
        else if ((type == 6) || (type == 7)) {
            cin >> l >> r;
            tree.permutation(l + 1, r + 1, (type == 6));
        }
    }
    cout << tree << "\n";
    return 0;
}
