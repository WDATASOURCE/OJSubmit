#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned int L[10000005],R[10000005],a,b,c,d,MIN,MAX,MOD;
int T,N,i;
bool FLAG;
int main()
{
    MOD=(long long)429496729*10+6;
    scanf("%d",&T);
    while (T--)
    {
        cin>>N>>L[1]>>R[1]>>a>>b>>c>>d;
        for (i=2; i<=N; i++) {L[i]=(L[i-1]*a+b); R[i]=(R[i-1]*c+d);}
        for (i=1; i<=N; i++) if (L[i]>R[i]) swap(L[i],R[i]);
        MIN=MOD-1; MAX=0;
        for (i=1; i<=N; i++)
        {
            if (R[i]<MIN) MIN=R[i];
            if (L[i]>MAX) MAX=L[i];
        }
        FLAG=false;
        for (i=1; i<=N; i++) if (L[i]>MIN && R[i]<MAX) FLAG=true;
        if (FLAG && N>=3) puts("YES"); else puts("NO");
    }
    return 0;
}
