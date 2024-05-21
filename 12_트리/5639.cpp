#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void postOrderTraversal() {
        postOrderRec(root);
    }

private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void postOrderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        postOrderRec(node->left);
        postOrderRec(node->right);
        cout << node->value << endl;
    }
};

int main() {
    vector<int> values;
    int value;
    while (cin >> value) {
        values.push_back(value);
    }

    BinarySearchTree bst;
    for (int v : values) {
        bst.insert(v);
    }

    bst.postOrderTraversal();

    return 0;
}
