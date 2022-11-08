#include<iostream>
using namespace std;


void single_N_natural(int a[], int length)
{
    int n=a[length-1];
    int s=0;
    int sum=0;

    for(int i=0;i<length;i++)
    {
        s+=a[i];
    }

    sum=(n*(n+1))/2;

    cout<<sum-s<<endl;
}


void single_missing(int a[], int length)
{
    int l=a[0];
    int diff=l-0;

    for(int i=0;i<length;i++)
    {
        if(a[i]-i!=diff)
        {
            cout<<diff+i<<endl;
            break;
        }
    }
}


void multiple_missing(int a[], int length)
{
    int l=a[0];
    int diff=l-0;

    for(int i=0;i<length;i++)
    {
        if(a[i]-i!=diff)
        {
            while(diff<a[i]-i)
            {
                cout<<diff+i<<endl;
                diff++;

            }
        }
    }
}



void multiple_missing_unsorted(int a[], int l, int h, int length)
{
    int b[h];
    for(int i=0;i<h;i++)
    {
        b[i]=0;
    }

    for(int j=0;j<length;j++)
    {
        b[a[j]]++;
    }

    for(int k=l;k<=h;k++)
    {
        if(b[k]==0)
        {
            cout<<k<<endl;
        }
    }
}



int main()
{
    // int a[10]={1,2,3,4,5,7,8,9,10,11};
    // single_N_natural(a,10);

    // int a[10]={4,5,6,7,9,10,11,12,13,14};
    // single_missing(a,10);

    // int a[10]={5,6,8,10,13,17,20,22,25,27};
    // multiple_missing(a,10);

    int a[10]={4,6,1,3,7,11,16,9,19,14};
    multiple_missing_unsorted(a,1,19,10);

    return 0;
}