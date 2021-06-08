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
void itrativePreorder(node *root)
{
    stack<node*>s;
    node* temp = root;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            cout << temp->val << " ";
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }
}
void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void itrativeInorder(node* root)
{
    stack<node*>s;
    node* temp = root;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            cout << temp->val << " ";
            s.pop();
            temp = temp->right;
        }
    }
}
void postorder(node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void itrativePostorder(node* root)
{
    stack<node*>s;
    s.push(root);
    stack<node*>ans;
    node* temp = root;
    while (!s.empty())
    {
        temp = s.top();
        ans.push(temp);
        s.pop();
        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    while (!ans.empty()) {
        cout << ans.top()->val << " ";
        ans.pop();
    }
}
void levelorder(node* root)
{
    queue<node*>q;
    node* temp = root;
    q.push(root);
    while (!q.empty())
    {
        cout << temp->val << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        q.pop();
        temp = q.front();
    }
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

        //nodes are labeled level order wise and labeling is identical for each node :-
        cout << "enter value of left and right child of " << count << print(count) << "node : ";

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
    cout << "\nPreorder traversal : \n";
    preorder(root);
    cout << endl;
    itrativePreorder(root);
    cout << endl;

    cout << "\nInorder traversal : \n";
    inorder(root);
    cout << endl;
    itrativeInorder(root);
    cout << endl;

    cout << "\nPostorder traversal : \n";
    postorder(root);
    cout << endl;
    itrativePostorder(root);
    cout << endl;

    cout << "\nLevel order traversal : \n";
    levelorder(root);
    
    return 0;
}


