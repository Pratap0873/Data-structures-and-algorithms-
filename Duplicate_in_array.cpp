#include<iostream>
using namespace std;

void duplicate_sorted(int a[], int length)
{
    int last_duplicate=0;

    for(int i=0;i<length-1;i++)
    {
        if(a[i]==a[i+1] && a[i]!=last_duplicate)
        {
            cout<<a[i]<<endl;
            last_duplicate=a[i];
        }
    }
}


void duplicate_count(int a[], int length)
{
    for(int i=0;i<length-1;i++)
    {
        if(a[i]==a[i+1])
        {
            int j=i+1;

            while(a[i]==a[j])
            {
                j++;
            }

            cout<<a[i]<<" appear for "<<j-i<<" times "<<endl;
            i=j-1;
        }
    }
}



void duplicate_hash(int a[], int length)
{
    int max=a[0];
    for(int i=0;i<length;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    int h=max;
    int b[h];

    for(int i=0;i<=h;i++)
    {
        b[i]=0;
    }

    for(int i=0;i<length;i++)
    {
        b[a[i]]++;
    }

    for(int i=0;i<=h;i++)
    {
        if(b[i]>1)
        {
            cout<<i<<" appears for "<<b[i]<<" times"<<endl;
        }
    }

}


void duplicate_unsorted(int a[], int length)
{
    for(int i=0;i<length-1;i++)
    {
        int count=1;

        if(a[i]!=-1)
        {
            for(int j=i+1;j<length;j++)
            {
                if(a[i]==a[j])
                {
                    count ++;
                    a[j]=-1;
                }
            }
        }
        if(count>1)
        {
            cout<<a[i]<<" appears for "<<count<<" times "<<endl;
        }


        
    }
}


int main()
{
    // int a[10]={1,2,6,6,8,9,9,10,12,12};

    // duplicate_sorted(a,10);


    // int a[10]={1,2,6,6,6,9,12,12,12,12};

    // duplicate_count(a,10);

    // int a[10]={1,2,6,6,6,9,12,12,12,12};

    // duplicate_hash(a,10);
    


    int a[10]={9,4,5,5,3,3,3,7,8,8};
    duplicate_unsorted(a,10);
    
    return 0;
}