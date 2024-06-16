#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int arr[], int length, bool isFilled){
	if(!isFilled){
		cout << "Array is empty!" << endl;
	} else {
		cout << "Array: ";
		for(int i = 0; i < length; i++){
		cout << arr[i] << " ";
		}
		cout << endl;	
	}
}

void inputArray(int arr[], int length, bool &isFilled){
	if(isFilled){
		cout << "Array is already filled!" << endl;
	} else {
		for(int i = 0; i < length; i++){
		cout << "[" << i + 1 << "]: "; cin >> arr[i];
		}
		isFilled = true;
	}
}

void clearArray(int arr[], int length, bool &isFilled){
	if(!isFilled){
		cout << "Array is already empty!" << endl;
	} else {
		for(int i = 0; i < length; i++){
			arr[i] = 0;
		}
		isFilled = false;
		cout << "Array cleared." << endl;
	}
}

int partition(int arr[], int low, int high, int filter){
	int pivot = arr[high];
	int i = low - 1;
	
	if(filter == 1){
		for(int j = low; j <= high - 1; j++){
			if(arr[j] <= pivot){
				i++;
				swap(arr[i], arr[j]);
			}
		}
	} else if (filter == 2){
		for(int j = low; j <= high - 1; j++){
			if(arr[j] >= pivot){
				i++;
				swap(arr[i], arr[j]);
			}
		}
	}
	
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high, int filter){
	if(low < high){
		int pi = partition(arr, low, high, filter);
		
		quickSort(arr, low, pi - 1, filter);
		quickSort(arr, pi + 1, high, filter);
	}
}

int main(){
	cout << "---------------------------------" << endl;
	cout << "\tQuick Sort Program" << endl;
	cout << "---------------------------------\n" << endl;
	
	int length, n, filter;
	cout << "Enter the length of the array: "; cin >> length;
	int arr[length];
	bool isFilled = false;
	
	do {
		cout << "\n[1] Enter Array" << endl;
		cout << "[2] Display Array" << endl;
		cout << "[3] Sort Array" << endl;
		cout << "[4] Clear Array" << endl;
		cout << "[5] Exit" << endl;
		cout << "Choose an option : "; 
		cin >> n;
		
		switch(n){
			case 1: 
				inputArray(arr, length, isFilled); 
				break;
			case 2: 
				printArray(arr, length, isFilled); 
				break;
			case 3:	
				if(!isFilled){
					cout << "Cannot sort an empty array." << endl;
				} else {
					cout << " [1] Ascending" << endl; 
					cout << " [2] Descending" << endl;
					cout << " Choose an option: "; 
					while (!(cin >> filter) || (filter != 1 && filter != 2)){
						cout << " Invalid option! Please choose 1 or 2: ";
					}	
					quickSort(arr, 0, length - 1, filter); 
					cout << " Sorted ";
					printArray(arr, length, isFilled);
				}
				break;
			case 4: 
				clearArray(arr, length, isFilled); 
				break;
			case 5: 
				break;
			default: 
				cout << "Invalid option! Please try again." << endl; 
				break;
		}	
	} while (n != 5);
	return 0;
}
