// NAME : NABIL NAQIB BIN SAHRUL RIZAL
// ID : 22011661
// GROUP : G1

#include <iostream>
#include <string>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string name, Node* next_ptr = nullptr, Node* prev_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
        this->prev_ptr = prev_ptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor for empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Constructor with initial node
    DoublyLinkedList(string name) {
        Node* newNode = new Node(name);
        head = newNode;
        tail = newNode;
    }

    void add_element(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next_ptr = newNode;
            newNode->prev_ptr = tail;
            tail = newNode;
        }
    }

    void delete_element(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        while (current != nullptr && current->name != name) {
            current = current->next_ptr;
        }

        if (current == nullptr) {
            cout << "Node not found." << endl;
            return;
        }

        if (current == head) { // deleting head
            head = head->next_ptr;
            if (head != nullptr)
                head->prev_ptr = nullptr;
            else
                tail = nullptr; // list is empty now
        } else if (current == tail) { // deleting tail
            tail = tail->prev_ptr;
            tail->next_ptr = nullptr;
        } else { // deleting middle node
            current->prev_ptr->next_ptr = current->next_ptr;
            current->next_ptr->prev_ptr = current->prev_ptr;
        }

        delete current;
        cout << "Node deleted." << endl;
    }

    void view() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Doubly Linked List (Forward): ";
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void view_reverse() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = tail;
        cout << "Doubly Linked List (Backward): ";
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->prev_ptr;
        }
        cout << "NULL" << endl;
    }
};

// Main function for testing
int main() {
    DoublyLinkedList list("A");

    list.add_element("B");
    list.add_element("C");

    list.view();
    list.view_reverse();

    list.delete_element("B");
    list.view();
    list.view_reverse();

    list.delete_element("X"); // non-existing element
    list.view();

    return 0;
}
