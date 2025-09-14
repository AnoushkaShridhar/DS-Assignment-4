#include <iostream>
using namespace std;

#define MAX 5
class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == 0 && rear == MAX - 1) || (rear + 1 == front); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n"; return;
        }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n"; return;
        }
        cout << arr[front] << " dequeued\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty()) cout << "Queue empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty\n"; return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
        case 2: q.dequeue(); break;
        case 3: cout << (q.isEmpty() ? "Queue Empty\n" : "Queue not Empty\n"); break;
        case 4: cout << (q.isFull() ? "Queue Full\n" : "Queue not Full\n"); break;
        case 5: q.display(); break;
        case 6: q.peek(); break;
        case 7: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
