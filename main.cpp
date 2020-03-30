#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


vector<int>* tree;
vector<int>* up;
int* droot;
int depth;
pair<int, int> maxw1;
pair<int, int> maxw2;


void dfs (int v, int p, int w) {
    if (w >= maxw1.second) {
        maxw2 = maxw1;
        maxw1.first = v;
        maxw1.second = w;
    }
    droot[v] = w;
    up[v][0] = p;
    for (int i=1; i<=depth; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    vector<int> ways = tree[v];
    for (auto & way : ways) {
        if (way != p) {
            dfs(way, v, w + 1);
        }
    }
}


int main() {
    int n, q;
    cin >> n >> q;
    tree = new vector<int> [n];
    up = new vector<int> [n];
    droot = new int [n];
    depth = ceil(log2(n));
    maxw1 = {0, -1};
    maxw2 = {0, -1};
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i=0; i<n; ++i) {
        up[i].resize (depth+1);
    }
    dfs(0, 0, 0);
    cout << maxw1.first << ' ' << maxw1.second << endl;
    cout << maxw2.first << ' ' << maxw2.second << endl;
    return 0;
}
