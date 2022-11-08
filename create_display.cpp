#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

        int data;
        Node * next;
};


class link
{
    Node * head;

    public:

        link()
        {
            head=NULL;
        }

        void create();
        void display();
        int length();
        int sum();
        int max();
        Node * search(int x);
        Node * iSearch(int x);
        void insert(int index, int x);
        void sortedInsertion(int x);
        int Delete(int index);
        int isSorted();
        void duplicateElim();
        void reverseEle();
        void reverseLink();
        void concatinate(link & l);
        void merging(link & l2);

        int middleLen();
        int middle();

        ~link();
};


void link::create()
{
    char ch;

    
    do
    {
        Node * newnode= new Node;
        cout<<"Enter data of node :";
        cin>>newnode->data;
        newnode->next=NULL;


        if(head==NULL)
        {
            head=newnode;
        }

        else
        {
            Node *p;
            p=head;

            while(p->next!=NULL)
            {
                p=p->next;
            }

            p->next=newnode;
        }

        cout<<"Do you want to insert more elements (Y/N) :";
        cin>>ch;

    }while(ch=='Y' || ch=='y');
    
}


void link::display()
{
    Node * p=head;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}


int link::length()
{
    int count=0;

    Node * p=head;

    while(p!=NULL)
    {
        count++;
        p=p->next;
    }

    return count;
}


int link::sum()
{
    int sum=0;
    Node * p=head;

    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }

    return sum;
}


int link::max()
{
    Node *p=head;
    int max=INT32_MIN ;

    while (p!=NULL)
    {
        if(p->data > max)
        {
            max=p->data;
            p=p->next;
        }

        p=p->next;
    }

    return max;
    
}

Node * link::search(int x)
{
    Node * p=head;

    int a=0;
    while(p!=NULL)
    {
        if(p->data==x)
        {   
            return p;
        }
        else
        {
            p=p->next;
        }
    }

    return NULL;


}


Node *link::iSearch(int x)
{
    Node *p=head;
    Node * q=NULL;

    while(p!=NULL)
    {
        
        if(p->data==x)
        {
            q->next=p->next;
            p->next=head;
            head=p;
            return p;

        }

        q=p;
        p=p->next;
    }

    return NULL;
}


void link::insert(int index,int x)
{
    int i;

    if(index <0 || index > length())
    {
        return;
    }

    Node * newnode=new Node;
    newnode->data=x;
    newnode->next=NULL;

    Node *p=head;
    // Node * q=NULL;

    if(index==0)
    {
        newnode->next=head;
        head=newnode;
    }

    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }

        newnode->next=p->next;
        p->next=newnode;
    }
    
}

void link::sortedInsertion(int x)
{
    Node * newnode=new Node;
    Node *p=head;
    Node * q=NULL;

    newnode->data=x;
    newnode->next=NULL;

    while(p!=NULL && p->data < x)
    {
        q=p;
        p=p->next;
    }

    if(p==head)
    {
        newnode->next=head;
        head=newnode;
    }

    else
    {
        newnode->next=p;
        q->next=newnode;
    }

}


int link::Delete(int index)
{
    Node * p=head;
    Node *q=NULL;
    int x=-1;

    if(index< 0  || index > length())
    {
        return -1;
    }

    if(index==1)
    {
        p=head;
        head=head->next;
        x=p->data;
        delete p;
        return x;

    }

    else
    {
        for(int i=1;i<index ;i++)
        {
            q=p;
            p=p->next;
        }

            q->next=p->next;
            x=p->data;
            delete p;
            return x;
        
    }

    // return x;
}


int link::isSorted()
{
    Node *p=head;
    int x=INT32_MIN;

    while(p!=NULL )
    {
        if(p->data < x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }

    return 1;
}



void link::duplicateElim()
{
    Node *p=head;
    Node *q=head->next;

    while(q!=NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }

        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}



void link::reverseEle()
{
    int n=length();
    int a[n];
    Node * p=head;

    for(int i=0;i<n;i++)
    {
        a[i]=p->data;
        p=p->next;
    }

    p=head;

    for(int i=n-1;i>=0;i--)
    {
        p->data=a[i];
        p=p->next;
    }
}

void link::reverseLink()
{
    Node *p=head;
    Node *q=NULL;
    Node * r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }

    head=q;
}



void link::concatinate(link & l)
{
    Node * p=head;

    while (p->next!=NULL)
    {
        p=p->next;
    }

    p->next=l.head;
    l.head=NULL;
    
}


void link::merging(link & l2)
{
    Node * p=head;
    Node * q=l2.head;

    Node * r,*last;

    if(p->data < q->data)
    {
        r=last=p;
        p=p->next;
        last->next=NULL;
    }

    else
    {
        r=last=q;
        q=q->next;
        last->next=NULL;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }

        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

    while(p!=NULL)
    {
        last->next=p;
        last=p;
        p=p->next;
        last->next=NULL;
    }

    while(q!=NULL)
    {
        last->next=q;
        last=q;
        q=q->next;
        last->next=NULL;
    }

    head=r;
}


int link::middleLen()
{
    float in =(length()/2)+0.3;
    int index=round(in);

    Node *p=head;

    for(int i=0;i<index;i++)
    {
        p=p->next;
    }

    return p->data;
}


int link::middle()
{
    Node*p, *q;

    p=q=head;

    while(q!=NULL && q->next!=NULL)
    {
        q=q->next;

        if(q!=NULL)
        {
            q=q->next;
        }
        p=p->next;
    }

    return p->data;
}


link ::~link()
{
    Node *p=head;

    while(head!=NULL)
    {
        head=head->next;
        delete p;
        p=head;
    }

    if(length()==0)
    {
        cout<<"DELETED"<<endl;
    }
    else
    {
        cout<<"NOT DELETED"<<endl;
    }
}





int main()
{
    link l1;

    l1.create();
    // link l2;
    // l2.create();
    // l.display();

    // cout<<l.length()<<endl;
    // cout<<l.sum()<<endl;

    // cout<<l.max()<<endl;
    // Node * n;

    // n=l.iSearch(4);

    // if(n!=NULL)
    // {
    //     cout<<"Found "<<n->data<<endl;

    // }
    // else
    // {
    //     cout<<"Not found "<<endl;
    // }


    // l.insert(2,12);
    // l.insert(12,25);
    // l.insert(4,8);
    // l.insert(0,4);
    

    // l.sortedInsertion(3);
    // l.sortedInsertion(4);
    // l.sortedInsertion(7);
    // l.sortedInsertion(2);
    // l.sortedInsertion(1);

    // l.display();
    // l.Delete(3);
    // l.display();

    // cout<<l.isSorted()<<endl;

    // l.duplicateElim();
    // l.reverseEle();
    // l.reverseLink();
    // l.concatinate(l2); 

    // l1.merging(l2);

    // cout<<l1.middle()<<endl;
    l1.Delete(2);
    l1.display();

    return 0;
}