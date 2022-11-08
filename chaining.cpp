// #include<iostream>
// using namespace std;

// class Node
// {
//     public:

//         int data;
//         Node *next;
// };Node *head;

// void sortedInsertion(Node **h,int x)
// {
//     Node * newnode=new Node;
//     Node *p=*h;
//     Node * q=NULL;

//     newnode->data=x;
//     newnode->next=NULL;

//     if(*h==NULL)
//     {
//         *h=newnode;
//     }

//     else
//     {

//         while(p!=NULL && p->data < x)
//         {
//             q=p;
//             p=p->next;
//         }

//         if(p==*h)
//         {
//             newnode->next=*h;
//             *h=newnode;
//         }

//         else
//         {
//             newnode->next=p;
//             q->next=newnode;
//         }
//     }

// }

// Node * search(Node *p,int x)
// {

//     while(p!=NULL)
//     {
//         if(p->data==x)
//         {
//             return p;
//         }
//         else
//         {
//             p=p->next;
//         }
//     }

//     return NULL;

// }

// int hashIndex(int key)
// {
//     return key%10;
// }

// void HashInsert(Node * H[], int key)
// {
//     int index=hashIndex(key);
//     sortedInsertion(H, key);

// }

// int main()
// {
//     Node * H[10];
//     Node *temp;

//     for(int i=0;i<10;i++)
//     {
//         H[i]=NULL;
//     }

//     HashInsert(H,12);
//     HashInsert(H,53);
//     HashInsert(H,77);

//     temp=search(H[hashIndex(12)],12);

//     cout<<temp->data;

//     return 0;
// }

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int hashIndex(int key)
{
    return key % 10;
}


void Insert(struct Node *H[], int key)
{
    int index = hashIndex(key);
    SortedInsert(&H[index], key);
}
int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;

    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    temp = Search(HT[hashIndex(21)], 21);

    printf("%d ", temp->data);

    return 0;

}