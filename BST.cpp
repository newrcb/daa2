#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
bool search(Node* root, int value) {
    if (!root) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}
Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int value) {
    if (!root) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int main() {
    Node* root = nullptr;
    int choice, value;
    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. In-order Traversal\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value)) {
                cout << "Value found in the BST.\n";
            } else {
                cout << "Value not found in the BST.\n";
            }
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 4:
            cout << "In-order Traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
