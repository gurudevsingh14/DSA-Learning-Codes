#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int freq;
  char ch;
  Node* left;
  Node* right;
  Node(int freq)
  {
    this->freq = freq;
    ch = '*';
    left = NULL;
    right = NULL;
  }
  Node(int freq, int ch)
  {
    this->freq = freq;
    this->ch = ch;
    left = NULL;
    right = NULL;
  }
};
void encoding(Node* root, string path)
{
  if (!root) return;
  if (root->ch != '*')
  {
    cout << root->ch << " : " << path << "\n";
    return;
  }
  encoding(root->left, path + '0');
  encoding(root->right, path + '1');
}
struct compare {

  bool operator()(Node* l, Node* r)
  {
    return (l->freq > r->freq);
  }
};
int main()
{
  cout<<"enter the string : ";
  string s;
  cin >> s;
  n = s.size();
  int freq[26];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < n; i++)
    freq[s[i] - 'a']++;

  priority_queue<Node*, vector<Node*>, compare>q;
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0) {
      Node* temp = new Node(freq[i], (char)(i + 97));
      q.push(temp);
    }
  }
  while ((int)q.size() >= 2)
  {
    Node* first = q.top();
    q.pop();
    Node* second = q.top();
    q.pop();
    int sum = first->freq + second->freq;
    Node* temp = new Node(sum);
    temp->left = first;
    temp->right = second;
    q.push(temp);
  }
  Node* root = q.top();
  q.pop();
  encoding(root, "");
  return 0;
}