#include<stdio.h>  
#include<string.h>  
#define MAXN 100005  
struct node  
{  
    int l,r;  
    __int64 s,c;  
}t[MAXN*4];  
void construct(int l,int r,int p)  
{  
    t[p].l=l,t[p].r=r,t[p].s=t[p].c=0;  
    if(l==r) return ;  
    int m=(l+r)>>1;  
    construct(l,m,p*2);  
    construct(m+1,r,p*2+1);  
}  
void modify(int l,int r,__int64 val,int p)  
{  
    if(t[p].l==l&&t[p].r==r)  
    {  
        t[p].c+=val;  
        t[p].s+=(r-l+1)*val;  
        return ;  
    }  
    if(t[p].c)//向下更新  
    {  
        t[p*2].s+=(t[p*2].r-t[p*2].l+1)*t[p].c;  
        t[p*2].c+=t[p].c;  
        t[p*2+1].s+=(t[p*2+1].r-t[p*2+1].l+1)*t[p].c;  
        t[p*2+1].c+=t[p].c;  
        t[p].c=0;  
    }  
    int m=(t[p].l+t[p].r)>>1;  
    if(r<=m) modify(l,r,val,p*2);  
    else if(l>m) modify(l,r,val,p*2+1);  
    else { modify(l,m,val,p*2); modify(m+1,r,val,p*2+1);}  
    t[p].s=t[p*2].s+t[p*2+1].s;//向上更新  
}  
__int64 query(int l,int r,int p)  
{  
    if(t[p].l==l&&t[p].r==r)  
        return t[p].s;  
    if(t[p].c)  
    {  
        t[p*2].s+=(t[p*2].r-t[p*2].l+1)*t[p].c;  
        t[p*2].c+=t[p].c;  
        t[p*2+1].s+=(t[p*2+1].r-t[p*2+1].l+1)*t[p].c;  
        t[p*2+1].c+=t[p].c;  
        t[p].c=0;  
    }  
    int m=(t[p].l+t[p].r)>>1;  
    if(r<=m) return query(l,r,p*2);  
    else if(l>m) return query(l,r,p*2+1);  
    else return query(l,m,p*2)+query(m+1,r,p*2+1);  
}  
int main()  
{  
    int i,a,b,n,m;  
    char op[3];  
    __int64 x,c;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        construct(1,n,1);  
        for(i=1;i<=n;i++)  
        {  
            scanf("%I64d",&x);  
            modify(i,i,x,1);  
        }  
        while(m--)  
        {  
            scanf("%s%d%d",op,&a,&b);  
            if(op[0]=='C')  
            {  
                scanf("%I64d",&c);  
                modify(a,b,c,1);  
            }  
            else  
                printf("%I64d\n",query(a,b,1));  
        }  
    }  
    return 0;  
}  
