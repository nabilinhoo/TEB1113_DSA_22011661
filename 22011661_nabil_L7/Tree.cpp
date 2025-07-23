//NAME : NABIL NAQIB BIN SAHRUL RIZAL
//ID : 22011661

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* leftbranch;
    Node* rightbranch;

    Node(string name) : name(name), leftbranch(nullptr), rightbranch(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    ~Tree() {
        deleteSubtree(root);
    }

    void deleteSubtree(Node* node) {
        if (node == nullptr) return;
        deleteSubtree(node->leftbranch);
        deleteSubtree(node->rightbranch);
        delete node;
    }

    void addRoot(string name) {
        if (root == nullptr) {
            root = new Node(name);
            cout << "Root node created: " << name << endl;
        } else {
            cout << "Error: Root already exists" << endl;
        }
    }

    void addLeft(Node* parent, string name) {
        if (parent->leftbranch == nullptr) {
            parent->leftbranch = new Node(name);
            cout << "Added left child: " << name << " to parent: " << parent->name << endl;
        } else {
            cout << "Error: Left child already exists for parent: " << parent->name << endl;
        }
    }

    void addRight(Node* parent, string name) {
        if (parent->rightbranch == nullptr) {
            parent->rightbranch = new Node(name);
            cout << "Added right child: " << name << " to parent: " << parent->name << endl;
        } else {
            cout << "Error: Right child already exists for parent: " << parent->name << endl;
        }
    }

    Node* findNode(Node* current, string name) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current->name == name) {
            return current;
        }
        Node* leftResult = findNode(current->leftbranch, name);
        if (leftResult != nullptr) {
            return leftResult;
        }
        return findNode(current->rightbranch, name);
    }

    void tree_add_left(string parentName, string childName) {
        Node* parent = findNode(root, parentName);
        if (parent != nullptr) {
            addLeft(parent, childName);
        } else {
            cout << "Error: Parent node " << parentName << " not found." << endl;
        }
    }

    void tree_add_right(string parentName, string childName) {
        Node* parent = findNode(root, parentName);
        if (parent != nullptr) {
            addRight(parent, childName);
        } else {
            cout << "Error: Parent node " << parentName << " not found." << endl;
        }
    }

    void printTree(Node* node, int level = 0) {
        if (node == nullptr) return;
        for (int i = 0; i < level; i++) cout << "  ";
        cout << node->name << endl;
        printTree(node->leftbranch, level + 1);
        printTree(node->rightbranch, level + 1);
    }

    void print() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            cout << "Tree structure:" << endl;
            printTree(root);
        }
    }
};

int main() {
    Tree tree;

    tree.addRoot("A");
    tree.tree_add_left("A", "B");
    tree.tree_add_right("A", "C");
    tree.tree_add_left("B", "D");
    tree.tree_add_right("B", "E");
    tree.tree_add_left("C", "F");
    tree.tree_add_right("C", "G");
    tree.print();

    return 0;
}
