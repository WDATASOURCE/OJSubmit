#include <cstdio>
using namespace std;

int main(){
long long a,m;
scanf("%I64d",&a);
for(m=a;;m++){
if((a*a+1)%m==0)
break;
}
long long ans=2*a+m+(a*a+1)/m;
printf("%I64d\n",ans);
}
