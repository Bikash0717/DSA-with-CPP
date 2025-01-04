#include<iostream>
#define SIZE 10
using namespace std;

class Stack
{
    int TOP;
    int arr[SIZE];
    public:
      Stack()
      {
        TOP=-1;
      }

      void push(int element)
      {
         
         if(TOP==SIZE-1)
         {
            cout<<"Stack overflow!"<<endl;
         }
         else
         {
            TOP++;
         arr[TOP]=element;
         cout<<element<<": is pushed"<<endl;
         
         }
        
      }
      void pop()
      {
        if(TOP==-1)
        {
            cout<<"Stack underflow!"<<endl;
        }
        else
        {
            cout<<arr[TOP]<<": is popped"<<endl;
            TOP--;
        }
      }

      int peek()
      {
        cout<<arr[TOP]<<endl;
      }
      int Size()
      {
        return TOP+1;
      }

};

int main()
{
    Stack s;
    s.push(45);
    s.pop();
    s.pop();
    for(int i=0;i<SIZE;i++)
    {
        s.push(i);
    }
    s.push(07);
    s.pop();
    return 0;
}