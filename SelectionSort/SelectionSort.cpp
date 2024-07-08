#include <iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

void selectionSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] > array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }

        cout << "Step " << i + 1 << " : ";
        printArray(array, n);
        cout << endl;
    }
}

void inputArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of element " << i + 1 << " : ";
        cin >> array[i];
    }
}

int main() {
    cout << "---------------------------------" << endl;
    cout << "Selection Sort Descending Program" << endl;
    cout << "---------------------------------" << endl;

    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;
    int array[n];

    inputArray(array, n);

    cout << "\nArray elements before sorting: \n";
    printArray(array, n);

    cout << "\n\nSelection Sort Steps: \n";
    selectionSort(array, n);

    cout << "\nArray elements after sorting: \n";
    printArray(array, n);

    return 0;
}

