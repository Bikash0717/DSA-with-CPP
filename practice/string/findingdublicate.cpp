#include<iostream>
using namespace std;

int main()
{
    string A="finding";
    /* int H[26]={0},i;        //by hash method

    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]+=1;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            cout<<char(i+97)<<" is repeated "<<H[i]<<" times "<<endl;
            
        }
    } */



   long int H=0,x=0 ;       //by masking and merging method

    for(int i=0;A[i]!='\0';i++)
    {
        x=1;
        int j=A[i ]- 97;
        x=x << j;
    
    if((x & H)>0)
    {
        cout<<A[i]<<" is dublicate"<<endl;
    }
    else
    {
    H=x | H;
    }
    }
}