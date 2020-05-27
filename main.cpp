#include <fstream>
#include "splay-tree/Tree.h"

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
