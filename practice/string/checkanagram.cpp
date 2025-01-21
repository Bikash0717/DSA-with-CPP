#include<iostream>
using namespace std;

int main()
{
    string A="decimal";
    string B="medical";
    int H[26]={0},i;       

    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]+=1;
    }
    for(i=0;B[i]!='\0';i++)
    {
       H[B[i]-97]-=1;
       if(H[B[i]-97]<0)
       {
        cout<<"Not anagram!"<<endl;
        break;
       }
    } 

    if(B[i]=='\0')
    {
        cout<<"Anagram"<<endl;
    }
}