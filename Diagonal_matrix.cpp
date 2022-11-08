#include<iostream>
using namespace std;

class diagonal
{
    int n;
    int *a;

    public:

        diagonal(int n)
        {
            this->n=n;
            a=new int[n];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();

        ~diagonal()
        {
            delete []a;
        }

};


void diagonal::set(int i, int j, int x)
{
    if(i==j)
    {
        a[i-1]=x;
    }
}

int diagonal::get(int i, int j)
{
    if(i==j)
    {
        return a[i-1];
    }
    else
    {
        return 0;
    }
}



void diagonal::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<a[i]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }

        cout<<endl;
    }
}

int main()
{
    diagonal d(5);
    d.set(1,1,2);
    d.set(2,2,4);
    d.set(3,3,6);
    d.set(4,4,8);
    d.set(5,5,10);

    cout<<d.get(4,4)<<endl;

    d.display();
    
    return 0;
}