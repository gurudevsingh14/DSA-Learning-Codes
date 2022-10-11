#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
Node* create(int a[], int n)
{
    Node* root = new Node(0);
    Node* temp = root;
    Node* prev = NULL;
    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node(a[i]);
        newNode->prev = prev;
        prev = newNode;
        temp->next = newNode;
        temp = temp->next;
    }
    return root->next;
}
void print(Node* root)
{
    if (!root) {
        cout << "\n";
        return;
    }
    cout << root->data << " -> ";
    print(root->next);
}
Node* insertAtBeginning(Node* root, int key)
{
    Node* newNode = new Node(key);
    newNode->next = root;
    root->prev = newNode;
    root = newNode;
    return root;
}
Node* insertAtEnd(Node* root, int key)
{
    Node* temp = root;
    Node* newNode = new Node(key);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return root;
}
Node* deleteFromBeginning(Node* root)
{
    Node* temp = root;
    temp = temp->next;
    temp->prev = NULL;
    free(root);
    return temp;
}
Node* deleteFromEnd(Node* root)
{
    if (root == NULL) return NULL;
    if (root->next == NULL) return NULL;
    root->next = deleteFromEnd(root->next);
    return root;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node* root = create(a, n);
    print(root);
    cout << "3 inserted at beginning :\n";
    root = insertAtBeginning(root, 3);
    print(root);
    cout << "5 inserted at end :\n";
    root = insertAtEnd(root, 5);
    print(root);
    cout << "node deleted from beginning :\n";
    root = deleteFromBeginning(root);
    print(root);
    cout << "node deleted from end :\n";
    root = deleteFromEnd(root);
    print(root);
    return 0;
}