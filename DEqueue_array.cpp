#include<iostream>
using namespace std;


class DEq
{
    
    int size;
    int front;
    int rear;
    int *q;

    public:

        DEq(int s)
        {
            size=s;
            front=rear=-1;
            q=new int [size];
        }

        int isEmpty();
        int isFull();

        void rear_enqueue(int x);
        int front_dequeue();
        void front_enqueue(int x);
        int rear_dequeue();
        int first();
        int last();
        void display();


};

int DEq::isEmpty()
{
    if(front==rear)
    {
        return 1;
    }

    return 0;
}


int DEq::isFull()
{
    if(rear==size-1)
    {
        return 1;
    }

    return 0;
}


void DEq::rear_enqueue(int x)
{
    if(isFull())
    {
        cout<<"Queue is Full "<<endl;
    }
    else
    {
        rear++;
        q[rear]=x;
    }
    
}

int DEq::front_dequeue()
{
    int x=-1;

    if(isEmpty())
    {
        cout<<"Queue is Empty"<<endl;
        front=rear=-1;
    }
    else
    {
        front++;
        x=q[front];
    }
    return x;
}


void DEq::front_enqueue(int x)
{
    if(front>-1)
    {
        q[front]=x;
        front--;
    }

    else
    {
        cout<<"FULL"<<endl;
    }
}


int DEq::rear_dequeue()
{
    int x=-1;

    if(isEmpty())
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        x=q[rear];
        rear--;
    }

    return x;
}


int main()
{
    DEq q(5);

    q.rear_enqueue(2);
    q.rear_enqueue(4);
    q.rear_enqueue(6);
    q.rear_enqueue(7);
    q.rear_enqueue(8);


    // cout<<q.front_dequeue()<<endl;
    q.front_enqueue(10);

 
    return 0;
}