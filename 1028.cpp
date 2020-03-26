#include <iostream>


using namespace std;


int tree[32001];
int levels[32001];


void update(int x) {
    while (x <= 32001) {
        tree[x]++;
        x += (x & -x);
    }
}


int f(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= (x & -x);
    }
    return sum;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0;  i < n;  i++) {
        int x, y;
        cin >> x >> y;
        x++;
        levels[f(x)]++;
        update(x);
    }
    for (int i = 0;  i < n;  i++) {
        cout << levels[i] << endl;
    }
}