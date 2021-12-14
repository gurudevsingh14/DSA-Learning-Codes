#include<bits/stdc++.h>
using namespace std;
class Deque
{
private:
    int s = 100;
    int queue_array[100];
    int front = s / 2 + 1;
    int rear = s / 2;
public:
    int input();
    void push_back();
    void push_front();
    void pop_front();
    void pop_back();
    void print();
};
int Deque::input()
{
    int n;
    cout << "enter a number : ";
    cin >> n;
    return n;
}
void Deque::push_back()
{
    if (rear == s - 1)
    {
        cout << "Overflow\n";
        return;
    }
    int n = input();
    queue_array[++rear] = n;
}
void Deque::push_front()
{
    if (front == 0)
    {
        cout << "Overflow\n";
        return;
    }
    int n = input();
    queue_array[--front] = n;
}
void Deque::pop_front()
{
    if (front > rear)
    {
        cout << "Underflow\n";
        return;
    }
    front++;
}
void Deque::pop_back()
{
    if (front > rear)
    {
        cout << "Underflow\n";
        return;
    }
    rear--;
}
void Deque::print()
{
    if (front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "elements in queue are : ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue_array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    Deque dq;
    int flag = 1;
    while (flag)
    {
        int ch;
        cout << "\n1 : push at back of queue\n";
        cout << "2 : push at front of queue\n";
        cout << "3 : pop from front of queue\n";
        cout << "4 : pop from back of queue\n";
        cout << "5 : print all elements of queue\n";
        cout << "6 : quit\n";
        cout << "Enter your choice : ";
        cin >> ch;
        cout << "\n";
        switch (ch)
        {
        case 1:
            dq.push_back();
            break;
        case 2:
            dq.push_front();
            break;
        case 3:
            dq.pop_front();
            break;
        case 4:
            dq.pop_back();
            break;
        case 5:
            dq.print();
            break;
        case 6:
            flag = 0;
            break;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }
    return 0;
}

