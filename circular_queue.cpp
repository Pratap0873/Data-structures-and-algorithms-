#include<iostream>
using namespace std;

template <class t>
class CQ
{
    int size;
    int front;
    int rear;
    t * q;

    public:

        CQ(int s)
        {
            size=s;
            front=rear=0;
            q=new t [size];
        }

        int isFull();
        int isEmpty();

        void enqueue(t x);
        t dequeue();
        t first();
        t last();
        void display();

};


template <class t>
int CQ<t>::isFull()
{
    if((rear+1)%size == front)
    {
        return 1;
    }

    return 0;
}

template <class t>
int CQ<t>::isEmpty()
{
    if(front==rear)
    {
        return 1;
    }

    return 0;
}


template <class t>
void CQ<t>::enqueue(t x)
{
    if(isFull())
    {
        cout<<"Queue is Full "<<endl;
    }
    else
    {
        rear=(rear+1)%size;
        q[rear]=x;
    }
    
}

template <class t>
t CQ::dequeue()
{
    t x=-1;

    if(isEmpty())
    {
        cout<<"Queue is Empty "<<endl;
    }

    else
    {
        front=(front+1)%size;
        x=q[front];

    }

    return x;

}


void CQ::display()
{
    int i=(front+1)%size;
    
    do 
    {
        cout<<q[i]<<" ";
        i=(i+1)%size;

    }while(i!=(rear+1)%size);



    cout<<endl;
}


int main()
{
    CQ q(5);

    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);

    q.display();    

    cout<<q.dequeue()<<endl;
    q.enqueue(10);

    q.display();


    
    return 0;
}