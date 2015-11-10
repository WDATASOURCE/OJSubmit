#include<iostream>
using namespace std;

int main()
{
char a[10];
int n;
while(cin.getline(a,10))
{
cout<<a<<endl;
for(n=0;n<10;n++)
a[n]=0;
}
return 0;
}