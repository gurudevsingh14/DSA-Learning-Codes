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
void preorderTraverse(node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}
int splitInorder(int inorder[], int start, int end, int data)
{
    for (int i = start; i <= end; ++i)
    {
        if (inorder[i] == data)
            return i;
    }
    return -1;
}
node* generateTreeFromTraversal(int preorder[], int inorder[], int start, int end)
{
    static int preindex = 0;

    if (start > end)
        return NULL;

    node* temp = new node(preorder[preindex++]);

    if (start == end)
        return temp;

    int split = splitInorder(inorder, start, end, temp->val);
    temp->left = generateTreeFromTraversal(preorder, inorder, start, split - 1);
    temp->right = generateTreeFromTraversal(preorder, inorder, split + 1, end);

    return temp;
}
int main()
{
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    // int inorder[] = {2, 5, 6, 10, 12, 14, 15};
    // int preorder[] = {10, 5, 2, 6, 14, 12, 15};
    
    node* t = generateTreeFromTraversal(preorder, inorder, 0, 6);

    preorderTraverse(t);

    return 0;
}
