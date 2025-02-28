#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Define the Queue class
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            // If the queue is empty, set both front and rear to the new node
            front = rear = newNode;
        } else {
            // Otherwise, link the new node to the rear and update rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front; // Store the front node
        int dequeuedValue = temp->data;

        // Move front to the next node
        front = front->next;

        // If front becomes nullptr, set rear to nullptr as well
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // Free the memory of the dequeued node
        cout << dequeuedValue << " dequeued from the queue." << endl;
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return front->data;
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to dequeue from an empty queue

    q.display();

    return 0;
}