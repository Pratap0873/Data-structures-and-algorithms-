#include<iostream>
using namespace std;


class Node
{
    public:

    int data;
    Node * next;
};

class Queue
{
    Node * front;
    Node * rear;

    public:

        Queue()
        {
            front=rear=NULL;
        }

        int isFull();
        int isEmpty();
        void enqueue(int x);
        int dequeue();
        void display();

        void priority_enqueue(int x);
        


};

int Queue::isFull()
{
    Node * t=new Node;
    if(t==NULL)
    {
        return 1;
    }
    return 0;
}


int Queue::isEmpty()
{
    if(front==NULL)
    {
        return 1;
    }

    return 0;
}


void Queue::enqueue(int x)
{
    Node *newnode;

    if(isFull())
    {
        cout<<"Queue Full"<<endl;
    }

    else
    {
        newnode=new Node;
        newnode->data=x;

        if(front==NULL)
        {
            front=rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
            newnode->next=NULL;

        }


    }
}


int Queue::dequeue()
{
    int x=-1;
    Node *p;

    if(isEmpty())
    {
        cout<<"Queue is Empty"<<endl;
    }

    else
    {
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }

    return x;


}


void Queue::display()
{
    Node *p=front;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}



void priotity_queue()
{
    
}


int main()
{
    
    Queue q;
    
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);

    q.display();
    cout<<q.dequeue()<<endl;


    return 0;
}