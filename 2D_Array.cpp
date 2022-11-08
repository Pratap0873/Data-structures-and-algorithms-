#include <iostream>
using namespace std;

int main()
{
    //  1....

    //int a[3][4];

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> a[i][j];
    //     }

    // }

    // cout<<endl<<"OUTPUT"<<endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << a[i][j];
    //     }
    //     cout<<endl;
    // }


    // 2....... 

    // int *b[3];

    // b[0]=new int [4];
    // b[1]=new int [4];
    // b[2]=new int [4];

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> b[i][j];
    //     }

    // }

    // cout<<endl<<"OUTPUT"<<endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    int ** c;

    c=new int *[3];
    c[0]=new int [4];
    c[1]=new int [4];
    c[2]=new int [4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> c[i][j];
        }

    }

    cout<<endl<<"OUTPUT"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << c[i][j]<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}