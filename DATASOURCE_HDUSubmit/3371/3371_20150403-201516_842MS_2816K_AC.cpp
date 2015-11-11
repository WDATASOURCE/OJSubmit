#include<stdio.h>
#include<stdlib.h>
#define MAX 10000000
int Num;
int set[501],rank[501],map[501][501];
struct node
{
 int p,q,c;
}a[25001];
int Find(int x)
{
 if(x!=set[x])
  set[x]=Find(set[x]);
 return set[x];
}
bool Union(int x,int y)
{
 x=Find(x);
 y=Find(y);
 if(x==y)
  return 0;
 Num--;
 if(rank[x]>rank[y])
 {
  set[y]=x;
  rank[x]+=rank[y];
 }
 else
 {
  set[x]=y;
  rank[y]+=rank[x];
 }
 return 1;
}
int cmp(void const *a,void const *b)
{
 return (*(node *)a).c-(*(node *)b).c;
}
int main()
{
 int i,j,T,n,m,k,t,B0,Bx,sum;
 scanf("%d",&T);
 while(T--)
 {
  scanf("%d%d%d",&n,&m,&k);
  Num=n-1;
  for(i=0;i<=n;i++)
  {
   set[i]=i;
   rank[i]=1;
  }
  for(i=0;i<m;i++)
  {
   scanf("%d%d%d",&a[i].p,&a[i].q,&a[i].c);
   map[a[i].p][a[i].q]=map[a[i].q][a[i].p]=a[i].c;
  }
  for(i=0;i<k;i++)
  {
   scanf("%d",&t);
   scanf("%d",&B0);
   for(j=1;j<t;j++)
   {
    scanf("%d",&Bx);
    map[B0][Bx]=map[Bx][B0]=0;
    Union(B0,Bx);
   }
  }
  qsort(a,m,sizeof(a[0]),cmp);
  sum=0;
  for(i=0;i<m;i++)
  {
   if(Num==0)
    break;
   if(Union(a[i].p,a[i].q))
    sum+=a[i].c;
  }
  if(Num==0)
   printf("%d\n",sum);
  else printf("-1\n");
 }
 return 0;
}