#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int n) {
        val = n;
        left = NULL;
        right = NULL;
    }
};
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
string print(int n)
{
    if (n == 1) return " st (root) ";
    else if (n == 2) return " nd ";
    else if (n == 3) return " rd ";
    else return " th ";
}
int main()
{
    int left, right, r;
    cout << "enter the value of root node : ";
    cin >> r;
    int count = 1;
    queue<node*>q;
    node* root = new node(r);
    node* temp = root, *p;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        cout << "left and right child of " << count << print(count) << "node : ";//labeling of nodes is done level order wise
        cin >> left;//enter -1 if their is no left child
        cin >> right;//enter -1 if their is no right child
        if (left != -1) {
            p = new node(left);
            q.push(p);
            temp->left = p;
        }
        if (right != -1) {
            p = new node(right);
            q.push(p);
            temp->right = p;
        }
        q.pop();
        count++;
    }
    preorder(root);
    return 0;
}
