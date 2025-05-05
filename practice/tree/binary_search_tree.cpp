#include<iostream>

using namespace std;

struct Node 
{
    struct Node *lchild; 
    int data; 
    struct Node *rchild; 
}
*root=NULL;

void insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p;

    if(root==NULL)
    {
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }

    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else
        {
        return;
        }
    }
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data) r->lchild=p;
    else r->rchild=p;


}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            return t;
        }
        else if(key<t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        } 
    }
    return NULL;
}

struct Node *Rinsert(struct Node *p,int key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=Rinsert(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Rinsert(p->rchild,key);
    }
    return p;
}

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node *Inpre(struct Node *p)
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct Node *Insucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node *p,int key)
{
   struct Node *q;
   if(p==NULL)
   {
    return NULL;
   }

   if(p->lchild==NULL && p->rchild==NULL)
   {
    if(p==root)
    {
        root=NULL;

    }
        delete p;
        return NULL;
    
   }
   
   
    if(key<p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
struct Node *temp;    
/* insert(10);
insert(20);
insert(5);
insert(15);
insert(30); */
root=Rinsert(root,10);
Rinsert(root,20);
Rinsert(root,5);
Rinsert(root,15);
Rinsert(root,30);

root=Delete(root,10);

inorder(root);
cout<<endl;

temp=Search(20);
if(temp!=NULL)
{
    cout<<temp->data<<" is found!"<<endl;
}
else
{
     cout<<temp->data<<" is not found!"<<endl;
}

return 0;
}