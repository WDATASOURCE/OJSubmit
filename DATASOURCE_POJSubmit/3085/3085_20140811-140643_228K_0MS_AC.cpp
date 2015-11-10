#include<iostream>
#include<fstream>
 
using namespace std;
 
void read(){
//  ifstream cin("in.txt");
    int i,j,k;
    int n1,n2,n3,n4;
    cin>>k;
    for(i=1;i<=k;i++)
    {
        cin>>j;
        n1=j/25;
        j%=25;
        n2=j/10;
        j%=10;
        n3=j/5;
        j%=5;
        n4=j;
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i,n1,n2,n3,n4);
    }
 
}
 
int main(){
    read();
    return 0;
}