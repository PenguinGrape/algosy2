#include <iostream>

using namespace std;
int n;
int ftree[10001];


int f(int x) {
    int res = 0;
    while (x > 0) {
        res += ftree[x];
        x -= x & (-x);
    }
    return res;
}


void update(int x) {
    while (x <= n) {
        ftree[x]++;
        x += x & (-x);
    }
}

int main() {
    int k;
    cin >> n >> k;
    int res = 0;                // cLaNg-TiDy
    int min = 0;
    int* arr = new int [n + 1];
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= 10001; j++) {
            ftree[j] = 0;
        }
        int s = 0;
        for (int j = 1; j <= n; j++) {
            cin >> arr[j];
        }
        for (int j = 1; j <= n; j++) {
            s += j - f(arr[j]);
            update(arr[j]);
        }
        if (s > min) {
            min = s;
            res = i;
        }
    }
    cout << res;
    return 0;
}
