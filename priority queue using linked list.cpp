//less priority Element is kept first
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int priority;
    Node* next;
    Node(int data,int priority)
    {
        this->data = data;
        this->priority = priority;
        next = NULL;
    }
};
class Queue
{
public:
    Node* frontPtr;
    Node* rearPtr;
    Queue()
    {
        frontPtr = NULL;
        rearPtr = NULL;
    }
    void push(int val,int priority);
    void pop();
    void front();
    void rear();
    bool isEmpty();
    void display();
};
bool Queue::isEmpty()
{
    if (frontPtr == NULL && rearPtr == NULL)
        return true;
    else
        return false;
}
void Queue::push(int val, int priority)
{
    Node* newNode = new Node(val,priority);
    if (isEmpty())
    {
        frontPtr = newNode;
        rearPtr = newNode;
    }
    else
    {
        if (priority < frontPtr->priority)
        {
            newNode->next = frontPtr;
            frontPtr = newNode;
        }
        else
        {
            Node* temp = frontPtr;
            Node* prev = frontPtr;
            while (temp != NULL && priority >= temp->priority)
            {
                temp = prev;
                temp = temp->next;
            }
            newNode->next = temp;
            prev->next = newNode;
            if(temp==NULL)
            rearPtr=rearPtr->next;
        }
    }
}
void Queue::pop()
{
    if (!isEmpty())
    {
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        if (frontPtr == NULL)
            rearPtr = NULL;
        free(temp);
        cout << "Element poped successfully!!\n";
    }
    else
    {
        cout << "underflow\n";
    }
}
void Queue::front()
{
    if (!isEmpty())
        cout << frontPtr->data << "\n";
    else
        cout << "Queue is empty\n";
}
void Queue::rear()
{
    if (!isEmpty())
        cout << rearPtr->data << "\n";
    else
        cout << "Queue is empty\n";
}
void Queue::display()
{
    Node* temp = frontPtr;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main()
{
    Queue q;
    int ch, flag = 1;
    while (flag)
    {

        cout << "\n1 : push\n";
        cout << "2 : pop\n";
        cout << "3 : peek front\n";
        cout << "4 : peek rear\n";
        cout << "5 : display queue\n";
        cout << "6 : exit\n";
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int n,data,priority;
            cout<<"enter no. of elements to be inserted : ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cout << "Enter a number and its priority : ";
                cin>>data;
                cin >> priority;
                q.push(data, priority); 
            }
            break;
        case 2:
            q.pop();
            break;
        case 3:
            cout << "front element of queue : ";
            q.front();
            break;
        case 4:
            cout << "rear element of queue : ";
            q.rear();
            break;
        case 5:
            q.display();
            break;
        case 6:
            flag = 0;
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    }
    return 0;
}


