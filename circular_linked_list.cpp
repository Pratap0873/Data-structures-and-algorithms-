#include<iostream>
using namespace std;


class Node
{
    public:
        int data;
        Node * next;
};

class Clist
{
    Node * head;

    public:

        Clist()
        {
            head=NULL;
        }

        void create();
        void display();
        void insert(int index, int x);
        int length();
        int Delete(int index);

};

void Clist::create()
{
    char ch;

    do
    {
        Node * newnode=new Node;
        cout<<"Enter data of node : ";
        cin>>newnode->data;
        // newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
        }

        else
        {
            Node * p=head;

            while(p->next!=head)
            {
                p=p->next;
            }

            p->next=newnode;
            newnode->next=head;
        }

        cout<<"DO you wan't to continue (Y/N):";
        cin>>ch;

    }while(ch=='y' || ch=='Y');


}


void Clist::display()
{
    Node * p=head;

    do 
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);

    cout<<endl;
}

int Clist::length()
{
    Node * p=head;

    int c=0;
    do
    {
        c++;
        p=p->next;
    } while (p!=head);

    return c;
    
}

// void Clist::insert(int index, int x)
// {
//     Node *p;
//     Node * newnode;

//     // if(index<0 || index>length())
//     // {
//     //     return;
//     // }



//         if(index==0)
//         {

//             newnode=new Node;
//             newnode->data=x;

//             if(head==NULL)
//             {

//                 head=newnode;
//                 head->next=head;
//             }

//             else
//             {
//                 p=head;
//                 while (p->next!=head)
//                 {
//                     p=p->next;
//                 } 

//                 p->next=newnode;
//                 newnode->next=head;
//                 head=newnode;
            
//             }
//         }
 

//         else
//         {
//             p=head;

//             for(int i=0;i<index-1;i++)
//             {
//                 p=p->next;
//             }

//             newnode->next=p->next;
//             p->next=newnode;
//         }

        
    
// }


void Clist::insert(int index, int x)
{
    Node *newnode, *p;
    int l=length();
    if(index < 0 || index>l)
    {
        return;  
    }

    if(index==0)
    {
        newnode=new Node;
        newnode->data=x;

        if(head==NULL)
        {
            head=newnode;
            head->next=head;
        }

        else
        {
            p=head;
            while(p->next!=head)
            {
                p=p->next;
            }

            p->next=newnode;
            newnode->next=head;
            head=newnode;
        }


    }

    else
    {
        p=head;
        newnode=new Node;
        newnode->data=x;

        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }

        newnode->next=p->next;
        p->next=newnode;
    }
}


int Clist::Delete(int index)
{
    Node *p,*q;
    q=NULL;
    int x;

    if(index<0 || index>length())
    {
        return -1;
    }

    else
    {

        if(index==1)
        {
            
            p=head;
            q=p;
            while(p->next!=head)
            {
                p=p->next;
            }

            if(p==head)
            {
                x=head->data;
                delete head;
                head=NULL;
                return x;
            }
            else
            {
                p->next=head->next;
                head=head->next;
                x=q->data;
                delete q;

                return x;
            }

        }

        else
        {
            p=head;

            for(int i=1;i<index;i++)
            {
                q=p;
                p=p->next;
            }

            q->next=p->next;
            x=p->data;
            delete p;

            return x;
        
        }
    }
}



int main()
{
    
    Clist cl;
    cl.create();

    // cl.insert(2,5);
    cl.display();
    cout<<"DELETED "<<cl.Delete(1)<<endl;
    cl.display();


    return 0;
}