#include<stdio.h>
#include<string.h>
const int maxn = 3000;
 
struct node
{
    int v,next;
}eg[maxn*maxn];
int head[maxn];
int dfn[maxn],low[maxn],sta[maxn],insta[maxn],belong[maxn];
int tot,color,top,Index,n;
void add(int a,int b)
{
    eg[tot].v= b;
    eg[tot].next = head[a];
    head[a] = tot++;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++Index;
    sta[top++] = u;
    insta[u] = 1;
    for(int i=head[u];i+1;i= eg[i].next)
    {
        int v= eg[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = low[u] < low[v] ? low[u] : low[v];
        }else if(insta[v])
            low[u] = low[u] < dfn[v] ? low[u] : dfn[v];
    }
    if(low[u] == dfn[u])
    {
        int v;
        color++;
        do
        {
            v= sta[--top];
            insta[v] = 0;
            belong[v] =color;
        }while(v != u);
    }
}
void init()
{
    tot = color = top = Index =0;
    memset(dfn,0,sizeof(dfn));
    memset(insta,0,sizeof(insta));
    memset(belong,0,sizeof(belong));
    memset(head,-1,sizeof(head));
}
void work()
{
    int i;
    for(i=0;i<2*n;i++)
    {
        if(!dfn[i])tarjan(i);
    }
    int flag = 0;
    for(i=0;i<n;i++)
    {
        if(belong[i*2] == belong[i*2+1])
        {
            break;
        }
    }
    if(i == n) printf("YES\n");
    else printf("NO\n");
 
}
int main()
{
    int m,a1,a2,b1,b2;
    while(~scanf("%d",&n))
    {
        init();
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
        //  printf("%d %d\n",a1*2+a2,b1*2 + !b2);
        //  printf("%d %d\n",b1*2 + b2,a1*2+!a2);
            add(a1*2 + b1,a2*2 + 1 -b2);
            add(a2*2 + b2,a1*2 + 1 -b1);
        }
        work();
    }
 
    return 0;
}
