#include<iostream>
#include<string>
#define SIZE 50
using namespace std;

template<class T>

class Stack
{
    int TOP;
    T arr[SIZE];
    public:
      Stack()
      {
        TOP=-1;
      }

      void push(T item)
      {
         
         if(TOP==SIZE-1)
         {
            cout<<"Stack overflow!"<<endl;
         }
         else
         {
           
            TOP++;
            arr[TOP]=item;
         
         }
        
      }
      T pop()
      {
        if(TOP==-1)
        {
            cout<<"Stack underflow!"<<endl;
            return 0;
        }
        else
        {
            return  arr[TOP--];
        }
      }
      int getTop()
      {
        return TOP;
      }
      bool isFull()
      {
        return (TOP>=(SIZE-1));
      }

      bool isEmpty()
      {
        return (TOP==-1);
      }
     

};

bool CheckOperator(char ch)
{
    return((ch=='/'||(ch=='*'))||(ch=='+')||(ch=='-')||(ch=='^'));
}

int evaluate(string ch)
{
    int operandA,operandB;
    Stack<int> s;
    int l=ch.length();
    for(int i=0;i<l;i++)
    {
        if(ch[i]>='0'&&ch[i]<='9')s.push(ch[i]-'0');
        else if(CheckOperator(ch[i]))
        {
            operandA=s.pop();
            operandB=s.pop();

            switch(ch[i])
            {
                case '+':
                s.push(operandB+operandA);
                break;

                case '-':
                s.push(operandB-operandA);
                break;


                case '*':
                s.push(operandB*operandA);
                break;

                case '/':
                s.push(operandB/operandA);
                break;

                default:
                break;
            }
        }
    }
   return s.pop();
}

int main()
{
    
        string exp;
        cout<<"enter the postfix expression : "<<endl;
        cin>>exp;
        cout<<"The evaluated expression is: "<<evaluate(exp)<<endl;
    return 0;
}