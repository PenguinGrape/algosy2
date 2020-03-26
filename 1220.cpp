#include <iostream>
#include <vector>


using namespace std;


int main() {
    // ясно студия снова сосет и вытворяет черную магию
    vector<int> stacks [1000];
    unsigned int n;
    cin >> n;
    for (unsigned int i = 0; i < n; i++) {
        char operation[5];
        cin >> operation;
        if (operation[1] == 'U') {
            unsigned short number;
            cin >> number;
            number--;
            unsigned int value;
            cin >> value;
            stacks[number].push_back(value);
        } else {
            unsigned short number;
            cin >> number;
            number--;
            auto value = stacks[number].back();
            stacks[number].pop_back();
            cout << value << endl;
        }
    }
    return 0;
}
