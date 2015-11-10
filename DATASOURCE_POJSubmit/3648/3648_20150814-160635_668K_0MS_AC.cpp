#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 200
#define MAXM 1000
struct Edge
{
 int from;
 int to;
 int next;
};
Edge e[MAXM], e2[MAXM];
int cnt, cnt2, pn[MAXN], pn2[MAXN];
int n, m;
//-------------------原图增加一条边
void addedge(int from, int to)
{
 e[cnt].from = from;
 e[cnt].to = to;
 e[cnt].next = pn[from];
 pn[from] = cnt++;
}
//-------------------缩点图增加一条边
void addedge2(int from, int to)
{
 e2[cnt2].from = from;
 e2[cnt2].to = to;
 e2[cnt2].next = pn2[from];
 pn2[from] = cnt2++;
}
//-------------------Tarjan算法求强连通分量
int index, tuan, top;
int dfn[MAXN], low[MAXN], instack[MAXN], sta[MAXN], belong[MAXN];
void tarjan(int u)
{
 int v, j;
 dfn[u] = low[u] = ++index;
 instack[u] = 1;
 sta[++top] = u;
 for (int i = pn[u]; i != -1; i = e[i].next)
 {
  v = e[i].to;
  if (!dfn[v])
  {
   tarjan(v);
   if (low[v] < low[u])
    low[u] = low[v];
  }
  else if (instack[v] && dfn[v] < low[u])
  {
   low[u] = dfn[v];
  }
 }
 if (dfn[u] == low[u])
 {
  tuan++;
  do
  {
   j = sta[top--];
   instack[j] = 0;
   belong[j] = tuan;
  } while(j != u);
 }
}
//---------------------拓扑排序求解
int cf[MAXN], indeg[MAXN], que[MAXN], col[MAXN];   //indeg[]为入度 ,que[]为队列,col[]为是否选择标志
bool ans[MAXN];    //1表示选择，0表示不选择
bool sovle(int n)
{
 int i;
 index = tuan = top = 0;
 memset(dfn,0,sizeof(dfn));
 for (i = 0; i < 2*n; i++)
 {
  if (!dfn[i])
   tarjan(i);
 }
 for (i = 0; i < n; i++)
 {
  if (belong[i] == belong[i+n]) //若有同一组的分量在同一个强连通分量中，则直接返回false
   return false;
  cf[belong[i]] = belong[i+n];  //存储同一组的分量所在哪个强连通分量，这样访问过其中一个后，另一个就不用再去访问了
  cf[belong[i+n]] = belong[i];  //在缩点的图中标记互斥的缩点。（原来互斥，现在也互斥）
 }
 memset(indeg,0,sizeof(indeg));
 memset(col,0,sizeof(col));
 memset(pn2,0xff,sizeof(pn2));
 cnt2 = 1;
 for (i = 1; i < cnt; i++)   //cnt条边,建立缩点图
 {
  if (belong[e[i].from] != belong[e[i].to])
  {
   addedge2(belong[e[i].to],belong[e[i].from]);  //反向,是因为u--->v，如果选择了u，必须选择v，则应该反向，求入度为0的缩点
   indeg[belong[e[i].from]]++;     //统计入度
  }
 }
 //-----------------开始拓扑排序
 int head = 1 ,tail = 1;
 for (i = 1; i <= tuan; i++)
 {
  if (indeg[i] == 0)  //入度为0入队列
  {
   que[tail++] = i;
  }
 }
 int v;
 while (head < tail)
 {
  int u = que[head];
  head++;
  if (col[u] == 0)    //对于未着色的点x，将x染成红色1，同时将与x矛盾的点cf[x]染成蓝色-1。
  {
   col[u] = 1;
   col[cf[u]] = -1;
  }
  for (i = pn2[u]; i != -1; i = e2[i].next)
  {
   v = e2[i].to;
   if (--indeg[v] == 0)    //入度为0
   {
    que[tail++] = v;         //入队列
   }
  }
 }
 memset(ans,0,sizeof(ans));
 for (i = 0; i < n; i++)
 {
  if (col[belong[i]] == 1)
  {
   ans[i] = 1;
  }
 }
 return true;
}
int main()
{
    int i, r, l;
 char str1, str2;
//  freopen("in.txt","r",stdin);
    while(scanf("%d%d\n",&n,&m) && ( n || m ))
    {
  memset(pn,0xff,sizeof(pn));
  cnt = 1;
  while (m--)
  {
   scanf("%d%c %d%c",&l,&str1,&r,&str2);
   //开始构图
   if (str1 == 'h' && str2 == 'h')
   {
    addedge(r+n,l);
    addedge(l+n,r);
   }
   else if (str1 == 'h' && str2 == 'w')
   {
    addedge(l+n,r+n);
    addedge(r,l);
   }
   else if (str1 == 'w' && str2 == 'h')
   {
    addedge(l,r);
    addedge(r+n,l+n);
   }
   else if (str1 == 'w' && str2 == 'w')
   {
    addedge(l,r+n);
    addedge(r,l+n);
   }
  }
  addedge(0,0+n);  //增加新娘到新郎的边
  if (sovle(n))
  {
   for (i = 1; i < n; i++)
   {
    if (ans[i])
     printf("%dh ",i);
    else
     printf("%dw ",i);
   }
   printf("\n");
  }
  else
   printf("bad luck\n");
    }
    return 0;
}