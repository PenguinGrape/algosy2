#include <iostream>
#include <cstring>
#include <stack>


using namespace std;


int main() {
    stack<char> st4ck;
    char input [200001];
    cin >> input;
    unsigned int length = strlen(input);
    st4ck.push('\0');
    for (unsigned int i = 0; i < length; i++) {
        if (st4ck.top() != input[i]){
            st4ck.push(input[i]);
        } else {
            st4ck.pop();
        }
    }
    length = st4ck.size();
    for (unsigned int i = length - 1; i > 0; i--) {
        input[i - 1] = st4ck.top();
        st4ck.pop();
    }
    input[length - 1] = '\0';
    cout << input;
    return 0;
}
