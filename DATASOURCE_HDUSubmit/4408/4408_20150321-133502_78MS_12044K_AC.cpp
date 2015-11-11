#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<cstdlib>  
#include<queue>  
#include<algorithm>  
#include<vector>  
using namespace std;  
  
const int N=1111;  
const int M=1111;  
  
typedef long long LL;  

  
struct Edges  {  
    int a,b,c;  
    bool operator<(const Edges & x)const  {  
        return c<x.c;  
    }  
} edge[M];  
  
int n,m;  
int mod;  
LL f[N],U[N],vist[N];//f,U¶¼ÊÇ²¢²é¼¯£¬UÊÇÃ¿×é±ßÁÙÊ±Ê¹ÓÃ  
LL G[N][N],C[N][N];//G¶¥µãÖ®¼äµÄ¹ØÏµ£¬CÎªÉú³ÉÊ÷¼ÆÊýÓÃµÄKirchhoff¾ØÕó  
  
vector<int>V[N];//¼ÇÂ¼Ã¿¸öÁ¬Í¨·ÖÁ¿  
  
int Find(int x,LL f[])  {  
    if(x==f[x])  return x;  
    else  return Find(f[x],f);  
}  
  
LL det(LL a[][N],int n)//Éú³ÉÊ÷¼ÆÊý:Matrix-Tree¶¨Àí  
{  
    for(int i=0; i<n; i++)  
        for(int j=0; j<n; j++)  
            a[i][j]%=mod;  
    int ret=1;  
    for(int i=1; i<n; i++)  {  
        for(int j=i+1; j<n; j++)  
            while(a[j][i])  {  
                int t=a[i][i]/a[j][i];  
                for(int k=i; k<n; k++)  
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;  
                for(int k=i; k<n; k++)  
                    swap(a[i][k],a[j][k]);  
                ret=-ret;  
            }  
        if(a[i][i]==0)  return 0;  
        ret=ret*a[i][i]%mod;  
    }  
    return (ret+mod)%mod;  
}  
  
void Solve()  {  
    sort(edge,edge+m);//°´È¨ÖµÅÅÐò  
    for(int i=1; i<=n; i++){//³õÊ¼»¯²¢²é¼¯  
        f[i]=i;  
        vist[i]=0;  
    }  
  
    LL Edge=-1;//¼ÇÂ¼ÏàÍ¬µÄÈ¨ÖµµÄ±ß  
    LL ans=1;  
    for(int k=0; k<=m; k++)  {  
        if(edge[k].c!=Edge||k==m)//Ò»×éÏàµÈµÄ±ß,¼´È¨Öµ¶¼ÎªEdgeµÄ±ß¼ÓÍê  
        {  
            for(int i=1; i<=n; i++)  {  
                if(vist[i])  {  
                    LL u=Find(i,U);  
                    V[u].push_back(i);  
                    vist[i]=0;  
                }  
            }  
            for(int i=1; i<=n; i++) //Ã¶¾ÙÃ¿¸öÁ¬Í¨·ÖÁ¿  
            {  
                if(V[i].size()>1)  {  
                    for(int a=1; a<=n; a++)  
                        for(int b=1; b<=n; b++)  
                            C[a][b]=0;  
                    int len=V[i].size();  
                    for(int a=0; a<len; a++) //¹¹½¨Kirchhoff¾ØÕóC  
                        for(int b=a+1; b<len; b++)  {  
                            int a1=V[i][a];  
                            int b1=V[i][b];  
                            C[a][b]=(C[b][a]-=G[a1][b1]);  
                            C[a][a]+=G[a1][b1];//Á¬Í¨·ÖÁ¿µÄ¶È  
                            C[b][b]+=G[a1][b1];  
                        }  
                    LL ret=(LL)det(C,len);  
                    ans=(ans*ret)%mod;//¶ÔVÖÐµÄÃ¿Ò»¸öÁ¬Í¨¿éÇóÉú³ÉÊ÷¸öÊýÔÙÏà³Ë  
                    for(int a=0; a<len; a++)  
                        f[V[i][a]]=i;  
                }  
            }  
            for(int i=1; i<=n; i++)  {  
                U[i]=f[i]=Find(i,f);  
                V[i].clear();  
            }  
            if(k==m)  break;  
            Edge=edge[k].c;  
        }  
  
        int a=edge[k].a;  
        int b=edge[k].b;  
        int a1=Find(a,f);  
        int b1=Find(b,f);  
        if(a1==b1)  continue;  
        vist[a1]=vist[b1]=1;  
        U[Find(a1,U)]=Find(b1,U);//²¢²é¼¯²Ù×÷  
        G[a1][b1]++;  
        G[b1][a1]++;  
    }  
  
    int flag=0;  
    for(int i=2; i<=n&&!flag; i++)  
        if(U[i]!=U[i-1])  
            flag=1;  
    if(m==0)  flag=1;  
    printf("%lld\n",flag?0:ans%mod);  
  
}  
  
int main()  {  
    int t;
    while(scanf("%d%d%d", &n, &m, &mod) != EOF && m + n + mod){
        memset(G,0,sizeof(G));  
        for(int i=1; i<=n; i++)  
            V[i].clear();  
        for(int i=0; i<m; i++) { 
            scanf("%d%d%d",&edge[i].a,&edge[i].b, &edge[i].c);  
        }
        Solve();  
    }  
    return 0;  
}  
