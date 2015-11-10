
#include<iostream>  
#include<string.h>  
#include<stdio.h>  
#include<algorithm>  
#include<math.h>  
#include<queue>  
using namespace std;    
struct node  
{  
      __int64 h,s;       
}mystack[100005];   
__int64 ans,x,k,n,p,a[100005],t;  
int main()  
{     
      while (~scanf("%I64d",&n))  
      {  
            if (!n) break;  
            ans=0;  
            for (p=1;p<=n;p++) scanf("%I64d",&a[p]);  
            a[0]=a[n+1]=0; n++;  
            k=0;  
            for (p=1;p<=n;p++)  
            {   
                  x=a[p];  
                  t=p;   
                  while (k && mystack[k].h>=x)  
                  {  
                        if (mystack[k].h*(p-mystack[k].s)>ans)  
                            ans=mystack[k].h*(p-mystack[k].s);  
                        if (mystack[k].s<t) t=mystack[k].s;  
                        k--;  
                  }  
                  if (!k || mystack[k].h!=x)   
                  {   
                        k++;   
                        mystack[k].h=x;    
                        mystack[k].s=t;   
                  }    
            }    
            k=0;  
            for (p=n-1;p>=0;p--)  
            {  
                  x=a[p];   
                  t=p;  
                  while (k && mystack[k].h>=x)  
                  {  
                        if (mystack[k].h*(mystack[k].s-p)>ans)  
                            ans=mystack[k].h*(n-mystack[k].s-p);  
                        if (mystack[k].s>t) t=mystack[k].s;  
                        k--;  
                  }   
                  if (!k || mystack[k].h!=x)   
                  {   
                        k++;   
                        mystack[k].h=x;    
                        mystack[k].s=t;     
                  }                    
            }    
            printf("%I64d\n",ans);  
      }   
      return 0;  
}  