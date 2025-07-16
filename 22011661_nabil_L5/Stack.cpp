//NAME : NABIL NAQIB BIN SAHRUL RIZAL
//ID : 22011661

#include <string>
#include <iostream>
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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next_ptr = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. You cannot pop\n";
            return;
        }

        Node* temp = top;
        top = top->next_ptr;
        cout << "Popped: " << temp->name << endl;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* current = top;
        cout << "Stack (Top -> Bottom): ";
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Abu");

    stack.display();

    stack.pop();
    stack.display();

    return 0;
}
