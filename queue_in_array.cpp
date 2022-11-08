// #include<iostream>
// using namespace std;

// class Queue
// {
//     int size;
//     int front;
//     int rear;
//     int * q;

//     public:

//     Queue(int s);

//     int isfull();

//     int isempty();

//     void enqueue(int val);

//     int dequeue();

//     int first_val();

//     int last_val();



// };

// Queue:: Queue(int s)
// {
//     size=s;
//     front=rear=-1;
//     q=new int[size];
// }


// int Queue::isfull()
// {
//     if(rear==size-1)
//     {
//         return 1;
//     }

//     else
//     {
//         return 0;
//     }
// }


// int Queue::isempty()
// {
//     if(front==rear)
//     {
//         return 1;
//     }

//     else
//     {
//         return 0;
//     }

// }


// void Queue::enqueue(int val)
// {
//     if(isfull())
//     {
//         cout<<"Queue is overflow "<<endl;
//     }

//     else
//     {
//         rear++;
//         q[rear]=val;
//     }
// }


// int Queue::dequeue()
// {
//     int a=-1;

//     if(isempty())
//     {
//         cout<<"Queue is underflow "<<endl;
//         return a;
//     }

//     else
//     {
//         front++;
//         a=q[front];

//         return a;

//     }
// }



// int Queue::first_val()
// {
//     return q[front+1];
// }

// int Queue::last_val()
// {
//     return q[rear];
// }

// int main()
// {
//     Queue * qu=new Queue(10);

//     qu->enqueue(5);
//     qu->enqueue(7);
//     qu->enqueue(2);
//     qu->enqueue(13);
//     qu->enqueue(33);
//     qu->enqueue(4);

//     cout<<qu->dequeue()<<endl;
//     cout<<qu->dequeue()<<endl;
//     cout<<qu->dequeue()<<endl;
//     cout<<qu->dequeue()<<endl;
//     cout<<qu->dequeue()<<endl;
//     cout<<qu->dequeue()<<endl;
//     cout<<qu->dequeue()<<endl;

    
//     return 0;
//}







