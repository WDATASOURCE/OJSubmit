#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <utility>
#define ll long long 
#define INF 0x3f3f3f3f

using namespace std;

double p,q,res;
int n,m,temp;

int main()
{
    int t;
    //cin>>t;
    scanf("%d", &t);
    while(t--)
    {
        //cin>>n>>m>>p>>q;
        scanf("%d%d%lf%lf", &n, &m, &p, &q);
        if(p<=q/m)
        {
            res=n*p;
        }
        else
        {
            temp=n/m;//Ì××°¸öÊý
            if(n%m>0)
            {
                if((n%m)*p>=q) res=(temp+1)*q;
                else res=(n%m)*p+temp*q;
            }
            else res=temp*q;
        }
        //cout<<res<<endl;
        printf("%.0lf\n", res);
    }
    return 0;
}
