#include <iostream>
#include <string>
#include <stdexcept> // For RangeError
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next_ptr = head; // circular
        } else {
            tail->next_ptr = newNode;
            tail = newNode;
            tail->next_ptr = head; // maintain circular link
        }
    }

    void show_circle(int max_loops) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        int counter = 0;

        try {
            cout << "Showing names in a circle (up to " << max_loops << " names):" << endl;
            while (true) {
                if (counter >= max_loops) {
                    throw range_error("RangeError: Loop limit exceeded.");
                }
                cout << current->name << " -> ";
                current = current->next_ptr;
                counter++;
            }
        } catch (range_error& e) {
            cout << "\n" << e.what() << endl;
        }
    }
};

int main() {
    CircularLinkedList list;

    list.add("Ahmed");
    list.add("Alee");
    list.add("Ali");
    list.add("Hamza");

    list.show_circle(10); // Show 10 names in a loop

    return 0;
}
