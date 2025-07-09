#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
            head->prev = newNode;

        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        // Search for the node
        while (temp != nullptr && temp->data != value)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Value not found." << endl;
            return;
        }

        // If deleting head
        if (temp == head) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
        } else {
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Search value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display forward
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display backward
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to test
int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.displayForward();

    list.deleteByValue(10);
    list.displayForward();

    list.displayBackward();

    if (list.search(20)) {
        cout << "20 found in the list." << endl;
    } else {
        cout << "20 not found." << endl;
    }

    return 0;
}
