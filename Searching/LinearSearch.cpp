#include <iostream>
using namespace std;

int linearSearch(int arr[], int length, int find) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == find) {
            return i;
        }
    }
    return -1;
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int length = 5;
    int arr[length] = {2, 4, 0, 1, 9};
    int find;
    
    cout << "Array: ";
    printArray(arr, length);
    cout << endl;
    
    cout << "Enter the element to search: ";
    cin >> find;
    
    int result = linearSearch(arr, length, find);
    
    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }
    
    return 0;
}
