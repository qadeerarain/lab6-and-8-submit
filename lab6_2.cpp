#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertBefore(Node** head, Node* nextNode, int data) {
    if (nextNode == nullptr) {
        cout << "The given next node cannot be NULL" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;

    if (nextNode->prev != nullptr) {
        nextNode->prev->next = newNode;
    } else {
        *head = newNode;
    }

    nextNode->prev = newNode;
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

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    cout << "Doubly Linked List: ";
    printList(head);

    insertBefore(&head, head->next, 15);

    cout << "Doubly Linked List after insertion: ";
    printList(head);

    return 0;
}