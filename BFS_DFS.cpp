
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


int a[7][7]={

            {0,1,1,0,0,0,0},
            {1,0,1,1,0,0,0},
            {1,1,0,1,0,0,0},
            {0,1,1,0,1,1,0},
            {0,0,0,1,0,1,1},
            {0,0,0,1,1,0,1},
            {0,0,0,0,1,1,0}
};



int visited[7]={0,0,0,0,0,0,0};



void BFS(int i)
{
    int node;
    Queue <int> q(7);

    cout<<i<<" ";
    visited[i]=1;
    q.enqueue(i);

    while(!q.isEmpty())
    {
        node=q.dequeue();

        for(int j=0;j<7;j++)
        {
            if(a[node][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.enqueue(j);
            }
        }
    }

}




void DFS(int i)
{
    cout<<i<<" ";
    visited[i]=1;

    for(int j=0;j<7;j++)
    {
        if(a[i][j]==1 && visited[j]==0)
        {
            DFS(j);
        }
    }
}


int main()
{
    // BFS(6);
    DFS(4);

    return 0;
}