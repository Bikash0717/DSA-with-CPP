#include<iostream>
#include<cstring>
using namespace std;

class Stack
{
    int size,top=-1;
    string s;
    public:
    Stack()
    {  
    }
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
       
        top++;
        s[top]=value;
        cout<<value<<" is pushed in the stack"<<endl;
        
    }
    
    void pop()
    {
       
        cout<<s[top]<<"  is popped!"<<endl;
        top--;
    }

    void checkbalance(string expr)
    {
    
        int l=0;
        for(int i=0;expr[i]!='\0';i++)
        {
            l++;
        }
        for(int i=0;i<l;i++)
        {
            if(expr[i]=='(') 
            {
                
                push(expr[i]);
            }
            else if(expr[i]==')')
            {
                   if(isEmpty())
       {
        cout<<"Expression is not correct"<<endl;
        return;
       }
       else
       {
        pop();
       }
            }
            
        }
        if(isEmpty())
        {
            cout<<"Expression is correct!"<<endl;
        }
        else
        {
            cout<<"Expression is not correct!"<<endl;
        }
    }


       void checkbalance2(string expr)
    {
        char x;
        int l=0;
        for(int i=0;expr[i]!='\0';i++)
        {
            l++;
        }
        for(int i=0;i<l;i++)
        {
            if(expr[i]=='(' ||expr[i]=='{'||expr[i]=='[') 
            {
                
                push(expr[i]);
            }
            else if(expr[i]==')'||expr[i]=='}'||expr[i]==']')
            {
                   if(isEmpty())
            {
        cout<<"Expression is not correct"<<endl;
        return;
       }
        
        x=s[top];
        
        if ((expr[i] == ')' && x != '(') ||
                    (expr[i] == ']' && x != '[') ||
                    (expr[i] == '}' && x != '{')) {
                    cout << "Expression is not correct!" << endl;
                    return;
                }
        pop();
       }
                 
        }
        if(isEmpty())
        {
            cout<<"Expression is correct!"<<endl;
        }
        else
        {
            cout<<"Expression is not correct!"<<endl;
        }
    }

    void display()
    {
       for(int i=0;i<=top;i++)
        {
            cout<<s[i]<<" ";
        }
     cout<<endl;
    }


};


int main()
{
Stack s1;

/* string exp="(a+(b-(c+d)-e)";
s1.checkbalance(exp); */

string exp2="(a + [b - {c + d} - e])";
s1.checkbalance2(exp2);

}