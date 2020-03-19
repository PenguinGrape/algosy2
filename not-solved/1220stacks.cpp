#include <iostream>
#define START_COUNT 2


using namespace std;


struct stack {
    unsigned int* value;
    unsigned int count;
    unsigned int maxcount;
};


int main() {
    stack stacks [1000];
    for (auto & stack : stacks) {
        stack.value = (unsigned int *) malloc(sizeof(int) * START_COUNT);
        stack.count = 0;
        stack.maxcount = START_COUNT;
    }
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
            if (stacks[number].count + 1 > stacks[number].maxcount) {
                // да я знаю что реалок в х2 быстрее, но хуй с ним
                stacks[number].value = (unsigned int*)realloc(stacks[number].value, sizeof(int) * (stacks[number].maxcount + START_COUNT));
                stacks[number].maxcount += START_COUNT;
            }
            stacks[number].value[stacks[number].count] = value;
            stacks[number].count++;
        } else {
            unsigned short number;
            cin >> number;
            number--;
            unsigned int value = stacks[number].value[stacks[number].count - 1];
            stacks[number].count--;
            cout << value << endl;
        }
    }
    return 0;
}