#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int nxt[1000010],len,t;
char ch[1000010];

void get_next()
{
    int i=0,j=-1;
    nxt[0]=-1;
    while (i<len)
    {
        if (j==-1||ch[i]==ch[j])
        {
            i++;
            j++;
            nxt[i]=j;
        }
        else
            j=nxt[j];
    }
}

int Min_(char s[],int len)
{
    int p1=0,p2=1,k=0;
    while (p1<len&&p2<len&&k<len)
    {
        t=s[(p1+k)%len]-s[(p2+k)%len];
        if (t==0)
            k++;
        else
        {
            if (t>0)
                p1=p1+k+1;
            else
                p2=p2+k+1;
            if (p1==p2)
                p2++;
            k=0;
        }
    }
    return min(p1,p2);
}

int Max_(char s[],int len)
{
    int p1=0,p2=1,k=0;
    while (p1<len&&p2<len&&k<len)
    {
        t=s[(p1+k)%len]-s[(p2+k)%len];
        if (t==0)
            k++;
        else
        {
            if (t>0)
                p2=p2+k+1;
            else
                p1=p1+k+1;
            if (p1==p2)
                p2++;
            k=0;

        }
    }
    return p1<p2?p1:p2;
}

int main()
{
    while(~scanf("%s",ch))
    {
        len=strlen(ch);
        get_next();
        int Max=Max_(ch,len);
        int Min=Min_(ch,len);
        //cout<<Max<<Min<<endl;
        int sum=0;
        if(len%(len-nxt[len])==0)
            sum=len/(len-nxt[len]);
        else
            sum=1;
        printf ("%d %d %d %d\n",Min+1,sum,Max+1,sum);
    }
    return 0;
}
