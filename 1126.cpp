#include <iostream>


using namespace std;


int main() {
    unsigned short m;
    cin >> m;
    auto carriage = new unsigned int [m];
    unsigned short index = 0;
    unsigned int max = 0;
    unsigned int inp;
    for (unsigned short i = 0; i < m; i++) {
        cin >> inp;
        carriage[i] = inp;
        if (inp > max) {
            max = inp;
        }
    }
    // дадада я беззнаковый сравниваю с -1 все намана
    while (inp != -1) {
        cout << max << endl;
        max = 0;
        cin >> inp;
        carriage[index] = inp;
        index = (index + 1) % m;
        for (unsigned short i = 0; i < m; i++) {
            if (carriage[i] > max) {
                max = carriage[i];
            }
        }
    }
    return 0;
}
