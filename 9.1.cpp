#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

bool has(Node* root, int key) {
    if (!root) {
        return false;
    }
    if (root->key == key) {
        return true;
    } else if (key < root->key) {
        return has(root->left, key);
    } else {
        return has(root->right, key);
    }
}

int next(Node* root, int x) {
    Node* current = root;
    int ans = INT_MAX;
    while (current) {
        if (current->key > x) {
            ans = min(ans, current->key);
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int prev(Node* root, int x) {
    Node* current = root;
    int ans = INT_MIN;
    while (current) {
        if (current->key < x) {
            ans = max(ans, current->key);
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return ans == INT_MIN ? -1 : ans;
}

Node* deleteNode(Node* root, int key) {
    if (!root) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
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
        Node* temp = root->right;
        while (temp->left) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    string command;
    int key;
    
    while (cin >> command >> key) {
        if (command == "insert") {
            root = insert(root, key);
        } else if (command == "delete") {
            root = deleteNode(root, key);
        } else if (command == "has") {
            cout << (has(root, key) ? "t" : "f") << endl;
        } else if (command == "next") {
            cout << next(root, key) << endl;
        } else if (command == "prev") {
            cout << prev(root, key) << endl;
        }
    }
    
    return 0;
}