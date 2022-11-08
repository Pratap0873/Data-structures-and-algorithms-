#include<iostream>
using namespace std;


class Node
{
    public:

        int data;
        int height;
        Node *left;
        Node *right;
};

class AVL
{
    public:

        Node *root;

        AVL()
        {
            root=NULL;
        }

        Node * createNode(int data);
        int getHeight(Node *p);
        int getBalancedFactor(Node *p);
        int max(int a, int b);
        Node * Rinsert(Node *p, int key);
        Node * Rrotation(Node * x);
        Node * Lrotation(Node * y);
        Node * Delete(Node *p, int key);

        Node * successor(Node *p);
        Node * predecessor(Node *P);

        Node * DeleteRotatins(Node *p);

        void inorder(Node *p);
};


Node * AVL::createNode(int data)
{
    Node *newnode=new Node;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;

    return newnode;

}


int AVL::getHeight(Node *p)
{
    if(p==NULL)
    {
        return 0;
    }

    return p->height;
}


int AVL::max(int a, int b)
{
    return a>b?a:b;
}


int AVL::getBalancedFactor(Node *p)
{
    if(p==NULL)
    {
        return 0;
    }

    return getHeight(p->left)-getHeight(p->right);
}



Node * AVL::Rrotation(Node * x)
{
    Node * y=x->left;
    Node * t2=y->right;

    y->right=x;
    x->left=t2;

    x->height=max(getHeight(x->left), getHeight(x->right))+1;
    y->height=max(getHeight(y->left), getHeight(y->right))+1;

    if(x==root)
    {
        root=y;
    }

    return y;

}



Node * AVL::Lrotation(Node * y)
{
    Node * x=y->right;
    Node * t2=x->left;

    x->left=y;
    y->right=t2;


    x->height=max(getHeight(x->left), getHeight(x->right))+1;
    y->height=max(getHeight(y->left), getHeight(y->right))+1;


    if(y==root)
    {
        root=x;
    }

    return x;
}

Node * AVL::Rinsert(Node *p, int key)
{
    // Node *newnode=NULL;
    if(p==NULL)
    {

        return createNode (key);
    }

    if(p->data > key)
    {
        p->left=Rinsert(p->left,key);
    }

    else if(p->data < key)
    {
        p->right=Rinsert(p->right,key);
    }

    p->height=max(getHeight(p->left),getHeight(p->right))+1;


    int bf=getBalancedFactor(p);


    //   LL rotation
    if(bf>1 && key < p->left->data)
    {
        return Rrotation(p);
    }

    //   RR rotation

    if(bf <-1 && key > p->right->data)
    {
        return Lrotation(p);
    }

    //   LR rotation

    if(bf>1 && key > p->left->data)
    {
        p->left=Lrotation(p->left);
        return Rrotation(p);
    }

    //    RL rotation

    if(bf<-1 && key < p->right->data )
    {
        p->right=Rrotation(p->right);
        return Lrotation(p);
    }


    return p;


}




Node * AVL::predecessor(Node *p)
{
    p=p->left;

    while(p!=NULL && p->right!=NULL)
    {
        p=p->right;
    }

    return p;
}



Node * AVL::successor(Node *p)
{
    p=p->right;

    while(p!=NULL && p->left!=NULL)
    {
        p=p->left;
    }

    return p;

}


Node * AVL::DeleteRotatins(Node *p)
{

    int bf1=getBalancedFactor(p);
    int bf2=getBalancedFactor(p->left);
    int bf3=getBalancedFactor(p->right);

    // L1
    if(p->left!=NULL && (bf1>1 && bf2==1) )
    {
        return Rrotation(p);
    }
    
    // L-1

    else if(p->left !=NULL && (bf1>1 && bf2==-1))
    {
        p->left=Lrotation(p->left);
        return Rrotation(p);

    }
    //L0

    else if(p->left!=NULL && (bf1>1 && bf2==0))
    {
        return Rrotation(p);
    }

    //  R rotations

    
    //  R1
    else if(p->right!=NULL && (bf1<-1 && bf3==0))
    {
        p->right=Rrotation(p->right);
        return Lrotation(p);
    }

    // R-1
    else if(p->right!= NULL && (bf1<-1 && bf2==-1))
    {
        return Lrotation(p);
    }

    else if(p->right!=NULL && (bf1<-1 && bf3==0))
    {
        return Lrotation(p);
    }

    return p;
            
}








Node * AVL::Delete(Node *p, int key)
{

    Node * pre,*succ;

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


        // return DeleteRotatins(p);

        return NULL;
    }

    else if(p->data > key)
    {
        p->left=Delete(p->left, key);
    }

    else if(p->data < key)
    {
        p->right=Delete(p->right,key);
    }

    else
    {
        if(getHeight(p->left)> getHeight(p->right))
        {
            pre=predecessor(p);
            p->data=pre->data;
            p->left=Delete(p->left,pre->data);
        }

        else
        {
            succ=successor(p);
            p->data=succ->data;
            p->left=Delete(p->left,succ->data);
        }

    }

    // return DeleteRotatins(p);

    //  Rotattions

    // p->height=max(getHeight(p->left)-getHeight)

    //   L rotations

    // int bf1=getBalancedFactor(p);
    // int bf2=getBalancedFactor(p->left);
    // int bf3=getBalancedFactor(p->right);

    // // L1
    // if(p->left!=NULL && (bf1>1 && bf2==1) )
    // {
    //     return Rrotation(p);
    // }
    
    // // L-1

    // else if(p->left !=NULL && (bf1>1 && bf2==-1))
    // {
    //     p->left=Lrotation(p->left);
    //     return Rrotation(p);

    // }
    // //L0

    // else if(p->left!=NULL && (bf1>1 && bf2==0))
    // {
    //     return Rrotation(p);
    // }

    // //  R rotations

    
    // //  R1
    // else if(p->right!=NULL && (bf1<-1 && bf3==0))
    // {
    //     p->right=Rrotation(p->right);
    //     return Lrotation(p);
    // }

    // // R-1
    // else if(p->right!= NULL && (bf1<-1 && bf2==-1))
    // {
    //     return Lrotation(p);
    // }

    // else if(p->right!=NULL && (bf1<-1 && bf3==0))
    // {
    //     return Lrotation(p);
    // }
        
    // return p;
}







void AVL::inorder(Node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

int main()
{
    AVL a;

    a.root=a.Rinsert(a.root,70);
    // a.root=
    a.Rinsert(a.root,60);
    // a.root=
    a.Rinsert(a.root,50);
    // a.root=
    a.Rinsert(a.root,40);
    // a.root=
    a.Rinsert(a.root,30);
    // a.root=
    a.Rinsert(a.root,20);


    a.Delete(a.root,40);



    a.inorder(a.root);



  
    return 0;
}