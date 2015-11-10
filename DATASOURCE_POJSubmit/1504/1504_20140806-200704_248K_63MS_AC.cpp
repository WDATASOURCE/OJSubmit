#include<iostream>  
using namespace std;  
int fan(int n)  
{  
    long int sum=0;  
    while(n!=0)  
    {  
        sum=sum*10+n%10;  
        n/=10;  
    }  
    return sum;  
}  
int main()  
{  
    int t,a,b;  
    cin>>t;  
    while(t--)  
    {  
        cin>>a>>b;  
        cout<<fan(fan(a)+fan(b))<<endl;  
    }  
    return 0;  
}  