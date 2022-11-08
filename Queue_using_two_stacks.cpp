#include<iostream>
using namespace std;




template <class t>

class stack
{
    int size;
    int top;
    t *stk;

    public:

        stack(int s)
        {
            size=s;
            top=-1;
            stk=new t[size];
        }


        int isFull();
        int isEmpty();
        void push(t x);
        t pop();
        t stackTOP();
        t peek(int position);
        void display();


};


template <class t>
int stack<t>:: isFull()
{
    if(top==size-1)
    {
        return 1;
    }

    return 0;
}


template <class t>
int stack<t>::isEmpty()
{
    if(top==-1)
    {
        return 1;
    }

    return 0;
}

template <class t>
void stack<t>::push(t x)
{
    if(isFull())
    {
        cout<<"Stack Overflow "<<endl;
    }
    else
    {
        top++;
        stk[top]=x;
    }
}


template <class t>
t stack<t>::pop()
{
    t x=-1;

    if(isEmpty())
    {
        cout<<"Stack underflow "<<endl;
    }

    else
    {
        x=stk[top];
        top--;
    }

    return x;
}

template <class t>
t stack<t>::stackTOP()
{
    if(top==-1)
    {
        return -1;
    }

    else
    {
        return stk[top];
    }
}


template <class t>
t stack<t>::peek(int position)
{
    if((top-position+1)<0)
    {
        return -1;
    }
    else
    {
        return stk[top-position+1];
    }
}


template <class t>
void stack<t>::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<stk[i]<<" ";
    }

    cout<<endl;
}



void enqueue(int x,stack <int > &s1)
{
    // if(s1.isFull())
    // {
    //     cout<<
    // }

    s1.push(x);

}


int dequeue(stack <int>&s1, stack <int> &s2)
{
    int x=-1;

    if(s2.isEmpty())
    {
        if(s1.isEmpty())
        {
            cout<<"Empty"<<endl;
            return x;
        }
    

        else
        {
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
    }

    return s2.pop();
}



int main()
{
    stack <int> s1(10);
    stack <int> s2(10);

    enqueue(2,s1);
    enqueue(3,s1);
    enqueue(5,s1);
    enqueue(7,s1);
    enqueue(10,s1);

    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;
    cout<<dequeue(s1,s2)<<endl;


    
    return 0;
}