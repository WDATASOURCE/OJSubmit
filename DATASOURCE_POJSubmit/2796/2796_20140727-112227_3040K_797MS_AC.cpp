#include<iostream>
#include<cstdio>
#include<fstream>
 
using namespace std;
 
long long a[100011],lef[100011],rig[100011];
long long n;
 
void read(){
//  ifstream cin("in.txt");
    long long i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)
        lef[i]=rig[i]=i;
    a[0]=a[n+1]=-1;
    for(i=1;i<=n;i++)
        while(a[i]<=a[lef[i]-1]) lef[i]=lef[lef[i]-1];
    for(i=n;i>=1;i--)
        while(a[i]<=a[rig[i]+1]) rig[i]=rig[rig[i]+1];
    a[0]=0;
    for(i=2;i<=n;i++)
        a[i]=a[i]+a[i-1];
    long long ans=0;j=0;
    for(i=1;i<=n;i++)
        if(ans<=(a[rig[i]]-a[lef[i]-1])*(a[i]-a[i-1]))
        {
            ans=(a[rig[i]]-a[lef[i]-1])*(a[i]-a[i-1]);
            j=i;
        }
    cout<<ans<<endl;
    cout<<lef[j]<<' '<<rig[j]<<endl;
 
 
}
 
int main(){
    read();
    return 0;
}
