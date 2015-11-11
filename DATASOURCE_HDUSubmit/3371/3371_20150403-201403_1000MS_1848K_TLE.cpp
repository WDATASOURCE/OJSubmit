#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,k,p[505],ans;
struct node{
    int u,v,w;
}pt[250000];
int cmp(node a,node b)
{
    return a.w<b.w;
}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,num,a,b,root,x,y;
        for(i=0;i<=500;i++) p[i]=i;
        bool flag=false;
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=m;i++)scanf("%d%d%d",&pt[i].u,&pt[i].v,&pt[i].w);
        sort(pt+1,pt+m+1,cmp);
        for(i=1;i<=k;i++)
        {
            scanf("%d%d",&num,&root);
            for(j=1;j<num;j++)
            {
                scanf("%d",&a);
                 x=find(a),y=find(root);
                if(x!=y)  p[x]=y;
            }
        }
        for(num=0,i=1;i<=n;i++) if(p[i]==i) num++;
        for(ans=0,i=1;i<=m;i++)
        {
            x=find(pt[i].u);y=find(pt[i].v);
            if(x!=y) 
            {
                p[x]=y;
                ans+=pt[i].w;num--;
            }
            if(num==1)
            {
                flag=true;
                break;
            }
        }
        if(flag) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}