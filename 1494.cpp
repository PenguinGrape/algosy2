#include <iostream>
#include <stack>


using namespace std;


int main() {
    int count;
    cin >> count;
    auto arr = new int [count];
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }
    stack<int> st4ck;
    int max = 0;
    for (int i = 0; i < count; i++) {
        for (int j = max+1; j <= arr[i]; j++) {
            st4ck.push(j);
        }
        if (max < arr[i]) {
            max = arr[i];
        }
        int dig = st4ck.top();
        st4ck.pop();
        if (dig != arr[i]){
            cout << "Cheater" << endl;
            return 0;
        }
    }
    cout << "Not a proof" << endl;
    return 0;
}
