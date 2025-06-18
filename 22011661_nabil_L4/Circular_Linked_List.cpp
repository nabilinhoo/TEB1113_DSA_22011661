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
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    LinkedList(string name) {
        Node* newNode = new Node(name);
        newNode->next_ptr = newNode; 
        head = newNode;
        tail = newNode;
    }

    void add_element(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            newNode->next_ptr = newNode;
            head = newNode;
            tail = newNode;
        } else {
            newNode->next_ptr = head;
            tail->next_ptr = newNode;
            tail = newNode;
        }
    }

    void delete_element(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        Node* previous = tail;
        bool found = false;

        do {
            if (current->name == name) {
                found = true;
                break;
            }
            previous = current;
            current = current->next_ptr;
        } while (current != head);

        if (!found) {
            cout << "Node not found." << endl;
            return;
        }

        if (current == head && current == tail) {
            // Only one node
            delete current;
            head = nullptr;
            tail = nullptr;
        } else {
            previous->next_ptr = current->next_ptr;
            if (current == head) head = current->next_ptr;
            if (current == tail) tail = previous;
            delete current;
        }
        cout << "Node deleted." << endl;
    }

    void view() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Circular Linked List: ";
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    LinkedList list("A");

    list.add_element("B");
    list.add_element("C");

    list.view();

    list.delete_element("B");
    list.view();

    list.delete_element("X"); 
    list.view();

    return 0;
}
