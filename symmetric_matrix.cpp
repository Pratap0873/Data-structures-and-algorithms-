#include<iostream>
using namespace std;

class symmetric
{
    int n;
    int * a;

    public:

        symmetric(int n)
        {
            this->n=n;
            a=new int [n*(n+1)/2];

        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();

        ~symmetric()
        {
            delete []a;
        }

};


void symmetric::set(int i, int j , int x)
{
    if(i>=j)
    {
        a[i*(i-1)/2 +j-1]=x;

    }
}

int symmetric::get(int i, int j)
{
    if(i>=j)
    {
        return i*(i-1)/2 +(j-1);
    }

    else
    {
        return j*(j-1)/2 +(i-1);
    }
}



void symmetric::display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
                cout<<a[i*(i-1)/2 +j-1]<<" ";
            }

            if(j>i)
            {
                cout<<a[j*(j-1)/2 +i-1]<<" ";
            }
    
        }

        cout<<endl;
    
    }       
}


int main()
{   
    int d;
    cout<<"Enter dimension "<<endl;
    cin>>d;

    symmetric s(d);

    int x;
    cout<<"Enter all elements "<<endl;

    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            s.set(i,j,x);
        }

    }

    s.display();
    
    return 0;
}







// #include <stdio.h>
// #include <stdlib.h>

// struct Matrix
// {
//     int *B;
//     int n;
// };

// void Set(struct Matrix *m, int i, int j, int y)
// {
//     if (i >= j)
//         m->B[i * (i - 1) / 2 + j - 1] = y;
// }

// int Get(struct Matrix m, int i, int j)
// {
//     if (i >= j)
//         return m.B[i * (i - 1) / 2 + j - 1];
//     else
//         return 0;
// }

// void Display(struct Matrix m)
// {
//     int i, j;

//     printf ("\nMatrix is: \n");

//     for (i = 1; i <= m.n; i++)
//     {
//         for (j = 1; j <= m.n; j++)
//         {
//            if (i >= j)
//              printf ("%d ", m.B[i * (i - 1) / 2 + j - 1]);
//            if (j > i)
//              printf ("%d ", m.B[j * (j - 1) / 2 + i - 1]);
//         }
//         printf ("\n");
//     }
// }

// int main()
// {
//     struct Matrix M;
//     int i, j, y;

//     printf ("Enter Dimension of Matrix: ");
//     scanf ("%d", &M.n);
//     M.B = (int *) malloc (M.n * (M.n + 1) / 2 * sizeof (int));

//     printf ("Enter all the elements of the matrix:\n");
//     for (i = 1; i <= M.n; i++)
//     {
//         for (j = 1; j <= M.n; j++)
//         { 
//            scanf ("%d", &y);
//            Set(&M, i, j, y);
//         }
//     }
//     Display (M);
// }