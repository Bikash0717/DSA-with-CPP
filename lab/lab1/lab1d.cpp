
#include<iostream>
#include<string>
#define SIZE 20
using namespace std;

class Stack
{
    int TOP;
    char arr[SIZE];
    public:
      Stack()
      {
        TOP=-1;
      }

      void push(char element)
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
      int Size()
      {
        return SIZE;
      }
      int top()
      {
        return TOP;
      }
      char peek()
      {
        return arr[TOP];
      }
     

};



void Check(Stack s, string str)
{
    string postfix;
    char c;
    int l=str.length();
   
    for(int i = 0; i < l; i++) 
    {
       
         c = str[i];
        
        if(c == '('){
            s.push(c);
        }
        else if(c==')')
        {
        if(s.top()!=-1 && s.peek() == '(') {
                s.pop();
            }
            else{
               cout<<"The expression is not correct"<<endl;
               return;
            }
            
        }

    }
    
if(s.top() ==-1) {
    cout<<"The expression is correct";
}
else{
   cout<<"The expression is not correct";
}

    
}


int main()
{
    string infix,prefix,postfix,rev_infix,opentoclose;
    cout<<"Enter the infix expression:"<<endl;
    cin>>infix;
    Stack s;
    
    Check(s,infix);
   
    return 0;
}


