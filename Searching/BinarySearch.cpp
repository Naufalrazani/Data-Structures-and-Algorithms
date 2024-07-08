#include <iostream>
using namespace std;

int binarySearch(int arr[], int find, int low, int high){
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == find){
			return mid;
		}
		if(arr[mid] < find){
			low = mid + 1;
		} else {
			high = mid - 1;
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

int main(){
	int length = 5;
	int arr[length] = {3, 4, 5, 6, 7};
	int find;
	
	cout << "Array: ";
	printArray(arr, length);
	cout << endl;
	
    cout << "Enter the element to search: ";
    cin >> find;
	
	int result = binarySearch(arr, find, 0, length - 1);
	
    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }
    
    return 0;
}
