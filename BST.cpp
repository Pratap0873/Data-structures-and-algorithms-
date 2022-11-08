#include<iostream>
// #include<stack>
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
        return NULL;
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



class Node
{
    public:

        int data;
        Node * left;
        Node * right;
};

class BST
{
    public:

        Node * root;

        BST()
        {
            root=NULL;
        }

        void create(int data);
        void insert(int data);
        Node * Rcreate(Node *p, int key);
        void inorder(Node *p);
        Node * Rsearch(Node * p, int key);
        Node * Isearch(int key);

        int height(Node *p);
        Node * predecessor(Node *p);
        Node * successor(Node *p);

        Node * Delete(Node *p, int key);
        void bstFromPreorder(int a[], int n);
};


void BST::create(int data)
{
    Node * newnode;
    Node *p=root;
    Node *q;

    if(root==NULL)
    {
        newnode=new Node;
        newnode->data=data;
        newnode->left=newnode->right=NULL;
        root=newnode;
    }

    else
    {
        while(p!=NULL)
        {
            q=p;
            
            if(p->data == data)
            {
                return;
            }

            else if(p->data > data)
            {
                p=p->left;
            }
            else
            {
                p=p->right;
            }
        }

        newnode =new Node;
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;

        if(q->data > newnode->data)
        {
            q->left=newnode;
        }
        else
        {
            q->right=newnode;
        }
    }
}



void BST::insert(int data)
{
    Node * newnode;
    Node *p=root;
    Node *q;
    while(p!=NULL)
    {
        q=p;            
        if(p->data == data)
        {
            return;
        }

       else if(p->data > data)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
   }

    newnode =new Node;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    if(q->data > newnode->data)
    {
        q->left=newnode;
    }
    else
    {
        q->right=newnode;
    }
}


Node * BST::Rcreate(Node *p, int key)
{
    Node *newnode=NULL;

    if(p==NULL)
    {
        newnode=new Node;
        newnode->data=key;
        newnode->left=newnode->right=NULL;
        return newnode;
    }

    else if(p->data > key)
    {
        p->left=Rcreate(p->left,key);
    }
    else if(p->data < key)
    {
        p->right=Rcreate(p->right, key);
    }

    return p;
}



Node * BST::Rsearch(Node *p, int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    else if(p->data==key)
    {
        return p;
    }
    else if(p->data > key)
    {
        return Rsearch(p->left, key);
    }
    else
    {
        return Rsearch(p->right, key);
    }
}



void BST::inorder(Node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }

   
}


Node * BST::Isearch(int key)
{
    Node *p=root;

    while(p!=NULL)
    {
        if(p->data==key)
        {
            return p;
        }
        else if(p->data > key)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }

    return NULL;
}


int BST::height(Node *p)
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


Node * BST::predecessor(Node *p)
{
    p=p->left;

    while(p!=NULL && p->right!=NULL)
    {
        p=p->right;
    }

    return p;
}



Node * BST::successor(Node *p)
{
    p=p->right;

    while(p!=NULL && p->left!=NULL)
    {
        p=p->left;
    }

    return p;
}



Node * BST::Delete(Node *p, int key)
{
    Node *pred, * succ;

    if(p==NULL)
    {
        return NULL;
    }

    else if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
        {
            root=NULL;

        }

        delete p;
        return NULL;
    }

    else if(p->data > key)
    {
        p->left=Delete(p->left,key);
    }
    else if(p->data < key)
    {
        p->right=Delete(p->right,key);
    }

    else
    {
        if(height(p->left) > height(p->right))
        {
            pred=predecessor(p);
            p->data=pred->data;
            p->left=Delete(p->left,pred->data);

        }

        else
        {
            succ=successor(p);
            p->data=succ->data;
            p->right=Delete(p->right,succ->data);
        }
    }

    return p;

}


void BST::bstFromPreorder(int a[], int n)
{
    Node *p;
    Node * newnode;
    int i=0;

    stack <Node *> st(50);
    newnode =new Node;
    newnode->data=a[i++];
    newnode->left=newnode->right=NULL;
    root=newnode;
    p=root;

    while(i<n)
    {
        if(p->data > a[i])
        {
            newnode=new Node;
            newnode->data=a[i++];
            newnode->left=newnode->right=NULL;
            p->left=newnode;
            st.push(p);
            p=newnode;
        }

        else if(a[i] > p->data && a[i]<st.stackTOP()->data)
        {
            newnode=new Node;
            newnode->data=a[i++];
            newnode->left=newnode->right=NULL;
            p->right=newnode;
            p=newnode;
        }
        else
        {
            p=st.pop();
        }
    }
}


int main()
{
    BST b;
    // b.root=b.Rcreate(b.root,20);
    // b.Rcreate(b.root,30);
    // b.Rcreate(b.root,10);
    // b.Rcreate(b.root,15);
    // b.Rcreate(b.root,25);

    int a[8]={10,8,5,9,20,15,25,35};

    b.bstFromPreorder(a,8);

    // b.insert(8);
    // b.insert(35);
    // b.insert(21);

    // b.Delete(b.root,15);

    // Node *t=b.Isearch(15);
    // if(t!=NULL)
    // {
    //     cout<<t->data<<" is found "<<endl;
    // }
    // else
    // {
    //     cout<<"Not found "<<endl;
    // }

    b.inorder(b.root);
    
    return 0;
}