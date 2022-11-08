// #include "queue.h"
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
    t x;

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
    t x;
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
    t x;
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
    t x;

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









/////     Binary tree

class Node 
{
    public:

    int data;
    Node * left;
    Node * right;
};


class tree
{

    public:
        Node * root;

        tree()
        {
            root=NULL;
        }

        void create();
        void preOrderTraversal(Node * p);
        void inOrderTraversal(Node * p);
        void postOrderTraversal(Node * p);

        void IpreOrderTraversal();
        void IinOrderTraversal();
        void IpostOrderTraversal();
        void levelWisetraversal();

        int nodeCount(Node *p);
        int sum(Node *p);
        int degree0(Node *p);
        int degree1(Node *p);
        int degree2(Node *p);

        int height(Node *p);



};

void tree:: create()
{
    Node *newnode;
    Node *p;
    int x;

    Queue <Node *> q(50);

    cout<<"Enter data of root :";
    cin>>x;

    newnode=new Node;
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;

    root=newnode;
    q.enqueue(root);

    cout<<"Enter childs / if not enter -1"<<endl;

    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout<<"Enter left child of "<<p->data<<" : ";
        cin>>x;

        if(x!=-1)
        {
            newnode=new Node;
            newnode->data=x;
            newnode->left=NULL;
            newnode->right=NULL;
            p->left=newnode;
            q.enqueue(newnode);
        }


        cout<<"Enter right child of "<<p->data<<" : ";
        cin>>x;

        if(x!=-1)
        {
            newnode=new Node;
            newnode->data=x;
            newnode->left=NULL;
            newnode->right=NULL;
            p->right=newnode;
            q.enqueue(newnode);
        }
 

    }
}


void tree::preOrderTraversal(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
    }

   
}


void tree::inOrderTraversal(Node *p)
{
    if(p!=NULL)
    {
        inOrderTraversal(p->left);
        cout<<p->data<<" ";
        inOrderTraversal(p->right);
    }

   
}



void tree::postOrderTraversal(Node *p)
{
    if(p!=NULL)
    {
        postOrderTraversal(p->left);
        postOrderTraversal(p->right);
        cout<<p->data<<" ";

    }

   
}



void tree::IpreOrderTraversal()
{
    Node *p=root;
    stack <Node *>st(50);

    while(p!=NULL || !st.isEmpty())
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            st.push(p);
            p=p->left;
        }

        else
        {
            p=st.pop();
            p=p->right;
        }
    }
}



void tree::IinOrderTraversal()
{

    Node *p=root;
    stack <Node *>st(50);

    while(p!=NULL || !st.isEmpty())
    {
        if(p!=NULL)
        {
            st.push(p);
            p=p->left;
        }

        else
        {
            p=st.pop();
            cout<<p->data<<" ";
            p=p->right;
        }
    }
}


// void tree::IpostOrderTraversal()
// {
//     Node *p=root;
//     stack <Node *>st(50);
//     long int temp;

//     while(p!=NULL || !st.isEmpty())
//     {
//         if(p!=NULL)
//         {
//             st.push(p);
//             p=p->left;
//         }

//         else
//         {
//             temp=st.pop();
//             if(temp>0)
//             {
//                 st.push((Node *)-temp);
//                 p=((Node *)temp)->right;

//             }
//             else
//             {
//                 cout<<((Node *)temp)->data;
//                 p=NULL;
//             }
//         }
//     }

// }



void tree::levelWisetraversal()
{
    Node *p=root;
    Queue <Node *> q(50);

    cout<<p->data<<" ";
    q.enqueue(p);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        if(p->left!=NULL)
        {
            cout<<p->left->data<<" ";
            q.enqueue(p->left);
        }

        if(p->right!=NULL)
        {
            cout<<p->right->data<<" ";
            q.enqueue(p->right);
        }
    }
}


int tree::nodeCount(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=nodeCount(p->left);
        y=nodeCount(p->right);
        return x+y+1;
    }

    return 0;
}


int tree::sum(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=sum(p->left);
        y=sum(p->right);

        return x+y+p->data;
    }

    return 0;
}


int tree::degree0(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=degree0(p->left);
        y=degree0(p->right);

        if(p->left==NULL && p->right==NULL)
        {
            return x+y+1;
        }

        else
        {
            return x+y;
        }
    }

    return 0;
}


int tree::degree1(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=degree1(p->left);
        y=degree1(p->right);

        // if(p->left==NULL && p->right!=NULL)
        // {
        //     return x+y+1;
        // }
        // else if(p->left!=NULL && p->right==NULL)
        // {
        //     return x+y+1;
        // }
        if(p->left!=NULL ^ p->right!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }

    return 0;
}


int tree::degree2(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=degree2(p->left);
        y=degree2(p->right);

        if(p->left!=NULL && p->right!=NULL)
        {
            return x+y+1;
        }

        else
        {
            return x+y;
        }
    }

    return 0;
}


int tree::height(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=height(p->left);
        y=height(p->right);

        if(x>y)
        {
            return x+1;
        }
        else
        {
            return y+1;
        }
    }

    return 0;
}


int main()
{
    tree t;
    t.create();
    // cout<<"Preorder traversal "<<endl;
    // t.preOrderTraversal(t.root);
    // cout<<"inorder traversal "<<endl;
    // t.inOrderTraversal(t.root);
    // cout<<"Postorder traversal "<<endl;
    // t.postOrderTraversal(t.root);


    // cout<<"Preorder traversal "<<endl;
    // t.IpreOrderTraversal();
    // cout<<endl;
    // cout<<"inorder traversal "<<endl;
    // t.IinOrderTraversal();


    // cout<<"Level wise traversal "<<endl;
    // t.levelWisetraversal();

    cout<<"No of Nodes : ";
    cout<<t.nodeCount(t.root)<<endl;
    cout<<"Sum of Nodes data : ";
    cout<<t.sum(t.root)<<endl;
    cout<<"No of nodes with degree 0 : ";
    cout<<t.degree0(t.root)<<endl;
    cout<<"No of nodes with degree 1 : ";
    cout<<t.degree1(t.root)<<endl;
    cout<<"No of nodes with degree 2 : ";
    cout<<t.degree2(t.root)<<endl;

    cout<<"Height of tree : ";
    cout<<t.height(t.root)<<endl;





    return 0;
}