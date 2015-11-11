#include<iostream>
using namespace std;
int main(){
    int t,a,b,i,j,s;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>j;
        for(a=1,s=0;a<=j;a++){
            cin>>b;
            s+=b;
        }
        cout<<s<<endl;
        cout<<endl;
    }
    return 0;
}