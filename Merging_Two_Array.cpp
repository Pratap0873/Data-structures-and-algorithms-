#include<iostream>
using namespace std;





void merging(int a[], int  b [],int c[],int l, int m)
{
    


    int i,j,k;
    i=j=k=0;
    
    while(i<l && j<m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }

        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<l)
    {
        c[k]=a[i];
        i++;
        k++;
    }

    while(j<m)
    {
        c[k]=b[j];
        j++;
        k++;
    }

    

}


int * sorted_creation(int l){
   
    int * a=new int [l];
    cout<<"Enter all elements of an array in sorted manner "<<endl;

    for(int i=0;i<l;i++)
    {
        cin>>a[i];
    }

    return a;
}

void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    int * a=sorted_creation(5);
    int *b= sorted_creation(5);

    int *c=new int [10];
    merging(a,b,c,5,5);

    print(c,10);


    return 0;
}