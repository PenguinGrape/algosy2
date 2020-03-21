#include <iostream>
#include <algorithm>


using namespace std;


struct city {
    int count;
    int id;
};


int compare(const void * x1, const void * x2) {
    int res = ((city*)x1)->count - ((city*)x2)->count;
    if (res) {
        return res;
    }
    return ((city*)x1)->id - ((city*)x2)->id;
}


int f(city a, city b) {
    if(a.count == b.count) return a.id < b.id;
    return a.count < b.count;
}


int main() {
    int count;
    cin >> count;
    auto arr = new city [count];
    for (int i = 0; i < count; i++) {
        cin >> arr[i].count;
        arr[i].id = i + 1;
    }
    qsort(arr, count, sizeof(city), compare);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int fl, fr, fcount;
        cin >> fl >> fr >> fcount;
        city lcity {fcount, fl};
        city rcity {fcount, fr};
        long l = lower_bound(arr, arr + count, lcity, f) - arr;
        long r = upper_bound(arr, arr + count, rcity, f) - arr;
        if (l < r) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    return 0;
}
