#include<iostream>
using namespace std;


class Node
{
    public:

        int data;
        Node * next;
};


class stack
{
    Node * top;

    public:

        stack()
        {
            top=NULL;
        }

        void push(int x);
        int pop();
        int peek(int position);
        int isEmpty();
        int isFull();
        int stackTop();
        int length();
        void display();
        
};


int stack::isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }

    return 0;
}


int stack::isFull()
{
    Node * t=new Node;

    if(t==NULL)
    {
        return 1;
    }

    return 0;

}


int stack::stackTop()
{
    if(top==NULL)
    {
        return -1;
    }

    return top->data;
}

int stack::length()
{
    Node *p=top;

    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }

    return c;
}


void stack::push(int x)
{
    Node * newnode=new Node;

    if(isFull())
    {
        cout<<"stack overflow "<<endl;
    }

    else
    {
        newnode->data=x;
        newnode->next=top;
        top=newnode;
    }
}


int stack::pop()
{
    int x=-1;

    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
    }

    else
    {
        Node *p=top;
        top=top->next;
        x=p->data;
        delete p;
    }

    return x;
}


int stack::peek(int position)
{
    if(position<0 || position >length())
    {
        return -1;
    }

    else
    {
        Node *p=top;
        for(int i=0;i<position-1;i++)
        {
            p=p->next;
        }

        return p->data;
    }
}


void stack::display()
{
    Node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next; 
    }

    cout<<endl;
}








int main()
{
    stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    s.push(12);

    cout<<s.peek(2)<<endl;
    cout<<s.peek(20)<<endl;
    cout<<s.stackTop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;

    s.display();


    return 0;
}