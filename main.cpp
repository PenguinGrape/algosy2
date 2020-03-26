#include <iostream>
#include <vector>
#include <cmath>
#define MAX 500000


using namespace std;


int* droot;
vector<pair<int,int>>* tree;
int d[MAX], f[MAX];
int up[MAX][20];
int depth = 1;


/*
 * Значит так блять
 * dist - массив со значениями расстояние до корня
 * тогда расстояние между заданными вершинами:
 * dist[u] – dist[l] + dist[v] – dist[l];
 * заебись, че дальше?
 * дфс который для каждой вершины запомнит ебаное расстояние до корня
 */


void dfs (int v, int p = 0, int len = 0, int timer = 0) {
    int to;
    d[v] = timer++;
    up[v][0] = p;
    droot[v] = len;
    for(int i = 1; i <= depth; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(int i = 0; i < tree[v].size(); i++) {
        to = tree[v][i].first;
        if (to != p) {
            dfs(to, v, len + tree[v][i].second, timer=timer);
        }
    }
    f[v] = timer++;
}


bool is_parent(int x, int y) {
    return (d[x] <= d[y]) && (f[x] >= f[y]);
}


int LCA (int a, int b) {
    if (is_parent(a, b)) return a;
    if (is_parent(b, a)) return b;
    for (int i = depth; i >= 0; i--) {
        if (!is_parent(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}


int main() {
    int n;
    int m;
    cin >> n;
    tree = new vector<pair<int, int>> [n];
    droot = new int [n];
    depth = ceil(log2(n));
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        tree[x].emplace_back(y, w);
        tree[y].emplace_back(x, w);
    }
    dfs(0);
    cin >> m;
    for(int i = 0; i < m; i++) {
        int u;
        int v;
        cin >> u >> v;
        int lca = LCA(u, v);
        cout << droot[u] - droot[lca] + droot[v] - droot[lca] << endl;
    }
    return 0;
}
