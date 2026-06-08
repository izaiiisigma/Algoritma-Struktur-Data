#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

int calculateDiameter(Node* root, int& max_dia) {
    if (root == NULL) {
        return 0;
    }

    int left_height = calculateDiameter(root->left, max_dia);
    int right_height = calculateDiameter(root->right, max_dia);

    max_dia = max(max_dia, left_height + right_height);

    return max(left_height, right_height) + 1;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Node* root = NULL;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int max_dia = 0;
    
    calculateDiameter(root, max_dia);

    cout << max_dia << endl;

    return 0;
}