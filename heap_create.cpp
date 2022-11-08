#include<iostream>
using namespace std;


void insert(int a[], int n)
{
    int i,temp;
    i=n;
    temp=a[n];

    while(i>1 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }

    a[i]=temp;
}



int Delete(int a[], int n)
{
    int x=a[1];
    // int d=a[n];
    a[1]=a[n];
    a[n]=x;
    int temp;

    int i=1;
    int j=2*i;

    while(j<n-1)
    {
        if(a[j]< a[j+1])
        {
            j=j+1;
        }

        if(a[i]<a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;

        }
        else
        {
            break;
        }
    }

    return x;
}


int main()
{
    int a[]={0,10,20,30,25,5,40,35};

    for(int i=2;i<=7;i++)
    {
        insert(a,i);
    }

    // for(int i=1;i<=7;i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    // cout<<endl;

    // cout<<Delete(a,7);

    for(int i=7;i>1;i--)
    {
        Delete(a,i);
    }


    for(int i=1;i<=7;i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
    
    return 0;
}