#include<iostream>
using namespace std;


class Node
{

    public:
        int data;
        Node * prev;
        Node * next;
};

class DL
{
    Node * head;

    public:

        DL()
        {
            head=NULL;
        }

        void create();
        void display();
        void revDisplay();
        void insert(int index, int x);
        int length();
        int Delete(int index);
        void reverse();

};

void DL::create()
{
    char ch;

    do 
    {
        Node * newnode=new Node;
        cout<<"Enter data : ";
        cin>>newnode->data;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            head->prev=NULL;
        }

        else
        {
            Node *p=head;

            while(p->next!=NULL)
            {
                p=p->next;
            }

            p->next=newnode;
            newnode->prev=p;

        }

        cout<<"DO continue (Y/N) :";
        cin>>ch;


    }while(ch=='y' || ch=='Y');



}

void DL::display()
{
    Node * p=head;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    // cout<<p->data;

    cout<<endl;
}


void DL::revDisplay()
{
    Node * p=head;

    while (p->next!=NULL)
    {
        p=p->next;
    }

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }

    // cout<<p->data;

    cout<<endl;
    
}


int DL::length()
{
    Node * p=head;
    int c=0;

    while(p!=NULL)
    {
        c++;
        p=p->next;
    }

    return c;
}


void DL::insert(int index , int x)
{
    Node * newnode, * p;

    if(index< 0 || index > length())
    {
        return;
    }

    else
    {
        if(index==1)
        {
            newnode=new Node;
            newnode->data=x;

            if(head==NULL)
            {
                head=newnode;
                head->prev=NULL;
                head->next=NULL;
            }
            else
            {
                newnode->prev=NULL;
                newnode->next=head;
                head->prev=newnode;
                head=newnode;
            }
        }

        else
        {
            newnode=new Node;
            newnode->data=x;

            p=head;

            for(int i=0;i<index-1;i++)
            {
                p=p->next;
            }

            newnode->next=p->next;
            newnode->prev=p;

            if(p->next!=NULL)
            {
                p->next->prev=newnode;
            }

            p->next=newnode;

        }
    }
}


int DL::Delete(int index)
{
    Node *p;
    int x;

    if(index<0 || index> length())
    {
        return -1;
    }

    else
    {
        if(index==1)
        {
            p=head;
            head=head->next;
            x=p->data;

            if(head!=NULL)
            {
                head->prev=NULL;
            }

            return x;
        }
        else
        {
            p=head;
            for(int i=0;i<index-1;i++)
            {
                p=p->next;
            }

            p->prev->next=p->next;
            if(p->next!=NULL)
            {
                p->next->prev=p->prev;
            }

            x=p->data;
            delete p;
            return x;
        }
    }
}


void DL::reverse()
{
    Node *p=head;
    Node * temp;

    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;

        p=p->prev;

        if(p!=NULL && p->next==NULL)
        {
            head=p;
        }
    }
}


int main()
{
    DL d;

    d.create();
    // d.insert(1,5);
    // d.insert(3,9);
    // d.insert(4,1);
    // d.insert(10,5);

    // cout<<d.Delete(1)<<endl;
    // cout<<d.Delete(3)<<endl;
    // cout<<d.Delete(5)<<endl;
    d.reverse();

    d.display();
    d.revDisplay();
    return 0;
}