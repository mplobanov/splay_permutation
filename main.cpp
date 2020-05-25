#include <fstream>
#include "splay-tree/Tree.h"

using namespace std;
using Nd = Tree::Node;


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //ifstream fin("../test.txt");
    ifstream fin("g.in");
    ofstream fout("g.out");
    int n, m;
    fin >> n >> m;
    Tree tree;
    for (int i = 0; i < n; ++i) {
        tree.add(i + 1);
    }
    tree.find(n / 2);
    for (int j = 0; j < m; ++j) {
        int x, y;
        fin >> x >> y;
        tree.move_to_start(x, y);
        tree.find(n / 2);
    }
    fout << tree;
    fin.close();
    fout.close();
    return 0;
}
