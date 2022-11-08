
//       row -major methd

// #include<iostream>
// using namespace std;

// class lower
// {
//     int n;
//     int * a;

//     public:

//         lower(int n)
//         {
//             this->n=n;
//             a=new int[(n*(n+1))/2];
//         }

//         void set(int i, int j, int x);
//         int get(int i, int j);
//         void display();

//         ~lower()
//         {
//             delete []a;
//         }
// };

// void lower::set(int i, int j, int x)
// {
//     if(i>=j)
//     {
//         a[(i*(i-1))/2 + j-1]=x;
//     }
// }


// int lower::get(int i, int j)
// {
//     if(i>=j)
//     {
//         return a[(i*(i-1))/2 + j-1];

//     }

//     else
//     {
//         return 0;
//     }
// }


// void lower::display()
// {
//     int i,j;

//     for(int i=1;i<=n;i++)
//     {
//         for(j=1;j<=n;j++)
//         {
//             if(i>=j)
//             {
//                 cout<<a[(i*(i-1))/2 + j-1]<<" ";

//             }

//             else
//             {
//                 cout<<"0 ";
//             }
//         }

//         cout<<endl;
//     }
// }



// int main()
// {

//     int d;
//     cout<<"Enter dimensions "<<endl;
//     cin>>d;

//     lower l(d);

//     int x;

//     cout<<"enter all elements "<<endl;
//     for(int i=1;i<=d;i++)
//     {
//         for(int j=1;j<=d;j++)
//         {
//             cin>>x;
//             l.set(i,j,x);

//         }
//     }

//     l.display();


    
//     return 0;
// }





//   column - major




#include<iostream>
using namespace std;

class lower
{
    int n;
    int * a;

    public:

        lower(int n)
        {
            this->n=n;
            a=new int[(n*(n+1))/2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();

        ~lower()
        {
            delete []a;
        }
};

void lower::set(int i, int j, int x)
{
    if(i>=j)
    {
        a[n*(j-1) -  (j-1)*(j-2)/2 +(i-j)]=x;
    }
}


int lower::get(int i, int j)
{
    if(i>=j)
    {
        return a[n*(j-1) -  (j-1)*(j-2)/2 +(i-j)];


    }

    else
    {
        return 0;
    }
}


void lower::display()
{
    int i,j;

    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
            {
                cout<<a[n*(j-1) -  (j-1)*(j-2)/2 +(i-j)]<<" ";


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
    cout<<"Enter dimensions "<<endl;
    cin>>d;

    lower l(d);

    int x;

    cout<<"enter all elements "<<endl;
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            l.set(i,j,x);

        }
    }

    l.display();

    cout<<l.get(3,4);


    
    return 0;
}
