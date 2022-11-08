#include<iostream>
using namespace std;

#define size 10


int hashIndex(int key)
{
    return key%size;
}

int probe(int h[], int key)
{
    int index=hashIndex(key);
    int i=0;

    while(h[(index+i*i)%10]!=0)
    {
        i++;
    }

    return (index+i*i)%10;
}


void insert(int h[], int key)
{
    int index=hashIndex(key);

    if(h[index]!=0)
    {
        index=probe(h,key);
    }

    h[index]=key;
}


int search(int h[], int key)
{
    int index=hashIndex(key);

    int i=0;

    while(h[(index+i*i)%10]!=key)
    {
        i++;
    }

    return (index+i*i)%10;
}

int main()
{
    int h[10]={0};

    insert(h,23);
    insert(h,43);
    insert(h,13);
    insert(h,27);

    cout<<"Index "<<search(h,43)<<endl;
    
    return 0;
}