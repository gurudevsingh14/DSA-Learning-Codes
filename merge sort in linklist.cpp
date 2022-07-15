#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* next;
  Node(int data)
  {
    this->data = data;
    next = NULL;
  }
};
Node* createList(int a[], int n)
{
  Node* dummy = new Node(0);
  Node* temp = dummy;
  for (int i = 0; i < n; i++)
  {
    temp->next = new Node(a[i]);
    temp = temp->next;
  }
  return dummy->next;
}
void printList(Node* head)
{
  if (!head) return;
  cout << head->data << " -> ";
  printList(head->next);
}
Node* mergeList(Node* head1, Node* head2)
{
  Node* newHead = new Node(0);
  Node* temp = newHead;
  while (head1 != NULL && head2 != NULL)
  {
    if (head1->data <= head2->data)
    {
      temp->next = head1;
      temp = temp->next;
      head1 = head1->next;
    }
    else
    {
      temp->next = head2;
      temp = temp->next;
      head2 = head2->next;
    }
  }
  if (head1 != NULL)
    temp->next = head1;
  if (head2 != NULL)
    temp->next = head2;
  return newHead->next;
}
Node* mergeSort(Node* head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node* mid = head, * fast = head->next;
  while (fast != NULL && fast->next != NULL)
  {
    mid = mid->next;
    fast = fast->next->next;
  }
  Node* temp = mid->next;
  mid->next = NULL;
  Node* head1 = mergeSort(head);
  Node* head2 = mergeSort(temp);
  temp = mergeList(head1, head2);
  return temp;
}
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  Node* head = createList(a, n);
  head = mergeSort(head);
  printList(head);
  return 0;
}