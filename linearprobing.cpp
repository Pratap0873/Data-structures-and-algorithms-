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

    while(h[(index+i)%size]!=0)
    {
        i++;
    }

    return (index+i)%size;
}

void insert(int h[], int key)
{
    int index;

    index=hashIndex(key);

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

    while(h[(index+i)%size]!=key)
    {
        i++;
    }

    return (index+i)%size;
}

int main()
{
    int h[10]={0};

    insert(h,12);
    insert(h,22);
    insert(h,32);
    insert(h,44);

    cout<<"Index "<<search(h,32)<<endl;
    
    return 0;
}