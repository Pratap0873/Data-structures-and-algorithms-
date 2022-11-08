#include<iostream>
using namespace std;

class myArray
{
    int total_size;
    int use_size;
    int* ptr;

    public:

    myArray(int t_size, int u_size);

    void set_value();

    void show();

    int element_at(int n);

    int indInsertion(int index, int element);

    int unsortedinsertion(int index, int element);

    int sortedDeletion(int index);

    int unsortedDeletion(int index);

    int linearSearch(int element);

    int binarySearch(int element);

    void sort();

    int length();

    void resize(int new_length);

    int max();

    int min();

};

myArray::myArray(int t_size, int u_size)
{
    total_size=t_size;
    use_size=u_size;

    ptr=new int[t_size];
}


//Traversal
void myArray:: set_value()
{
    for(int i=0;i<use_size;i++)
    {
        cout<<"Enter element "<<i<<endl;
        cin>>ptr[i];
    }
}


//Traversal
void myArray:: show()
{   

    for(int i=0;i<use_size;i++)
    {
        cout<<ptr[i]<<" ";
    }
      
    cout<<endl;
}



int myArray::element_at(int n)
{
    for (int i=0;i<use_size;i++)
    {
        return ptr[n];
    }
    
    return -1;
}


int myArray::length()
{
    int count;
    for (int i=0;i<'\0';i++)
    {
        count++;

    }

    return count;
}



//Insertion
int myArray::indInsertion(int index, int element)
{
    if(use_size>=total_size)
    {
        cout<<"Insertion failed"<<endl;
        return 0;
    }

    for(int i=use_size-1;i>=index;i--)
    {
        ptr[i+1]=ptr[i];
    }

    ptr[index]=element;
    use_size++;

    cout<<"success"<<endl;
    show();

    return 1;

}


//Insertion
int myArray::unsortedinsertion(int index, int element)
{
    if(use_size>=total_size)
    {
        return 0;
    }
    
    ptr[use_size+1]=ptr[index];
    ptr[index]=element;

    show();

    return 1;

}


//Deletion
int myArray::sortedDeletion(int index)
{
    if(index>total_size)
    {
        cout<<"Out of capacity"<<endl;
        return 0;
    }

    for(int i=index;i<use_size-1;i++)
    {
        ptr[i]=ptr[i+1];

    }

    use_size--;

    return 1;
}


//Deletion
int myArray::unsortedDeletion(int index)
{
    if(index>total_size)
    {
        cout<<"Out of capacity"<<endl;
        return 0;
    }

    ptr[index]=ptr[use_size-1];
    use_size--;

    return 1;

}



//Searching

int myArray::linearSearch(int element)
{
    for(int i=0;i<use_size;i++)
    {
        if(ptr[i]==element)
        {
            return i;
        }
    }

    return -1;
}


int myArray::binarySearch(int element)
{
    int l,h,mid;
    l=0;
    h=use_size-1;

    while(l<=h)
    {
        mid=(l+h)/2;

        if(ptr[mid]==element)
        {
            return mid;
        }

        else if(ptr[mid]>element)
        {
            h=mid-1;
        }

        else
        {
            l=mid+1;
        }
    }

    return -1;
}


void myArray::sort()
{
    int temp;

    for(int i=0;i<use_size;i++)
    {
        for(int j=i+1;j<use_size;j++)
        {
            if(ptr[i]>ptr[j])
            {
                temp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
            }
        }
    }
}


void myArray::resize(int new_length)
{
    int *ptr1=new int[new_length];

    for(int i=0;i<new_length;i++)
    {
        ptr1[i]=ptr[i];
    }

    delete []ptr;

    ptr=ptr1;
}


int myArray::max()
{
    int max=ptr[0];

    for(int i=0;i<use_size;i++)
    {
        if(ptr[i]>max)
        {
            max=ptr[i];
        }
    }

    return max;
}

int myArray::min()
{
    int min=ptr[0];

    for(int i=0;i<use_size;i++)
    {
        if(ptr[i]<min)
        {
            min=ptr[i];
        }
    }

    return min;
}


int main()
{
    myArray marks(4,4);
    marks.set_value();
    // marks.show();
    // marks.element_at(4);
      
    // marks.unsortedinsertion(1,43);    
     
    // marks.unsortedDeletion(52);
    
    // int index=marks.binarySearch(8);
    // marks.show();
    // marks.sort();
    // marks.show();

    // int length=marks.length();
    // cout<<length;
    
    // marks.resize(10);
    // int length=marks.length();
    // cout<<length;
    
    // int el=marks.element_at(2);
    // cout<<el;

    
    cout<<"MInimum "<<marks.min();
 
    return 0;
}