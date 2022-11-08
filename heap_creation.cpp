#include<iostream>
using namespace std;


class Heap
{
    // int *a;
    int size;
    int length;


    public:



        // Heap(int s)
        // {
        //     size=s;
        //     a=new int [size];
        //     length=0;
        // }

        // void arrayInsert(int x)
        // {
        //     a[length]=x;
        //     length++;
        // }
        // // {
        //     cout<<"How many numbers wan't to insert"<<endl;
        //     cin>>length;
        //     cout<<"Enter elements "<<endl;
        //     a[0]=0;

        //     for(int i=1;i<length;i++)
        //     {
        //         cin>>a[i];
        //     }
            
        // }


        void insert(int a[], int n)
        {
            int i=n;
            int temp=a[n];

            while(i>1 && temp>a[i/2])
            {
                a[i]=a[i/2];
                i=i/2;
            }

            a[i]=temp;
            // length++;

        }

        void create(int a[], int l)
        {
            for(int i=2;i<l;i++)
            {
                insert(a, i);
            }
        }

        int Delete(int a[],int n)
        {
            int i,j,x,temp;

            x=a[1];
            a[1]=a[n];
            a[n]=x;
            i=1;
            j=2*i;

            while(j<n-1)
            {
                if(a[j]<a[j+1])
                {
                    j=j+1;
                }

                else if(a[i]<a[j])
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

        void heapSort(int a[])
        {
            for(int i=length;i>1;i--)
            {
                Delete(a,i);
            }
        }



        void display(int a[], int l)
        {
            for(int i=1;i<l;i++)
            {
                cout<<a[i]<<" ";
            }

            cout<<endl;
        }
};



int main()
{
    
    Heap h;


    int a[]={0,10,20,30,25,5,40,35};

    // h.arrayInsert(0);

    // h.arrayInsert(10);
    // h.arrayInsert(20);
    // h.arrayInsert(30);
    // h.arrayInsert(25);
    // h.arrayInsert(5);
    // h.arrayInsert(40);
    // h.arrayInsert(35);

    // // h.arrayInsert();


    h.create(a,7);


    // cout<<"Dleted "<<h.Delete(7)<<endl;

    h.heapSort(a);


    h.display(a,7);



    return 0;
}