#include <iostream>
#define MAX 3
using namespace std;

int queue[MAX];
int front = -1;
int rear = -1;

bool isFull(){
    return rear == MAX - 1;
}

bool isEmpty(){
    return front == -1 || front > rear;
}

void insert(){
    int add;
    if(isFull()){
        cout << "Queue Overflow!" << endl;
    } else {
        cout << "Enter Queue Element Value: ";
        cin >> add;
        
        if(isEmpty()){
            front = 0;
        }
        queue[++rear] = add;
    }
}

void del(){
    if(isEmpty()){
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "->> " << queue[front] << " deleted" << endl;
        for(int i = front; i < rear; i++){
            queue[i] = queue[i + 1];
        }
        rear--; 
        if(rear < front){
            front = rear = -1;
        }
    }
}
    
void display(){
    if(isEmpty()){
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "Queue Element Values: " << endl;
        for(int i = front; i <= rear; i++){
            cout << "<-- " << queue[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int choice;
    
    while(true){
        cout << "\n[1] Input Queue" << endl;
        cout << "[2] Delete Queue" << endl;
        cout << "[3] Print Queue" << endl;
        cout << "[4] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1: insert(); break;
            case 2: del(); break;
            case 3: display(); break;
            case 4: return 0;
            default: cout << "Choose from the menu above!" << endl;
        }
    }
    return 0;
}
