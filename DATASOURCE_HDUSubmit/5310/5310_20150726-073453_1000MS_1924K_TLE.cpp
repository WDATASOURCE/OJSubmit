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
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>p>>q;
        //cout<<q/m<<endl;
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
        cout<<res<<endl;
    }
    return 0;
}
