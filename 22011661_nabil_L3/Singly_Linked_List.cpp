// NAME : NABIL NAQIB BIN SAHRUL RIZAL
// ID : 22011661
// GROUP : G1

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor for empty linked list
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Constructor with initial node
    LinkedList(string name) {
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
            tail = newNode;
        }
    }

    void delete_element(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next_ptr;
            delete temp;
            if (head == nullptr) tail = nullptr;
            cout << "Node deleted." << endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next_ptr;
        }

        if (current == nullptr) {
            cout << "Node not found." << endl;
            return;
        }

        previous->next_ptr = current->next_ptr;
        if (current == tail) tail = previous;
        delete current;
        cout << "Node deleted." << endl;
    }

    void view() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    // Using constructor with first node
    LinkedList list("A");

    list.add_element("B");
    list.add_element("C");

    list.view();

    list.delete_element("B");
    list.view();

    list.delete_element("X"); // non-existing element
    list.view();

    return 0;
}
