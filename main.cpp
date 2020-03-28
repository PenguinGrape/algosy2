#include <iostream>
#include <vector>


using namespace std;


vector<int>* tree;


int main() {
    int h, q;
    cin >> h >> q;
    tree = new vector<int> [h];
    for (int i = 0; i < h - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    return 0;
}
