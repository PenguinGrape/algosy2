#include <iostream>


using namespace std;
struct team {
    unsigned int id;
    unsigned int value;
};


team* mergesort(team *buf1, team *buf2, int l, int r) {
    if (l == r){
        buf2[l] = buf1[l];
        return buf2;
    }
    int m = (r + l) / 2;
    team *lb = mergesort(buf1, buf2, l, m);
    team *rb = mergesort(buf1, buf2, m + 1, r);
    team *to;
    if (lb == buf2) {
        to = buf1;
    } else {
        to = buf2;
    }
    int curl = l;
    int curr = m + 1;
    for (int i = l; i < r + 1; i++) {
        if (curr > r) {
            to[i] = lb[curl];
            curl++;
            continue;
        }
        if (curl > m) {
            to[i] = rb[curr];
            curr++;
            continue;
        }
        if (lb[curl].value < rb[curr].value) {
            to[i] = lb[curl];
            curl++;
        } else {
            to[i] = rb[curr];
            curr++;
        }
    }
    return to;
}


int main() {
    int count;
    cin >> count;
    auto arr = new team [count];
    auto barr = new team [count];
    for (unsigned int i = 0; i < count; i++) {
        cin >> arr[i].id >> arr[i].value;
    }
    team* result = mergesort(arr, barr, 0, count - 1);
    for (unsigned int i = count; i > 0; i--) {
        cout << result[i - 1].id << " " << result[i - 1].value << endl;
    }
    return 0;
}
