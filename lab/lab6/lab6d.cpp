//a)

/* #include<iostream>
using namespace std;

int fact(int n, int facts)  
{
    if (n == 0) 
    {
        return facts;
    }
    else
    {
        return fact(n - 1, facts * n); 
    }
}

int main()
{
    int n, r;
    cout << "Enter the n: ";
    cin >> n;
    r = fact(n, 1);  
    cout << "The factorial of " << n << " is: " << r << endl;
    return 0;
} */







//b



/* #include<iostream>
using namespace std;

int fibTailRecursive(int n, int a = 0, int b = 1)  {
    if (n == 0)
    {
        return a;  
    }
    if (n == 1)
    {
        return b;  
    }
    
    
    return fibTailRecursive(n - 1, b, a + b);
}

int main()
{
    int n, r;
    cout << "Enter the n: ";
    cin >> n;

    r = fibTailRecursive(n);  
    cout << "The Fibonacci number at position " << n << " is: " << r << endl;
    
    return 0;
} */



//c)

/* #include<iostream>
using namespace std;

int sums(int n, int sum=0)
{
    if(n==0)
    {
        return sum;
    }

    return sums(n-1, sum+n);
    
}

int main()
{
    int r,n;
    cout<<"Enter the n";
    cin>>n;
     r=sums(n);
    cout<<"The sum of "<<n<<" number is :"<<r<<endl;
    return 0;
}
 */

