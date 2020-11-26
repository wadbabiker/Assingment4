/*
    Mohamed Babiker Osman
    Computer Engineering
    Second Class
*/
#include <iostream>
#include <malloc.h>
#define  maxSize 10
#define null 0
using namespace std ;
// تعريف صنف المكدس
class stackApp
{
    private :
        int stackArray [maxSize];
        int index  ;
    public :
        stackApp () 
        {
            index = -1 ;
        }
        void push (int element)
        {
            if ( index == maxSize)
            {
                cout<<"Stack is Full! \n";
            }
            else
            {        
                index ++ ;
                stackArray [index] = element ;
            }
        }
        void pop ()
        {
            if ( index == -1)
            {
                cout<<"Stack is Empty !\n";
            }
            else
            {
                index -- ;
            }
        }
        void show()
        {
            for (int i = 0; i <= index; i++)
            {
                cout<<  stackArray[i]<<endl ;
            }
        }
};
// (Queue) تعريف صنف الـ
class Queue
{
    private:
        int queueArray [maxSize] ;
        int rear ;
        int front ;
    public :
        Queue(){
            rear = -1 ;
            front = -1 ;
        }
        void push (int element)
        {
            if ( rear == maxSize-1)
            {
                cout<<"Queue is Full! \n";
            }
            else
            {        
                queueArray [++rear] = element ;
            }
        }
        void pop ()
        {
            if ( front == rear)
            {
                cout<<"Queue is Empty !\n";
            }
            else
            {
                queueArray [front++] ;
            }
        }
         void show()
        {
            if (front == rear)
            {
                cout<<" Queue is Empty !\n" ;
            }
            else{
                for (int i = front; i < rear; i++)
                {
                    cout<<queueArray[i]<<"\n" ;
                }
            }
        }
};
// LinkedList تعريف دوال الـ
struct node
    {
        int data ;
        node *next ;    
    };
class LinkedList
{
    private :   
        node *head , *tail ;
    public :
        LinkedList ()
        {
            head = NULL ;
            tail = NULL ;
        }
        void add( int n )
        {
            node * tmp = new node ;
            tmp -> data = n;
            tmp -> next = NULL ;
            if (head == NULL)
            {
                head = tmp ;
                tail = tmp ;
            }
            else 
            {
                tail ->next=tmp ;
                tail = tail ->next ;
            }            
        }  
        void show (){
            node * tmp  ;
            tmp = head ;
            while ( tmp!= NULL)
            {
                cout<< tmp -> data <<" ";
                tmp = tmp-> next;
            }
        }
        node* gethead(){ return head ; }
        void front( int n ){
            node *tmp = new node;
            tmp ->data = n ;
            tmp ->next = head ;
            head = tmp ;
        }
        void after( node *a , int value){
            node* p = new node ;
            p -> data = value ;
            p -> next = a ->next ;
            a ->next = p ;
        }
        void remove ( node *before_del)
        {
            node *tmp;
            tmp = before_del ->next;
            before_del ->next=tmp->next;
            delete tmp ;
        }
};
    
int main()
{
    stackApp stack ;
    Queue queue ;
    LinkedList linkedlist ;
    int number , element ;
    cout<<" 1- stack   2- Queue 3- LinkedList "<<"\n";
    cout<<"Choose a number to insert your data...";
    cin>>number;
    switch (number)
    {
    case 1:
        cout<<"Enter 5 number to Stack..\n";
        for (int i = 0; i < 5; i++)
        {
            cin>>element;
            stack.push(element);
        }
        cout<<"=== Stack ====\n";
        stack.show();
        break;
    case 2:
        cout<<"Enter 5 number to Queue..\n";
        for (int i = 0; i < 5; i++)
        {
            cin>>element;
            queue.push(element);
        }
        cout<<"=== Queue ===\n";
        queue.show();
    case 3:
        cout<<"Enter 5 number to LinkedList..\n";
        for (int i = 0; i < 5; i++)
        {
            cin>>element;
            linkedlist.add(element);
        }
        cout<<"=== Linked List ===\n";
        linkedlist.show();
        cout<<"\n";
        default:
            cout<<"Sorry ! try again...";
        break;
    }
  
}

