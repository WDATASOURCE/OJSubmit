#include<iostream> 
#include <cstdio> 
#define max 105  
#define inf 0xffffff  
using namespace std;  
int tim[max][max];  
int dijkstra(int st,int n)  
{  
    int i,dist[max],vis[max]={0},min,k,j,max1;  
    for(i=1;i<=n;i++)  
    {  
    dist[i]=tim[st][i];  
    vis[i]=0;  
    }  
    vis[st]=1;//源点到源点不用考虑   
    for(i=1;i<n;i++)//n-1次循环查找   
    {  
      min=inf;  
      //k=0;  
      for(j=1;j<=n;j++)  
      {  
         if(!vis[j]&&dist[j]<min)  
         {  
           min=dist[j];  
           k=j;  
         }  
      }  
      //if(k==0) break;  
      vis[k]=1;//从S2集合里找出，源点到这个集合里的点中距离最小的点   
      for(j=1;j<=n;j++)  
      if(!vis[j]&&dist[j]>dist[k]+tim[k][j])   
      dist[j]=dist[k]+tim[k][j];//更新dist[j],每一次找的是S2中，  
      //源点到这个集合里的点中距离最小的点,可能这个距离会经过S1中的点（刚找到的K点）   
    }  
    return min;//每次找出S2集合里最小的，最后一次找出了，这些“最小”时间  
    //中的最长时间   
}  
int main()  
{  
     int j,n,m,i,t,min_num,num,time;  
     while(scanf("%d",&n)!=EOF&&n)  
     {  
       for(i=1;i<=n;i++)  
        for(j=1;j<=n;j++)  
         tim[i][j]=inf;  
       for(i=1;i<=n;i++)  
       {  
        scanf("%d",&m);  
        while(m--)  
        {  
          scanf("%d",&num);  
          scanf("%d",&tim[i][num]);  
        }  
       }  
       t=dijkstra(1,n);  
       min_num=1;  
       for(i=2;i<=n;i++)  
       {  
         time=dijkstra(i,n);  
         if(time<t)  
         {t=time;min_num=i;}  
       }  
       printf("%d %d\n",min_num,t);  
     }  
     return 0;  
}  
