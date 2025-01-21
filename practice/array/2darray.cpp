#include<iostream>
using namespace std;

int main()
{
    int i,j;
    //Method-1)  completely inside stack
    int A[2][3]={{1,2,3},{4,5,6}}; 

for(i=0;i<2;i++)
{
for(j=0;j<3;j++)
{
    cout<<A[i][j]<<" ";
}
cout<<endl;

}
cout<<endl;
cout<<endl;


//Method-2)  Partially inside stack and partially in heap

int *B[2];   //this is created inside stack
B[0]=new int(3);   //this is created inside heap
B[1]=new int(3);  

for(i=0;i<2;i++)
{
for(j=0;j<3;j++)
{
    cout<<B[i][j]<<" ";
}
cout<<endl;
}

cout<<endl;
cout<<endl;


//Method-3)  Completely inside heap

int **C;   //only this is created inside stack but it points to heap
C=new int*[2];   //inside heap
C[0]=new int(3);   //this is created inside heap
C[1]=new int(3);  

for(i=0;i<2;i++)
{
for(j=0;j<3;j++)
{
    cout<<C[i][j]<<" ";
}
cout<<endl;
}

return 0;
}