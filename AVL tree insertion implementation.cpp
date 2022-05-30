#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
int calHeight(Node* root)
{
    int l = 0, r = 0;
    if (root->left)
        l = root->left->height;
    if (root->right)
        r = root->right->height;
    return max(l, r) + 1;
}
int calBalanceFactor(Node* root)
{
    int l = 0, r = 0;
    if (root->left)
        l = root->left->height;
    if (root->right)
        r = root->right->height;
    return l - r;
}
Node* rightRotation(Node* root)
{
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->height = calHeight(root);
    newRoot->height = calHeight(newRoot);
    return newRoot;
}
Node* leftRotation(Node* root)
{
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root->height = calHeight(root);
    newRoot->height = calHeight(newRoot);
    return newRoot;
}
Node* insert(Node* root, int data)
{
    if (!root) return new Node(data);
    if (root->data > data) {
        Node* temp = insert(root->left, data);
        root->left = temp;
    }
    else {
        Node* temp = insert(root->right, data);
        root->right = temp;
    }
    root->height = calHeight(root);
    if (calBalanceFactor(root) == 2 && calBalanceFactor(root->left) == 1) //RR rotation
    {
        root = rightRotation(root);
    }
    else if (calBalanceFactor(root) == -2 && calBalanceFactor(root->right) == -1) //LL rotation
    {
        root = leftRotation(root);
    }
    else if (calBalanceFactor(root) == 2 && calBalanceFactor(root->left) == -1) //LR rotation
    {
        root->left = leftRotation(root->left);
        root = rightRotation(root);
    }
    else if (calBalanceFactor(root) == -2 && calBalanceFactor(root->right) == 1) //RL rotation
    {
        root->right = rightRotation(root->right);
        root = leftRotation(root);
    }
    return root;
}
void preorder(Node* root)
{
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node* root = NULL;
    int n;
    cout << "Enter the number of nodes to be inserted : ";
    cin >> n;
    int num;
    cout << "Enter " << n << " nodes : ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        root = insert(root, num);
    }
    cout << "Preorder traversal of generated AVL tree : ";
    preorder(root);
    cout << "\n";
    return 0;
}