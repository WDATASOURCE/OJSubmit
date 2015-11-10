#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std ;
const int maxn=200000+20;
int n, s;
int a[maxn];
int main()
{
 while(scanf("%d%d",&n,&s)!=EOF)
 {
  for(int i=1; i<=n; i++)
  scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  int left=1;
  int right=n;
  long long  ans=0;
  while(left<=right)
  {
   if(a[left]+a[right]<=s)
   {
    ans+=right-left;
  //  cout<<a[left]<<" "<<a[right]<<" "<<ans<<endl;
    left=left+1;
   }
   else
   {
    right=right-1;
   }
  }
  printf("%lld\n",ans); 
 }
 return 0;
}