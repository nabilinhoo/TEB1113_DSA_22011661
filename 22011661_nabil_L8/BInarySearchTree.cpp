// NAME : NABIL NAQIB BIN SAHRUL RIZAL
// ID : 22011661
// LAB : LAB 8


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

    void insert(string name) {
        if (root == nullptr) {
            root = new Node(name);
            cout << "Root node created: " << name << endl;
            return;
        }
        insertNode(root, name);
    }

    void insertNode(Node* current, string name) {
        if (name < current->name) {
            if (current->leftbranch == nullptr) {
                current->leftbranch = new Node(name);
                cout << "Added node: " << name << " as left child of " << current->name << endl;
            } else {
                insertNode(current->leftbranch, name);
            }
        } else if (name > current->name) {
            if (current->rightbranch == nullptr) {
                current->rightbranch = new Node(name);
                cout << "Added node: " << name << " as right child of " << current->name << endl;
            } else {
                insertNode(current->rightbranch, name);
            }
        } else {
            cout << "Error: Node " << name << " already exists" << endl;
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

    tree.insert("D"); 
    tree.insert("B");
    tree.insert("A");
    tree.insert("C");
    tree.insert("G");
    tree.insert("E");
    tree.insert("F");
    tree.print();

    return 0;
}
