#include<iostream>
#include<cmath>
using namespace std;

class term 
{
    public:
        int coeff;
        int exp;

};

class poly
{
    int n;

    term * t;

    public:

        poly(int n)
        {
            this->n=n;
            t=new term[n];
        }

        friend istream & operator>>(istream & is, poly & p);

        int eval(int x);

        poly operator+(poly & p);

        void display();

        
};


istream & operator>>(istream & is, poly & p)
{
    cout<<"Enter coefficent and power "<<endl;

    for(int i=0;i<p.n;i++)
    {
        cout<<"term no "<<i+1<<endl;
        cin>>p.t[i].coeff>>p.t[i].exp;
    }

    return is;
}


int poly::eval(int x)
{
    int res=0;

    for(int i=0;i<n;i++)
    {
        res+= t[i].coeff * pow(x,t[i].exp);
    }

    return res;
}




poly poly ::operator+(poly & p)
{
    poly * sum=new poly(n+p.n);

    int i, j, k;
    i=j=k=0;

    while(i<n && j<p.n)
    {
        if(t[i].exp > p.t[j].exp)
        {
            sum->t[k++]=t[i++];
        }

        else if(t[i].exp < p.t[j].exp)
        {
            sum->t[k++]= p.t[j++];
        }

        else
        {
            sum->t[k].exp=t[i].exp;
            sum->t[k++].coeff= t[i++].coeff + p.t[j++].coeff;
        }
    }

    for(;i<n;i++)
    {
        sum->t[k++]=t[i++];
    }

    for(;j<p.n;i++)
    {
        sum->t[k++]=p.t[j++];
    }

    sum->n=k;

    return * sum;
}


void poly::display()
{
    int i;

    for(i=0;i<n;i++)
    {
        cout<<t[i].coeff<<"X^"<<t[i].exp<<"+";
    }
    cout<<endl;
}


int main()
{
    poly p(3);

    cin>>p;
    poly p1(4);
    cin>>p1;

    poly sum=p+p1;

    // cout<<sum.eval(1);
    sum.display();
    
    
    return 0;
}