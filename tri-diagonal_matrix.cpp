#include<iostream>
using namespace std;

class tri
{
    int n;
    int *a;

    public:

        tri(int n)
        {
            this->n=n;

            a=new int [3*n-2];
        }

        void set(int i, int j, int x);
        int get(int i , int j);
        void display();

        ~tri()
        {
            delete []a;

        }

};

void tri::set(int i, int j, int x)
{
    if((i-j)==1)
    {
        a[i-2]=x;
    }

    else if((i-j)==0)
    {
        a[(n-1)+i-1]=x;
    }

    else if((i-j)==-1)
    {
        a[(2*n-1)+i-1]=x;
    }
}



int tri::get(int i, int j)
{

    if((i-j)==1)
    {
        return a[i-2];
    }

    else if((i-j)==0)
    {
        return  a[(n-1)+i-1];
    }

    else if((i-j)==-1)
    {
        return a[(2*n-1)+i-1];
    }

    else
    {
        return 0;
    }


}

void tri::display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i-j)==1)
            {
                cout<<a[i-2]<<" ";
            }

            else if((i-j)==0)
            {
                cout<<a[(n-1)+i-1]<<" ";
            }

            else if((i-j)==-1)
            {
                cout<<a[(2*n-1)+i-1]<<" ";
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
    int d;
    cout<<"Enter dimensions :";
    cin>>d;

    tri t(d);

    int x;
    cout<<"Enter all elements "<<endl;
    

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