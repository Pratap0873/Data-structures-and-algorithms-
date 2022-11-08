// // head recurssion


// #include<iostream>
// using namespace std;

// void fun(int n)
// {
//     if(n>0)
//     {
//         fun(n-1);
//         cout<<n<<" "<<endl;

//     }
// }



// int main()
// {
//     int a=4;
//     fun(a);
    
//     return 0;
// }




//tail recurssion

// #include<iostream>
// using namespace std;

// void fun(int n)
// {
//     if(n>0)
//     {
//         cout<<n<<" "<<endl;

//         fun(n-1);
//     }
// }



// int main()
// {
//     int a=4;
//     fun(a);
    
//     return 0;
//



// //tree recursion

// #include<iostream>
// using namespace std;

// void fun(int n){

//     if(n>0){

//         cout<<n<<" ";

//         fun(n-1);
//         fun(n-1);
//     }
// }


// int main()
// {
//     fun(4);
  


//     return 0;
// }



// //indirect recursion

// #include<iostream>
// using namespace std;

// void fun2(int n);

// void fun1(int n){

//     if(n>0){

//         cout<<n<<" ";
//         fun2(n-1);    
//     }
// }

// void fun2(int n){

//     if(n>1){

//         cout<<n<<" ";
//         fun1(n/2);
//     }
// }

// int main()
// {
//     fun1(20);
//     return 0;
// }



// //nested recursion


// #include<iostream>
// using namespace std;

// int fun(int n){

//     if(n>100){

//         return n-10;
//     }

//     return fun(fun(n+11));
// }

// int main()
// {
//     int n=fun(90);

//     cout<<n;
    
//     return 0;
// }




//examples 


//  1. sum of N naturals numbers

// #include<iostream>
// using namespace std;

// int sumofN(int n){

//     if(n==0){

//         return 0;
//     }
    
//     return sumofN(n-1)+n;
// }

// int main()
// {
//     int r=sumofN(5);

//     cout<<r;
    
//     return 0;
// }




// #include<iostream>
// using namespace std;

// int sum(int n){

//     int s=0;
//     int i=1;

//     while(i<=n){

//         s+=i;
//         i++;
//     }

//     return s;
// }


// int main()
// {
//     int r=sum(5);

//     cout<<r;
    
//     return 0;
// }



//  2. factorial



// #include<iostream>
// using namespace std;

// int fact(int n){

//     if(n==0){

//         return 1;
//     }

//     return fact(n-1)*n;
// }


// int main()
// {
//     int r=fact(4);
//     cout<<r;
//     return 0;
// }



// #include<iostream>
// using namespace std;

// int fact(int n){
//     int fac=1;
//     for(int i=1;i<=n;i++){

//         fac*=i;
//     }

//     return fac;
// }


// int main()
// {
//     int r=fact(4);
//     cout<<r;
    
//     return 0;
// }



//  3. power function



// #include<iostream>
// using namespace std;

// int pow(int m, int n){

//     if(n==0)
//         return 1;

//     if(n%2==0)
//         return pow(m*m,n/2);

//     else
//         return m *pow(m*m,(n-1)/2);
// }


// int Ipow(int n, int m){

//     int r=n;

//     for(int i=1;i<m;i++)
//         r=n*r;

//     return r;
// } 

// int main()
// {
//     int r=Ipow(3,5);
//     cout<<r;
//     return 0;
// }



//    4. Taylor series


// #include<iostream>
// using namespace std;

// double taylorSeries(int x, int n)
// {
//     static double p=1, f=1;
//     double r;

//     if(n==0)
//         return 1;

//     else{

//         r=taylorSeries(x,n-1);
//         p=p*x;
//         f=f*n;

//         return r+p/f;
//     }

// }

// int main()
// {
//     double r=taylorSeries(2,100);

//     cout<<r;
    
//     return 0;
// }




//   5. taylor series using horner's rule


// #include<iostream>
// using namespace std;


// double tay(int x , int n){

//     static double r=1;

//     if(n==0)
//         return r;
    
//     r=1+r*x/n;

//     return tay(x,n-1);

// }

// int main()
// {
//     cout<<tay(1,100);
//     return 0;
// }






// // #include<iostream>
// // using namespace std;

// // double tay(int x, int n){

// //     double r=1;

// //     for(;n>0;n--){

// //         r=1+x*r/n;
        
// //     }

// //     return r;
// // }

// // int main()
// // {
// //     double r=tay(1,100);
// //     cout<<r;
// //     return 0;
// // }




//    6.. Fibbonaci series


// #include<iostream>
// using namespace std;

// int iterFib(int n){

//     int t0=0, t1=1, s=0;

//     for(int i=2;i<=n;i++)
//     {
//         s=t0+t1;
//         t0=t1;
//         t1=s;

//     }

//     return s;
// }


// int recFib(int n){

//     if(n<=1)
//         return n;
    
//     return recFib(n-2) + recFib(n-1);
// }

// int R[10];

// int memoFib(int n)
// {
//     if(n<=1)
//     {
//         R[n]=n;
//         return n;
//     }

//     else
//     {
//         if(R[n-2]==-1)
//         {
//             R[n-2]=memoFib(n-2);
//         }

//         if(R[n-1]==-1)
//         {
//             R[n-1]=memoFib(n-1);
//         }


//     }

//     R[n]=R[n-2]+R[n-1];

//     return R[n-2]+ R[n-1];

// }


// int main()
// {
//     for(int i=0;i<10;i++){

//         R[i]=-1;
//     }
//     cout<<memoFib(7);
    
//     return 0;
// }



//        7......combination formula


// #include<iostream>
// using namespace std;

// int fact(int n){

//     if(n<=1){
//         return 1;
//     }

//     else
//         return fact(n-1)*n;
// }

// int NCR(int n, int r){

//     int num=fact(n);
//     int deno=fact(n-r)*fact(r);

//     return num/deno;

// }

// int combination(int n, int r){

//     if(r==0 || r==n){

//         return 1;
//     }

//     else{

//         return combination(n-1,r-1) + combination(n-1,r);
//     }

// }

// int main()
// {
//     cout<<NCR(5,3);

    
//     return 0;
// }





//  8. .. ...  Tower of Hanoi


#include<iostream>
using namespace std;

void TOH(int n, int A, int B, int C){

    if(n>0){

        TOH(n-1,A,C,B);
        cout<<"From "<<A<<"To"<<C<<endl;
        TOH(n-1,B,A,C);
    }
}


int main()
{
    TOH(3,1,2,3);
    
    return 0;
}