#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void reverseList(Node** head) {
    Node* temp = nullptr;
    Node* current = *head;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        *head = temp->prev;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    cout << "Original Doubly Linked List: ";
    printList(head);

    reverseList(&head);

    cout << "Reversed Doubly Linked List: ";
    printList(head);

    return 0;
}