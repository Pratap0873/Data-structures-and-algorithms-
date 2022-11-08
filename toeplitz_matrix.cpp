#include<iostream>
using namespace std;


class toeplitz
{
    int n;
    int *a;

    public:

        toeplitz(int n)
        {
            this->n=n;

            a=new int [2*n-1];
        }




        void set(int i, int j, int x);
        int get(int i, int j);
        void display();

        ~toeplitz()
        {
            delete []a;
        }



};

void toeplitz::set(int i, int j, int x)
{
    if(i<=j)
    {
        a[j-i]=x;
    }

    else if(i>j)
    {
        a[n+i-j-1]=x;
    }
}

int toeplitz::get(int i, int j)
{
    if(i<=j)
    {
        return a[j-i];
    }

    else
    {
        return a[n+i-j-1];
    }

}


void toeplitz::display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
            {
                cout<<a[j-i]<<" ";
            }

            else if(i>j)
            {
                cout<<a[n+i-j-1]<<" ";
            }
        }

        cout<<endl;
    }
}






int main()
{
    int d;
    cout<<"Enter dimensions :";
    cin>>d;

    toeplitz t(d);

    int x;
    cout<<"ENter all elements "<<endl;

    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            t.set(i,j,x);
        }
    }

    t.display();
    
    return 0;
}