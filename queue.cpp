#include<bits/stdc++.h>
using namespace std;
struct Queue
{
    int rear;
    int front;
    int size;
    unsigned capacity;
    int arr[];
};
struct Queue* createqueue(unsigned capacity)
{
    Queue* queue=new Queue();
    queue->front=0;
    queue->size=0;
    queue->rear=capacity-1;
    queue->capacity=capacity;
    queue->arr[capacity]=(int)malloc(sizeof(queue->capacity));
    return queue;
}
void enqueue(Queue * queue,int value)
{
    queue->rear=(queue->rear+1)%(queue->capacity);
    queue->size=queue->size+1;
    queue->arr[queue->rear]=value;
}
int dequeue(Queue* queue)
{   
    int temp=queue->arr[queue->front];
    queue->front=(queue->front+1)%(queue->capacity);
    queue->size=queue->size-1;
    return temp;   
}
bool isfull(Queue *queue)
{
    return (queue->size==queue->capacity);
}
bool isempty(Queue *queue)
{
    return (queue->size==0);
}
int front(Queue *queue)
{
    if(!isempty(queue))
    return queue->arr[queue->front];
    return INT_MIN;
}
int rear(Queue *queue)
{
    if(!isempty(queue))
    return queue->arr[queue->rear];
    return INT_MIN;
}
int main()
{   
    int a[]={10,20,30,40,50,60,70,80,90,100};
    Queue* queue=createqueue(10);
    for(int i=0;i<10;i++)
    {
        enqueue(queue,a[i]);
    }
    cout<<"front : "<<front(queue)<<endl;
    cout<<"rear : "<<rear(queue)<<endl;
    
    cout<<"dequeued : "<<dequeue(queue)<<endl;
    cout<<"front : "<<front(queue)<<endl;
    cout<<"rear : "<<rear(queue)<<endl;

    cout<<"dequeued : "<<dequeue(queue)<<endl;
    cout<<"front : "<<front(queue)<<endl;
    cout<<"rear : "<<rear(queue)<<endl;
    
    return 0;
}