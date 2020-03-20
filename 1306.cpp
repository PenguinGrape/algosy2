#include <iostream>
#include <iomanip>


using namespace std;


unsigned int parent(unsigned int i);
void heapify(unsigned int* arr, int root);
void buidHeap(unsigned int* arr);
unsigned int extractMax(unsigned int* arr);
void increaseKey(unsigned int* arr, unsigned int i, unsigned int k);
void insertIntoHeap(unsigned int* arr, unsigned int k);
unsigned int HeapSize;


int main() {
    unsigned int n;
    cin >> n;
    HeapSize = n / 2 + 1;
    auto arr = new unsigned int [HeapSize + 1];
    for (unsigned int i = 0; i < HeapSize; i++) {
        cin >> arr[i];
    }
    buidHeap(arr);
    for (unsigned int i = HeapSize; i < n; i++) {
        unsigned int cur;
        cin >> cur;
        insertIntoHeap(arr, cur);
        extractMax(arr);
    }
    if (n % 2) {
        unsigned int max = extractMax(arr);
        cout << max << ".0" << endl;
    } else {
        unsigned long max = extractMax(arr);
        max += extractMax(arr);
        cout << setprecision (100500) << (double)max / 2;
        // формартирование это кто? (who?)
        if (max % 2) {
            cout << endl;
        } else {
            cout << ".0" << endl;
        }
    }
    return 0;
}


unsigned int parent(unsigned int i) {
    if (i % 2) {
        return (i - 1) / 2;
    } else {
        return (i - 2) / 2;
    }
}


void heapify(unsigned int* arr, unsigned int root) {
    unsigned int max = root;
    unsigned int l = 2 * root + 1;
    unsigned int r = 2 * root + 2;
    if (l < HeapSize && arr[l] > arr[max])
        max = l;
    if (r < HeapSize && arr[r] > arr[max])
        max = r;
    if (max != root)
    {
        swap(arr[root], arr[max]);
        heapify(arr, max);
    }
}

void buidHeap(unsigned int* arr) {
    for (int i = HeapSize / 2 - 1; i >= 0; i--) {
        heapify(arr, (unsigned int)i);
    }
}


unsigned int extractMax(unsigned int* arr) {
    unsigned int max = arr[0];
    arr[0] = arr[HeapSize - 1];
    HeapSize -= 1;
    heapify(arr, 0u);
    return max;
}


void increaseKey(unsigned int* arr, unsigned int i, unsigned int k) {
    arr[i] = k;
    while (i > 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void insertIntoHeap(unsigned int* arr, unsigned int k) {
    HeapSize += 1;
    increaseKey(arr, HeapSize - 1, k);
}
