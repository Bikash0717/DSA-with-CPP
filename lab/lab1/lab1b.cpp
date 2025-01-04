 //a+b*c-(d*e-f/g)^h*i
#include<iostream>
#include<string>
#define SIZE 50
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

bool CheckOperator(char ch)
{
    return((ch=='/'||(ch=='*'))||(ch=='+')||(ch=='-')||(ch=='^'));
}

int CheckPriority(char ch)
{
    if((ch=='^'))return 1;
    if((ch=='/')||(ch=='*'))return 2;
    if((ch=='+')||(ch=='-'))return 3;
    else return 4;
}

string ReverseString(string ch)
{
    int l;
    l=ch.length();
    for(int i=0;i<l/2;i++)
    {
        swap(ch[i],ch[l-i-1]);
        
    }
return ch;
}

string OpenToClose(string ch)
{
    int l=ch.length();
    for(int i=0;i<l;i++)
    {
        if(ch[i]==')')
        {
            ch[i]='(';
        }
        else if(ch[i]=='(')
        {
            ch[i]=')';
        }
    }
    return ch;

}

string Convert(Stack s, string str)
{
    string postfix;
    char c;
    int l=str.length();
   
    for(int i = 0; i < l; i++)  
    {
        if(i==l)c=')';
        else c = str[i];
        if(CheckOperator(c)) {
            if(CheckOperator(s.peek()))
            {
            while(CheckPriority(c) >CheckPriority(s.peek()))
            {
                postfix += s.peek();
                s.pop();
            }
            }
            s.push(c);
        }
        else if(c == '('){
            s.push(c);
        }
        else if(c == ')') {
            while(s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.pop();  
        }

        else {
            postfix += c;  
        }
    }
    
while (s.top() !=-1) {
    postfix += s.peek();  
    s.pop();  
}

    return postfix;
}


int main()
{
    string infix,prefix,postfix,rev_infix,opentoclose;
    cout<<"Enter the infix expression:"<<endl;
    cin>>infix;
    Stack s;
    rev_infix=ReverseString(infix);
    opentoclose=OpenToClose(rev_infix);
     
    postfix=Convert(s,opentoclose);
    prefix=ReverseString(postfix);
    cout<<"The equivalent prefix expression is:"<<prefix<<endl;
    return 0;
}



 


//a+b*c-(d*e-f/g)^h*i
/* #include<iostream>
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

bool CheckOperator(char ch)
{
    return((ch=='/'||(ch=='*'))||(ch=='+')||(ch=='-')||(ch=='^'));
}

int CheckPriority(char ch)
{
    if((ch=='^'))return 1;
    if((ch=='/')||(ch=='*'))return 2;
    if((ch=='+')||(ch=='-'))return 3;
    else return 4;
}


string Convert(Stack s, string str)
{
    string postfix;
    char c;
    int l=str.length();
   // if(s.top() == -1) s.push('(');  // Ensure '(' is pushed before processing
    for(int i = 0; i < l; i++)  // Fix loop to iterate correctly
    {
        if(i==l)c=')';
        else c = str[i];
        if(CheckOperator(c)) {
            if(CheckOperator(s.peek()))
            {
            while(CheckPriority(c) >= CheckPriority(s.peek()))
            {
                postfix += s.peek();
                s.pop();
            }
            }
            s.push(c);
        }
        else if(c == '('){
            s.push(c);
        }
        else if(c == ')') {
            while(s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.pop();  // Remove '(' from stack
        }

        else {
            postfix += c;  // Operand
        }
         // cout<<"Test:"<<postfix<<endl;
    }
    // After processing the entire expression:
while (s.top() !=-1) {
    postfix += s.peek();  // Add the operator at the top of the stack to postfix
    s.pop();  // Pop the operator from the stack
}

    return postfix;
}


int main()
{
    string infix,prefix,postfix,rev_infix,opentoclose;
    cout<<"Enter the infix expression:"<<endl;
    cin>>infix;
    Stack s;
    
    postfix=Convert(s,infix);
    cout<<"The equivalent postfix expression is:"<<postfix<<endl;
    return 0;
}











 */