#include<bits/stdc++.h>
using namespace std;
void heapify(int i, vector<int>&heap, int size)
{
  if (i >= size)
    return;
  int left = i * 2 + 1, right = i * 2 + 2;
  heapify(left, heap, size);
  heapify(right, heap, size);
  int largest = i;
  if (left < size && heap[left] > heap[largest])
    largest = left;
  if (right < size && heap[right] > heap[largest])
    largest = right;
  if (largest != i)
  {
    swap(heap[largest], heap[i]);
  }
}
int deleteNode(vector<int>&heap, int i)
{
  int temp = heap[0];
  swap(heap[0], heap[i]);
  heapify(0, heap, i);
  return temp;
}
void heapSort(vector<int>&heap, int n)
{
  for (int i = 0; i < n; i++)
  {
    heapify(0, heap, i + 1);
  }
  for (int i = n - 1; i >= 0; i--)
  {
    deleteNode(heap, i);
  }
}
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  heapSort(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}