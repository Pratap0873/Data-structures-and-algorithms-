#include<iostream>
using namespace std;

template < class t>

class Queue
{
    int size;
    int front;
    int rear;
    t *q;

    public:

        Queue(int s)
        {
            size=s;
            front=rear=-1;
            q=new t [size];
        }

        int isEmpty();
        int isFull();

        void enqueue(t x);
        t dequeue();
        t first();
        t last();
        void display();
        void priority_insertion1(t x);
        t priority_dequeue1();

        void priority_enqueue2(t x);
        t priority_dequeue2();


};

template < class t>
int Queue<t>::isEmpty()
{
    if(front==rear)
    {
        return 1;
    }

    return 0;
}

template <class t>
int Queue<t>::isFull()
{
    if(rear==size-1)
    {
        return 1;
    }

    return 0;
}


template<class t>
void Queue<t>::enqueue(t x)
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

template <class t>
t Queue<t>::dequeue()
{
    t x=-1;

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

template<class t>
t Queue<t>::first()
{
    t x=-1;
    if(isEmpty())
    {
        cout<<"Queue is Empty"<<endl;
    }

    else
    {
    //     int i=front+1;
        x= q[front+1];
    }

    return x;
}

template<class t>
t Queue<t> ::last()
{
    t x=-1;
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }

    else
    {
        x=q[rear];
    }

    return x;

}

template<class t>
void Queue<t>:: display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<q[i]<<" ";
    }

    cout<<endl;
}



template <class t>
void Queue<t>::priority_insertion1(t x)
{
    if(isFull())
    {
        cout<<"Queue Full"<<endl;
    }
    else
    {
        rear ++;
        q[rear]=x;
    }
}



template <class t>
t Queue<t>::priority_dequeue1()
{
    
    int x=INT_MAX;
    int i,j;
    if(isEmpty())
    {
        cout<<"Empty "<<endl;
    }
    else
    {

        for(i=front+1;i<=rear;i++)
        {
            if(q[i]<x)
            {
                x=q[i];
            }
        }


        // for(j=front+1;j<=rear;j++)
        // {

        // }
        j=front+1;
        while(q[j]!=x)
        {
            j++;
        }

        for(int k=j;k<rear;k++)
        {
            q[k]=q[k+1];

        }
        rear--;

    }

    return x;

    
}


template< class t>
void Queue<t>::priority_enqueue2(t x)
{   
    
    if(isFull())
    {
        cout<<"Full "<<endl;
    }
    else
    {
        // rear++;
        // q[rear]=x;

        // for(i=rear)
        int i=rear;
        while(q[i]<x)
        {
            q[i+1]=q[i];
            i--;
        }

        q[i+1]=x;
        rear++;
    }
}



template<class t>
t Queue<t>::priority_dequeue2()
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
    Queue <int>q(5);

//     q.enqueue(2);
//     q.enqueue(4);
//     q.enqueue(6);
//     q.enqueue(8);
//     q.enqueue(10);
//     // q.enqueue(12);

//     cout<<q.dequeue()<<endl;
//     cout<<q.dequeue()<<endl;
//     cout<<q.dequeue()<<endl;
//     cout<<q.dequeue()<<endl;
//     cout<<q.dequeue()<<endl;
// //    cout<<q.dequeue()<<endl;
//     cout<<endl;
//     q.enqueue(10);

//     // cout<<q.first()<<endl;
//     // cout<<q.last()<<endl;

//     // q.display();


    // q.priority_insertion1(10);
    // q.priority_insertion1(4);
    // q.priority_insertion1(9);
    // q.priority_insertion1(3);
    // q.priority_insertion1(13);
    
    // cout<<q.priority_dequeue1()<<endl;
    // cout<<q.priority_dequeue1()<<endl;
    // cout<<q.priority_dequeue1()<<endl;
    // cout<<q.priority_dequeue1()<<endl;
    // cout<<q.priority_dequeue1()<<endl;
    // cout<<q.priority_dequeue1()<<endl;



    q.priority_enqueue2(10);
    q.priority_enqueue2(4);
    q.priority_enqueue2(9);
    q.priority_enqueue2(3);
    q.priority_enqueue2(13);
    
    cout<<q.priority_dequeue2()<<endl;
    cout<<q.priority_dequeue2()<<endl;
    cout<<q.priority_dequeue2()<<endl;
    cout<<q.priority_dequeue2()<<endl;
    cout<<q.priority_dequeue2()<<endl;
    cout<<q.priority_dequeue2()<<endl;




    return 0;
}