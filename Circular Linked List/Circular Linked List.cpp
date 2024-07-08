#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data, key;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

bool isEmpty() {
    return head == NULL;
}

int listLength() {
    int length = 0;
    Node *current;
    for (current = head; current != NULL; current = current->next) {
        length++;
    }
    return length;
}

void displayForward() {
    Node *ptr = head;
    
    cout << "\n[ ";
    while (ptr != NULL) {
        cout << "(" << ptr->key << ", " << ptr->data << ")";
        ptr = ptr->next;
        cout << " ";
    }
    cout << "]\n\n";
}

void displayBackward() {
    Node *ptr = tail;
    
    cout << "\n[ ";
    while (ptr != NULL) {
        cout << "(" << ptr->key << ", " << ptr->data << ")";
        ptr = ptr->prev;
        cout << " ";
    }
    cout << "]\n\n\n";
}

void addHead(int key, int data) {
    Node *link = (Node*)malloc(sizeof(Node));
    link->key = key;
    link->data = data;
    link->next = head;
    link->prev = NULL;
    
    if (isEmpty()) {
        tail = link;
    } else {
        head->prev = link;
    }
    
    head = link;
}

void addTail(int key, int data) {
    Node *link = (Node*)malloc(sizeof(Node));
    link->key = key;
    link->data = data;
    link->next = NULL;
    link->prev = tail;
    
    if (isEmpty()) {
        head = link;
    } else {
        tail->next = link;
    }
    tail = link;
}

Node* deleteHead() {
    if (isEmpty()) return NULL;
    
    Node *tempLink = head;
    if (head->next == NULL) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(tempLink);
    return head;
}

Node* deleteTail() {
    if (isEmpty()) return NULL;
    
    Node *tempLink = tail;
    if (tail->prev == NULL) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(tempLink);
    return tail;
}

bool addAfter(int key, int newKey, int data) {
    Node *current = head;
    
    if (head == NULL) {
        return false;
    }
    while (current->key != key) {
        if (current->next == NULL) {
            return false;
        } else {
            current = current->next;
        }
    }
    
    Node *newLink = (Node*)malloc(sizeof(Node));
    newLink->key = newKey;
    newLink->data = data;
    
    if (current == tail) {
        newLink->next = NULL;
        tail = newLink;
    } else {
        newLink->next = current->next;
        current->next->prev = newLink;
    }
    newLink->prev = current;
    current->next = newLink;
    return true;
}

int main() {
    addHead(1, 90);
    addHead(2, 40);
    addHead(3, 60);
    addHead(4, 70);
    addHead(5, 80);
    addHead(6, 30);
    addHead(7, 35);
    addHead(8, 75);
    cout << "\n List from Head to Tail : \n";
    displayForward();
    
    cout << "\n";
    cout << "\n List from Tail to Head : \n";
    displayBackward();
    
    cout << "\n List after deleting the head node : \n";
    deleteHead();
    displayForward();
    
    cout << "\n List after deleting the tail node : \n";
    deleteTail();
    displayForward();
    
    cout << "\n Add node after key 3 : \n";
    addAfter(3, 9, 12);
    displayForward();
    
    return 0;
}
