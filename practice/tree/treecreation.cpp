#include<iostream>
using namespace std;

class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};



class Queue
{
    private:
    int front,rear,size;
    Node **Q;
    public:
    Queue(int size)
    {
        this->size=size;
        Q=new Node*[this->size];
        front=rear=-1;
    }

    void enqueue(Node *value)
    {
        if(rear==size-1)
        {
            cout<<"Queue is full!"<<endl;
        }

        else{
        rear++;
        Q[rear]=value;
       
        }
    }

    Node *dequeue()
    {
        Node *x;
        if(front==rear)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else
        {
            x=Q[front+1];
        front++;
        }
         return x; 
    }

    int isEmpty()
    {
        return front==rear;
    }
   

};





class Tree
{
    public:
    Node *root;
    Tree(){root=NULL;}
    void createTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
};

void Tree::createTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    cout<<"Enter the root value: ";
    cin>>x;

    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
p=q.dequeue();
cout<<"Enter left child of "<<p->data<<": ";
cin>>x;
if(x!=-1)
{
    t=new Node;
    t->data=x;
    t->lchild=t->rchild=NULL;
    p->lchild=t;
    q.enqueue(t);
}

cout<<"Enter right child of "<<p->data<<": ";
cin>>x;
if(x!=-1)
{
    t=new Node;
    t->data=x;
    t->lchild=t->rchild=NULL;
    p->rchild=t;
    q.enqueue(t);
}
    }
    
}  

void Tree::Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if(p)
    {
        
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::Inorder(Node *p)
{
    if(p)
    {
        
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
        
    }
}

void Tree::Levelorder(Node *root)
{
    Queue q(100);
     

    cout<<root->data<<" ";
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            q.enqueue(root->rchild);
        }

    }
}

int Tree::Height(Node *root)
{
    int x=0,y=0;
    if(root==0)
    {
        return 0;
    }
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)
    {return x+1;
    }
    else
    {
        return y+1;
    }

}


int main()
{
Tree t;
t.createTree();
cout<<"Preorder: ";
t.Preorder(t.root);
cout<<endl;
cout<<"Postorder: ";
t.Postorder(t.root);
cout<<endl;
cout<<"Inorder: ";
t.Inorder(t.root);
cout<<endl;
cout<<"Levelorder: ";
t.Levelorder(t.root);
cout<<endl;

return 0; 
}