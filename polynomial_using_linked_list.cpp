#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:

        int coeff;
        int exp;
        Node * next;

};

class sparse
{
    Node *head;

        public:

        sparse()
        {
            head=NULL;
        }
        void create();
        void display();
        double eval(int x);


        sparse operator +(sparse s);
};


void sparse::create()
{

    int i=1;
    char ch;

    do
    {

        
        Node * newnode=new Node;
        cout<<"Enter coefficient of "<<i<<" ";
        cin>>newnode->coeff;
        cout<<"Enter exponent of "<<i<<" ";
        cin>>newnode->exp;
        i++;

        if(head==NULL)
        {
            head=newnode;
            head->next=NULL;
        }

        else
        {
            Node *p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }

            p->next=newnode;
            newnode->next=NULL;
        }

        cout<<"DO Continue (Y/N) : ";
        cin>>ch;

    }while(ch=='Y' || ch=='y');
}



void sparse::display()
{
    Node *p=head;

    while(p!=NULL)
    {
        cout<<p->coeff<<"X"<<p->exp<<"+";
        p=p->next;
    }

    cout<<endl;
}


double sparse::eval(int x)
{
    Node *p=head;
    double result=0;

    while(p!=NULL)
    {
        result+=p->coeff* pow(x,p->exp);
        p=p->next;
    }

    return result;


}


sparse sparse:: operator+(sparse s)
{
    // s.create();

    sparse s1;

    Node *p,*q,*r;
    p=head;
    q=s.head;
    r=s1.head;

    if(head==NULL)
    {
        
        Node *newnode=new Node;


        if(p->exp > q->exp)
        {
            
            newnode->coeff=p->coeff;
            newnode->exp=p->exp;
            newnode->next=NULL;
            r=newnode;
            s1.head=newnode;
            p=p->next;
        }

        else if(p->exp < q->exp)
        {
            newnode->coeff=q->coeff;
            newnode->exp=q->exp;
            newnode->next=NULL;
            r=newnode;
            s1.head=newnode;
            q=q->next;
        }

        else
        {
         

            newnode->coeff=p->coeff+q->coeff;
            newnode->exp=p->exp;
            newnode->next=NULL;
            r=newnode;
            s1.head=newnode;
        }
    



    }

    else
    {

        while(p!=NULL && q!=NULL)
        {    Node *newnode=new Node;


            if(p->exp > q->exp)
            {
                while(r->next!=NULL)
                {
                    r=r->next;
                }
                newnode->coeff=p->coeff;
                newnode->exp=p->exp;
                newnode->next=NULL;
                r->next=newnode;
                r=newnode;
                p=p->next;
            }

            else if(p->exp < q->exp)
            {
                while(r->next!=NULL)
                {
                    r=r->next;
                }
                newnode->coeff=q->coeff;
                newnode->exp=q->exp;
                newnode->next=NULL;
                r->next=newnode;
                r=newnode;
                q=q->next;
            }

            else
            {
                while(r->next!=NULL)
                {
                    r=r->next;
                }

                newnode->coeff=p->coeff+q->coeff;
                newnode->exp=p->exp;
                newnode->next=NULL;
                r->next=newnode;
                r=newnode;
                p=p->next;
                q=q->next;
            }
        }


        while(p!=NULL)
        {
            Node * newnode=new Node;
            newnode->coeff=p->coeff;
            newnode->exp=p->exp;
            r->next=newnode;
            newnode->next=NULL;
            p=p->next;
            r=newnode;
        }

        
        while(q!=NULL)
        {
            Node * newnode=new Node;
            newnode->coeff=q->coeff;
            newnode->exp=q->exp;
            r->next=newnode;
            newnode->next=NULL;
            r=newnode;
            q=q->next;
        }
    }
    return s1;





}





int main()
{
    sparse s;
    s.create();
    s.display();

    // cout<<s.eval(2)<<endl;
    sparse s1;
    s.create();

    sparse s3=s+s1;

    s3.display();
    
    return 0;
}