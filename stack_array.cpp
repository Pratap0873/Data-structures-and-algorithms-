#include<iostream>
// #include<bits/stdc++.h>
#include<string.h>
#include<cmath>
using namespace std;


template <class t>

class stack
{
    int size;
    int top;
    t *stk;

    public:

        stack(int s)
        {
            size=s;
            top=-1;
            stk=new t[size];
        }


        int isFull();
        int isEmpty();
        void push(t x);
        t pop();
        t stackTOP();
        t peek(int position);
        void display();


};


template <class t>
int stack<t>:: isFull()
{
    if(top==size-1)
    {
        return 1;
    }

    return 0;
}


template <class t>
int stack<t>::isEmpty()
{
    if(top==-1)
    {
        return 1;
    }

    return 0;
}

template <class t>
void stack<t>::push(t x)
{
    if(isFull())
    {
        cout<<"Stack Overflow "<<endl;
    }
    else
    {
        top++;
        stk[top]=x;
    }
}


template <class t>
t stack<t>::pop()
{
    t x=-1;

    if(isEmpty())
    {
        cout<<"Stack underflow "<<endl;
    }

    else
    {
        x=stk[top];
        top--;
    }

    return x;
}

template <class t>
t stack<t>::stackTOP()
{
    if(top==-1)
    {
        return -1;
    }

    else
    {
        return stk[top];
    }
}


template <class t>
t stack<t>::peek(int position)
{
    if((top-position+1)<0)
    {
        return -1;
    }
    else
    {
        return stk[top-position+1];
    }
}


template <class t>
void stack<t>::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<stk[i]<<" ";
    }

    cout<<endl;
}



int parenthesis(char * ex)
{
    int s=strlen(ex);

    stack <char>st(s);

    for(int i=0;ex[i]!='\0';i++)
    {
        if(ex[i]=='(')
        {
            st.push('(');
        }
        else if(ex[i]==')')
        {
            if(st.isEmpty())
            {
                return 0;
            }

            else
            {
                st.pop();
            }
        }
    }

    if(st.isEmpty())
    {
        return 1;
    }

    return 0;
}



int allParenthesis(char * exp)
{
    int s=strlen(exp);

    stack <char>stk(s);

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            stk.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(stk.isEmpty())
            {
                return 0;
            }
            else
            {
                if(stk.stackTOP()=='(')
                {

                    stk.pop();

                }
                else
                {
                    return 0;
                }
            }
        }

        else if(exp[i]=='}')
        {
            if(stk.isEmpty())
            {
                return 0;
            }
            else
            {
                if(stk.stackTOP()=='{')
                {
                    stk.pop();
                }
                else
                {
                    return 0;
                }
            }


        }

        else if(exp[i]==']')
        {
            if(stk.isEmpty())
            {
                return 0;
            }
            else
            {
                if(stk.stackTOP()=='[')
                {
                    stk.pop();
                }
                else
                {
                    return 0;
                }
            }

        }



    }

    if(stk.isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }

    
}





int isoperand(char a)
{
    if(a=='+' || a=='-' || a=='/' || a=='*')
    {
        return 0;
    }
    else

    {
        return 1;
    }
}

int precedence(char a)
{
    if(a=='*' || a=='/')
    {
        return 2;
    }
    else if(a=='+' || a=='-')
    {
        return 1;
    }
    else
        return 0;
}



char * infToPost(char * inf)
{
    char * postfix=new char[strlen(inf)+1];
    stack <char> stk(strlen(inf));

    int i=0,j=0;

    while(inf[i]!='\0')
    {
        if(isoperand(inf[i]))
        {
            postfix[j]=inf[i];
            i++;j++;
        }

        else{

            if(precedence(inf[i])>precedence(stk.stackTOP()))
            {
                stk.push(inf[i]);
                i++;
            }
            else
            {
                postfix[j++]=stk.pop();
            }
        }
    }

    while(!stk.isEmpty())
    {
        postfix[j++]=stk.pop();
    }

    postfix[j]='\0';

    return postfix;
}




int isoperand2(char a)
{
    if(a=='(' || a==')' || a=='+' || a=='-' || a=='*' || a=='/' || a=='^') 
    {
        return 0;
    }

    return 1;
}

int outprecedence(char a)
{
    if(a=='+' || a=='-')
    {
        return 1;
    }
    else if(a=='*' || a=='/')
    {
        return 3;
    }
    else if(a=='^')
    {
        return 6;
    }
    else if(a=='(')
    {
        return 7;
    }
    else if(a==')')
    {
        return 0;
    }

    return 0;
}



int inprecedence(char a)
{
    if(a=='+' || a=='-')
    {
        return 2;
    }
    else if(a=='*' || a=='/')
    {
        return 4;
    }
    else if(a=='^')
    {
        return 5;
    }
    else if(a=='(')
    {
        return 0;
    }
    // else if(a==')')
    // {
    //     return 0;
    // }

    return 0;

}



char * infixToPostfix(char * infix)
{
    stack <char> stk(strlen(infix));
    char * postfix=new char[strlen(infix)+1];


    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(isoperand2(infix[i]))
        {
            postfix[j++]=infix[i++];
        }

        else
        {
            if(outprecedence(infix[i]) > inprecedence(stk.stackTOP()))
            {
                stk.push(infix[i++]);
            }
            else if(outprecedence(infix[i]) < inprecedence(stk.stackTOP()))
            {
                postfix[j++]=stk.pop();

            }
            else
            {
                stk.pop();
                i++;
            }
        }
    }

    while(!stk.isEmpty())
    {
        postfix[j++]=stk.pop();
    }

    postfix[j]='\0';


    return postfix;

}




float eval(char * postfix)
{
    int a,b;
    a=b=0;

    int result=0;
    stack <int> stk(strlen(postfix));

    int i=0;
    for(i;postfix[i]!='\0';i++)
    {
        if(isoperand2(postfix[i]))
        {
            stk.push(postfix[i]-'0');
        }

        else
        {
            b=stk.pop();
            a=stk.pop();

            switch(postfix[i])
            {
                case '+':
                    result=a+b;
                    stk.push(result);
                    break;
                
                case '-':
                    result =a-b;
                    stk.push(result);
                    break;

                case '/':
                    result =a/b;
                    stk.push(result);
                    break;  

                case '*':
                    result =a*b;
                    stk.push(result);
                    break;                
                    
                case '^':
                    result =pow(a,b);
                    stk.push(result);
                    break;

            }
        }

    }


    return stk.pop();

}


int main()
{
    // stack <char>s(5);

    // s.push('a');
    // s.push('b');
    // s.push('c');
    // s.push('d');
    // s.push('e');
    // s.push(12);

    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;

    // cout<<s.stackTOP()<<endl;
    // cout<<s.peek(2)<<endl;

    // s.display();

    char a[15];
    cout<<"Enter expression "<<endl;
    cin>>a;

    char * postfix=infixToPostfix(a);
    // cout<<postfix<<endl;
    cout<<eval(postfix)<<endl;
    

    return 0;
}