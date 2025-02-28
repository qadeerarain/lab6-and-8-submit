#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void deleteNode(Node** head, Node* delNode) {
    if (*head == nullptr || delNode == nullptr) {
        return;
    }

    if (*head == delNode) {
        *head = delNode->next;
    }

    if (delNode->next != nullptr) {
        delNode->next->prev = delNode->prev;
    }

    if (delNode->prev != nullptr) {
        delNode->prev->next = delNode->next;
    }

    delete delNode;
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

    cout << "Doubly Linked List: ";
    printList(head);

    deleteNode(&head, head->next); // Delete the second node

    cout << "Doubly Linked List after deletion: ";
    printList(head);

    return 0;
}