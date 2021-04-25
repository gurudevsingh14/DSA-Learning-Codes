#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;
};
void create(int a[],int n,struct node **head)
{
    int i;
    struct node *first=(struct node*)malloc(sizeof(struct node));
    *head=first;
    first->data=a[0];
    first->next=NULL;
    for(int i=1;i<n;i++)
    {
        struct node *p=(struct node*)malloc(sizeof(struct node));
        p->data=a[i];
        p->next=NULL;
        first->next=p;
        first=p;
    }
}
void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("\n");
}
void deletenode(struct node **head,int key)
{
    struct node *temp=(*head),*prev=(*head);
    if(temp->data==key)
    {
        (*head)=temp->next;
        free(temp);
        return ;
    }
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("node not present\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
}
void insertfirst(struct node **head,int new_data)
{
    struct node *first=(struct node*)malloc(sizeof(struct node));
    first->data=new_data;
    first->next=(*head);
    (*head)=first;
}
void insertlast(struct node **head,int new_data)
{
    struct node *p=(*head);
    struct node *last=(struct node*)malloc(sizeof(struct node));
    last->data=new_data;
    last->next=NULL;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=last;
}
void checksort(struct node *head)
{
    int x=INT_MIN;
    while(head!=NULL)
    {
        if(head->data<x)
        {
            printf("list is unsorted\n");
            return;
        }
        x=head->data;
        head=head->next;
    }
    printf("list is sorted\n");
}
void removeduplicate(struct node **head)
{
    struct node *p=(*head);
    struct node *q=(*head)->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void reverse(struct node **head)
{
    struct node*p=(*head);
    int a[10];
    int i=0;
    while(p!=NULL)
    {
        a[i]=p->data;
        p=p->next;
        i++;
    }
    p=(*head);i--;
    while(i>=0)
    {
        p->data=a[i];
        p=p->next;
        i--;
    }
}
void reverselink(struct node **head)
{
    struct node *p=(*head),*q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    (*head)=q;
}
struct node* removeduplicate2(struct node**h)
{
    struct node*head=*h;
    struct node *p=NULL,*q=NULL,*r=head;
    while(r!=NULL)
    {
        p=q;
        q=r;
        r=r->next;
        if((r->data)==(q->data))
        {
            while(r->data==q->data)
            {
                r=r->next;
            }
            p->next=r;
            q=p;
        }
    }
    return head;
}
void mergelinklist(struct node **f,struct node **s)
{
    struct node *third,*last,*first=(*f),*second=(*s);
    if(first->data<second->data)
        {
            third=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else
        {
            third=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    while(first!=NULL&&second!=NULL)
    {
        if(first->data<second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)//if any one of the pointer is not null
        last->next=first;
    else
        last->next=second;
    (*f)=third;
}
void islinear(struct node *head)
{
    struct node *p=head,*q=head;
    while(q!=NULL&&q->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
        {
            printf("list is non-linear\n");
            return;
        }
    }
    printf("list is linear\n");
}
void makenonlinear(struct node **head)
{
    struct node *p=(*head);
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=(*head);
}
int main()
{
    struct node *head=NULL;
    int a[]={1,3,5,7};

    create(a,4,&head);
    display(head);
    deletenode(&head,1);
    display(head);
    insertfirst(&head,2);
    display(head);
    insertlast(&head,8);
    display(head);
    checksort(head);
    removeduplicate(&head);
    display(head);
    insertfirst(&head,1);
    reverselink(&head);
    display(head);
    reverselink(&head);

    struct node *second=NULL;
    int b[]={2,4,6,8};
    create(b,4,&second);
    mergelinklist(&head,&second);
    display(head);
    makenonlinear(&head);
    islinear(head);
    display(removeduplicate2(&head));
    
    return 0;
}
