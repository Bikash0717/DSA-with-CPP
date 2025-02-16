#include<iostream>
using namespace std;

class Stack
{
    int size,top=-1;
    string s;
    public:
   
    int isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else 
        {

            return 0;
        }
    }
    int isFull()
    {
        if(top==size-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(char value)
    {
        if(isFull())
        {
            cout<<"Stack is full!"<<endl;
            return;
        }
        top++;
        s[top]=value;
        cout<<value<<" is pushed in the stack"<<endl;
        
    }
    
    void pop()
    {
        if(isFull())
        {
            cout<<"Stack is empty!"<<endl;
        }
        
        cout<<s[top]<<" value is popped!"<<endl;
        top--;
    }

    void display()
    {
       for(int i=0;i<=top;i++)
        {
            cout<<s[i]<<" ";
        }
     cout<<endl;
    }

    char peek()
    {
        return s[top];
    }
    int TOP()
    {
        return top;
    }

    string convert(string expr)
    {
    char c;
    string postfix;
    int l=expr.length();

    for(int i=0;i<l;i++)
    {
        if(i==l)
        {
            c=')';
        }
        else
        {
            c=expr[i];
        }
        if(isOperator(c))
        {
            if(isOperator(peek()))
            {
                while(checkPriority(c)>=checkPriority(peek()))
                {
                    postfix+=peek();
                    pop();
                }
            }
            push(c);
        }
        else if(c=='(')
        {
            push(c);
        }
        else if(c==')')
        {
            while(peek()!='(')
            {
                postfix+=peek();
                pop();
            }
            pop();
        }
        else
        {
            postfix+=c;
        }
    }
    while(TOP()!=-1)
    {
        postfix+=peek();
        pop();
    }
return postfix;
    }

    int checkPriority(char ch)
    {
        if((ch=='^'))return 1;
        else if((ch=='/')||ch=='*')return 2;
        else if((ch=='-')||ch=='+')return 3;
        else return 4;    
    }
    bool isOperator(char ch)
    {
        return((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^'));
        
    }
};



int main()
{
Stack s1;
string exp1="a+b*c-(d*e-f/g)^h*i";
string postfix=s1.convert(exp1);
cout<<postfix;
}