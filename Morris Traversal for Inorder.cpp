#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    node(int n) {
        val = n;
        left = NULL;
        right = NULL;
    }
};

void morrisTraversal(node* root)
{
    node* curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            node* predecessor = curr->left;
            while (predecessor->right != curr && predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
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
    cout << "\n";
    morrisTraversal(root);

    return 0;
}