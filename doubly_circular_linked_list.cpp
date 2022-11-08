#include<iostream>
using namespace std;


class Node 
{
    public:

        int data;
        Node * next;
        Node * prev;
};

class DCL
{
    Node * head;

    public:

        DCL()
        {
            head=NULL;
        }

        void create();
        void display();
        void insert(int index, int x);
        int length();
        int Delete(int index);

};

void DCL::create()
{
    char ch;

    do
    {
        Node * newnode=new Node;
        cout<<"Enter data : ";
        cin>>newnode->data;

        if(head==NULL)
        {
            head=newnode;
            head->next=head;
            head->prev=head;

        }

        else
        {
            Node *p=head->prev;

            newnode->next=head;
            newnode->prev=p;
            head->prev=newnode;
            p->next=newnode;
        }

        cout<<"Do Continue (Y/N) :";
        cin>>ch;
    
    }while(ch=='y' || ch=='Y');

}


void DCL::display()
{
    Node * p=head;

    do 
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);

    cout<<endl;
}


int DCL::length()
{
    int c=0;
    Node * p=head;

    do
    {
        c++;
        p=p->next;
    }while(p!=head);

    return c;
}


void DCL::insert(int index, int x)
{
    Node * newnode;

    if(index<0 || index>length())
    {
        return;
    }

    else
    {
        if(index==0)
        {
            newnode=new Node;
            newnode->data=x;

            if(head==NULL)
            {
                head=newnode;
                head->next=head;
                head->prev=head;
            }

            else
            {
                Node *p=head->prev;

                newnode->next=head;
                newnode->prev=p;
                head->prev=newnode;
                p->next=newnode;
                head=newnode;

            }
        }

        else
        {
            newnode=new Node;
            newnode->data=x;
            Node * p=head;

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


int DCL::Delete(int index)
{
    Node*p;
    int x;

    if(index<0 || index>length())
    {
        return -1;
    }

    else
    {
        if(index==1)
        {

            if(head==NULL)
            {
                x=head->data;
                delete head;
                head=NULL;
                return x;
            }

            else
            {
                p=head;

                head->prev->next=head->next;
                head->next->prev=head->prev;
                x=head->data;
                head=head->next;

                delete p;
                return x;

            }
        }

        else
        {
            p=head;

            for(int i=0;i<index-1;i++)
            {
                p=p->next;
            }

            p->prev->next=p->next;
            p->next->prev=p->prev;
            x=p->data;
            delete p;
            return x;
        }
    }
}


int main()
{
    DCL l;
    l.create();
    l.insert(2,5);
    l.display();
    cout<<l.Delete(2)<<endl;
    l.display();

    return 0;
}