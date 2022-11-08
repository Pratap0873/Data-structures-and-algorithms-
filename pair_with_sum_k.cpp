#include<iostream>
using namespace std;


void pair_elements(int a[], int length, int sum)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(a[i]+a[j]==sum)
            {
                cout<<a[i]<<"+"<<a[j]<<"="<<sum<<endl;
            }
        }
    }
}


void pair_hash(int a[], int length, int sum)
{
    int max=a[0];
    for(int i=0;i<length;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    int b[max];

    for(int i=0;i<max;i++)
    {
        b[i]=0;
    }

    for(int i=0;i<length;i++)
    {
        if(b[sum-a[i]]!=0)
        {
            cout<<a[i]<<"+"<<sum-a[i]<<"="<<sum<<endl;
        }

        b[a[i]]++;
    }
}



void pair_sorted(int a[], int length, int sum)
{
    int i=0;
    int j=length-1;

    while(i<j)
    {
        if(a[i]+a[j]==sum)
        {
            cout<<a[i]<<"+"<<a[j]<<"="<<sum<<endl;
            i++;j--;
        }

        else if(a[i]+a[j]>sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}



void max_min(int a[], int length)
{
    int min=a[0];
    int max=a[0];

    for(int i=1;i<length;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }

        else if(a[i]>max)
        {
            max=a[i];
        }
    }

    cout<<max<<" "<<min<<endl;
}


int main()
{
    // int a[10]={5,2,6,4,3,47,8,7,10,1};
    // pair_elements(a,10,10);


    // int a[10]={5,2,6,4,3,12,8,7,10,1};
    // pair_hash(a,10,10);


    // int a[10]={3,4,6,7,8,11,12,16,45,47};
    // pair_sorted(a,10,10);

    int a[10]={10,9,8,7,6,5,4,3,2,1};
    max_min(a,10);    
    return 0;
}