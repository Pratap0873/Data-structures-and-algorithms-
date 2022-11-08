#include<iostream>
using namespace std;

#define size 10


int hashIndex(int key)
{
    return key%size;
}


int hashIndex2(int key)
{
    return 7-(key%7);
}


int probe(int h[], int key)
{
    int index=hashIndex(key);
    
    int i=0;

    while(h[(index+(i*hashIndex2(key)))%10]!=0)
    {
        i++;
    }

    return index+(i*(7-(key%7)));
}



void insert(int h[], int key)
{
    int index=hashIndex(key);

    if(index!=0)
    {
        index=probe(h,key);
    }

    h[index]=key;
}



int search(int h[], int key)
{
    int index=hashIndex(key);

    int i=0;

    while(h[(index+(i*(7-(key%7))))%10]!=key)
    {
        i++;
    }

    return index+(i*(7-(key%7)));
}


int main()
{
    int h[10]={0};

    insert(h,5);
    insert(h,25);
    insert(h,15);
    insert(h,35);
    insert(h,95);
    
    return 0;
}