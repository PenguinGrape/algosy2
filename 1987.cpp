#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>


using namespace std;


struct point {
    int x;
    unsigned char type;
    int id;
};


bool operator<(const point& x, const point& y) {
    return x.x < y.x;
}


int main() {
    int n;
    cin >> n;
    auto earr = new point [n];
    auto sarr = new point [2 * n];
    for (int i = 0; i < 2 * n; i++) {
        int index = i / 2;
        if (i % 2) {
            cin >> earr[index].x;
            earr[index].type = 'e';
            earr[index].id = index + 1;
        } else {
            cin >> sarr[index].x;
            sarr[index].type = 's';
            sarr[index].id = index + 1;
        }
    }
    int m;
    cin >> m;
    point* arr = sarr;
    arr = (point*)realloc(arr, sizeof(point) * (2 * n + m));
    for (int i = n; i < n + m; i++) {
        cin >> arr[i].x;
        arr[i].type = 'q';
    }
    memcpy(arr + n + m, earr, sizeof(point) * n);
    stable_sort(arr, arr + 2 * n + m);
    stack<point> st4ck;
    for (int i = 0; i < 2 * n + m; i++) {
        unsigned char type = arr[i].type;
        if (type == 's') {
            st4ck.push(arr[i]);
        }
        if (type == 'q') {
            if (st4ck.empty()) {
                cout << "-1" << endl;
            } else {
                cout << st4ck.top().id << endl;
            }
        }
        if (type == 'e') {
            st4ck.pop();
        }
    }
    return 0;
}
