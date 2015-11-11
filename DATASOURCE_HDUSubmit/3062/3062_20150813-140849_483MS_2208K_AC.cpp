#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define SIZE 2010

using namespace std;

struct node
{
    int to,next;
}edge[SIZE*SIZE];
int head[SIZE],idx;
int n,m;
int dfsn[SIZE],low[SIZE],tim;
int be[SIZE],num;
stack <int> sta;
bool instack[SIZE];

void addnode(int from,int to)
{
    edge[idx].to = to;
    edge[idx].next = head[from];
    head[from] = idx++;
}

void tarjan(int cur)
{
    dfsn[cur] = low[cur] = ++tim;
    sta.push(cur);
    instack[cur] = true;
    for(int i=head[cur]; i!=-1; i=edge[i].next)
    {
        int to = edge[i].to;
        if(!dfsn[to])
        {
            tarjan(to);
            low[cur] = min(low[cur],low[to]);
        }
        else if(instack[to])
            low[cur] = min(low[cur],dfsn[to]);
    }
    if(dfsn[cur] == low[cur])
    {
        int tem = -1;
        ++num;
        while(tem != cur)
        {
            tem = sta.top();
            sta.pop();
            instack[tem] = false;
            be[tem] = num;
        }
    }
}

void solve()
{
    memset(dfsn,0,sizeof(dfsn));
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    memset(be,0,sizeof(be));
    while(!sta.empty()) sta.pop();
    tim = num = 0;
    for(int i=0; i<2*n; i++)
        if(!dfsn[i])
            tarjan(i);
    bool ans = true;
    for(int i=0; i<2*n; i+=2)
        if(be[i] == be[i+n]){
            ans = false;
            break;
        }
    if(ans) puts("YES");
    else puts("NO");
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        idx = 0;
        memset(head,-1,sizeof(head));
        int x,y,sex1,sex2;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d%d",&x,&y,&sex1,&sex2);
            if(sex1 && sex2)
            {
                addnode(x+n,y);
                addnode(y+n,x);
            }
            if(!sex1 && sex2)
            {
                addnode(x,y);
                addnode(y+n,x+n);
            }
            if(sex1 && !sex2)
            {
                addnode(x+n,y+n);
                addnode(y,x);
            }
            if(!sex1 && !sex2)
            {
                addnode(x,y+n);
                addnode(y,x+n);
            }
        }
        solve();
    }
    return 0;
}