#include<iostream>
// #include<string.h>
using namespace std;



void swap(int &a, int&b)
{
    int temp=a;
    a=b;
    b=temp;
}

class String
{
    char *a;

    public:
    String(char b[]);
    ~String()
    {
        delete [] a;
    }

    void create();

    void display()
    {
        // for(int i=0;a[i]!='\0';i++)
        // {
        //     cout<<a[i];
        // }

        cout<<a;
        cout<<endl;
    }

    int str_length();
    void upperCase();
    void lowerCase();
    void toggleCase();
    void vowel_consonent_count();
    void Words_count();
    void validation();
    void reverse_auxillary_array();
    void reverse();
    void compare(String s);
    void palindrome_auxillary();
    void palindrome();
    void duplicate_comparing();
    void duplicate_hash();
    void duplicate_bitwise();
    void anagram(String b);
    void anagram_hash(String b);
    void permutation( int k);
    void permutation_swap(int l, int  h);

};

String::String(char b[])
{
    a=b;
}


// void String::create()
// {
//     cout<<"Enter a string "<<endl;
//     cin.getline(a,20);
// }


int String::str_length()
{   int i;
    for(i=0;a[i]!='\0';i++)
    {}

    return i;
}


void String::upperCase()
{
    for(int i=0;a[i]!='\0';i++)
    {
        a[i]-=32;
    }
}


void String::lowerCase()
{
    for(int i=0;a[i]!='\0';i++)
    {
        a[i]+=32;
    }
}


void String::toggleCase()
{
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>=65 && a[i]<=90)
        {
            a[i]+=32;
        }

        else if(a[i]>=97 && a[i]<=122)
        {
            a[i]-=32;
        }
    }
}


void String:: vowel_consonent_count()
{
    int i, Vcount=0,Ccount=0;

    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
        {
            Vcount++;
        }

        else if((a[i]>=65 && a[i]<=90) || a[i]>=97 && a[i]<=122)
        {
            Ccount++;
        }
    }

    cout<<"Vowels count "<<Vcount<<endl;
    cout<<"Consonent count "<<Ccount<<endl;
}


void String::Words_count()
{
    int i, word=1;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ' && a[i-1]!=' ')
        {
            word++;
        }
    }

    cout<<"Word count "<<word<<endl;
}


void String::validation()
{
    int i,pause=0;

    for(i=0;a[i]!='\0';i++)
    {
        if(!(a[i]>=65 && a[i]<=90)  && !(a[i]>=97 && a[i]<=122) && !(a[i]>=48 && a[i]<=57))
        {
            pause=1;
            break;
        }
    }

    if(pause==0)
    {
        cout<<"Valid "<<endl;
    }
    else
    {
        cout<<"Invalid"<<endl;
    }
}


void  String::reverse_auxillary_array()
{
    int l=str_length();
    char b[l];

    int i,j;

    for(i=l-1,j=0;i>=0;i--,j++)
    {
        b[j]=a[i];
    }

    // b[j]='\0';
    // // cout<<b;
    for(int k=0;k<l;k++)
    {
        a[k]=b[k];
    }
    // a[i]='\0';

}


void String::reverse()
{
    int i,j;
    char temp;
    int l=str_length();

    for(i=0,j=l-1;i<j;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}


void String::compare(String s)
{
    int i,j;

    for(i=0,j=0;a[i]!='\0', s.a[j]!='\0';i++,j++)
    {
        if(a[i]!=s.a[j])
        {
            break;
        }
    }

    if(a[i]==s.a[j])
    {
        cout<<"Equal "<<endl;
    }

    else if(a[i]> s.a[j])
    {
        cout<<"Greater"<<endl;
    }

    else
    {
        cout<<"Smaller"<<endl;
    }


}


void String::palindrome_auxillary()
{
    int l=str_length();
    char b[l];
    int pause=0;

    int i,j;

    for(i=l-1,j=0;i>=0;i--,j++)
    {
        b[j]=a[i];
    }

    b[j]='\0';

    for(int k=0,l=0;a[k]!='\0',b[l]!='\0';k++,l++)
    {
        if(a[k]!=b[l])
        {
            pause=1;
        }
    }

    if(pause==0)
    {
        cout<<"palindrome "<<endl;
    }
    else
    {
        cout<<"Not palindrome "<<endl;
    }
}


void String::palindrome()
{
    int i,j,pause=0;
    int l=str_length();

    for(i=0,j=l-1;i<j;i++,j--)
    {
        if(a[i]!=a[j])
        {
            pause=1;
        }
    }

    if(pause==0)
    {
        cout<<"palindrome "<<endl;
    }

    else
    {
        cout<<"NOt palindrome "<<endl;
    }


}
    

void String::duplicate_comparing()
{
    for(int i=0;a[i]!='\0';i++)
    {   int count=1;
        if(a[i]!='0')
        {
            for(int j=i+1;a[j]!='\0';j++)
            {
                if(a[i]==a[j])
                {
                    count ++;
                    a[j]='0';
                }
            }
        }

        if(count>1)
        {
            cout<<a[i]<<" occur for "<<count<<" times"<<endl;

        }
    }
}


void String::duplicate_hash()
{
    int h[26];
    for(int i=0;i<26;i++)
    {
        h[i]=0;
    }

    for(int i=0;a[i]!='\0';i++)
    {
        h[a[i]-97]++;
    }

    for(int i=0;i<26;i++)
    {
        if(h[i]>1)
        {
            cout<<char(i+97)<<" occurs "<<h[i]<<" times "<<endl;
        }
    }
}


void String::duplicate_bitwise()
{
    int h=0,x=0;

    for(int i=0;a[i]!='\0';i++)
    {
        x=1;
        x=x<<a[i]-97;

        if((h & x)>0)
        {
            cout<<"Duplicate "<<a[i]<<endl;
        }

        else
        {
            h=h|x;
        }
    }
}


void String::anagram(String b)
{
    int pause;
    if(str_length()!=b.str_length())
    {
        cout<<"Not anagram"<<endl;
    }

    else
    {
        for(int i=0;a[i]!='\0';i++)
        {   
            pause=0;
            for(int j=0;b.a[j]!='\0';j++)
            {
                if(a[i]==b.a[j])
                {
                    pause++;
                }
                
            }

            if(pause==1)
            {
                continue;
            }
            else
            {  
                break;
                
            }



        }

        if(pause==0)
        {
            cout<<"not"<<endl;
        }

        else
        {
            cout<<"yes"<<endl;
        }

    }
}


void String::anagram_hash(String b)
{
    int pause=0;

    if(str_length()!=b.str_length())
    {
        cout<<"Not"<<endl;
    }

    else
    {
        int h[26];
        for(int i=0;i<26;i++)
        {
            h[i]=0;
        }

        for(int i=0;a[i]!='\0';i++)
        {
            h[a[i]-97]++;
        }

        for(int i=0;b.a[i]!='\0';i++)
        {
            h[b.a[i]-97]--;
        }

        for(int i=0;i<26;i++)
        {
            if(h[i]!=0)
            {
                pause=1;
                break;
            }
        }

        if(pause==1)
        {
            cout<<"Not"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }

   
}



void String::permutation( int k)
{
    static int c[10]={0};
    static char result[10];

    if(a[k]=='\0')
    {
        result[k]='\0';
        cout<<result<<endl;
    }
    else
    {
        for(int i=0;a[i]!='\0';i++)
        {
            if(c[i]==0)
            {
                result[k]=a[i];
                c[i]=1;
                permutation(k+1);
                c[i]=0;
            }
        }
    }
    
}


void String::permutation_swap(int l, int h)
{
    int i;

    if(l==h)
    {
        cout<<a<<endl;
    }

    else
    {
        for(i=l;i<=h;i++)
        {
            swap(a[i],a[l]);

            permutation_swap(l+1,h);

            swap(a[i],a[l]);
        }
    }

}



int main()
{    
    char a[20];
    cout<<"Enterstring "<<endl;
    cin.getline(a,20);
    String str1(a);

    // char b[20];
    // cout<<"Enter permutation string "<<endl;
    // cin.getline(b,20);
    // string str2(b);

    // str.create();
    // str.upperCase();
    // str.lowerCase();
    // str.toggleCase();

    // str.vowel_consonent_count();
    // str.Words_count();

    // str.validation();
    // str.reverse_auxillary_array();
    // str.reverse();

    // str1.compare(b);
    // str1.palindrome_auxillary();
    // str1.palindrome();
    // str1.duplicate_comparing();
// "    str1.duplicate_hash();"

    // str.display();
    
    // cout<<sizeof(int);

    // str1.duplicate_bitwise();
    // str1.anagram(b);
    // str1.anagram_hash(b);
    // str1.permutation(0);

    int l=0;
    int h=str1.str_length()-1;
    str1.permutation_swap(l,h);

    return 0;
}