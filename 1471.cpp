#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


int* droot;
vector<pair<int,int>>* tree;
int depth;
int* tin;
int* tout;
int timer = 0;
vector<int>* up;


void dfs (int v, int p, int w) {
    tin[v] = ++timer;
    droot[v] = w;
    up[v][0] = p;
    for (int i=1; i<=depth; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    vector<pair<int, int>> ways = tree[v];
    for (auto & way : ways) {
        if (way.first != p) {
            dfs(way.first, v, w + way.second);
        }
    }
    tout[v] = ++timer;
}


bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}


int lca(int v, int u) {
    if (upper (v, u))  return v;
    if (upper (u, v))  return u;
    for (int i=depth; i>=0; --i) {
        if (!upper(up[v][i], u)) {
            v = up[v][i];
        }
    }
    return up[v][0];
}


int main() {
    int n;
    int m;
    cin >> n;
    tree = new vector<pair<int, int>> [n];
    up = new vector<int> [n];
    tin = new int [n];
    tout = new int [n];
    droot = new int [n];
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        tree[x].emplace_back(y, w);
        tree[y].emplace_back(x, w);
    }
    while ((1<<depth) <= n) {
        ++depth;
    }
    for (int i=0; i<n; ++i) {
        up[i].resize (depth+1);
    }
    dfs(0, 0, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        int p = lca(v, u);
        cout << droot[u] - droot[p] + droot[v] - droot[p] << endl;
    }
    return 0;
}
