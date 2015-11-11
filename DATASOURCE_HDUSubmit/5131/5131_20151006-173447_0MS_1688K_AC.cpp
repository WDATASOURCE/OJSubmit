#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
struct outlaw{
    string name;
    int nu;
};
bool cmp(outlaw a, outlaw b)
{
    if(a.nu == b.nu)
        return a.name < b.name;
    return a.nu > b.nu;
}
const int maxsize = 500;
outlaw ols[maxsize];
int main()
{
    int n, m;
    while(scanf("%d", &n), n!=0)
    {
        for(int i=0; i<n; i++)
        {
            cin>>ols[i].name;
            cin>>ols[i].nu;
        }
        sort(ols, ols+n, cmp);
        for(int i=0; i<n; i++)
        {
            cout<<ols[i].name<<" "<<ols[i].nu<<endl;
        }
        cin>>m;
        string tmp;
        while(m--)
        {
            cin>>tmp;
            int pos = -1;
            for(int i=0; i<n; i++)
            {
                if(ols[i].name == tmp)
                {
                    pos = i;
                    break;
                }
            }
            int major = 1;
            int minor = 1;
            int i;
            for(i=0; i<n; i++)
            {
                if(ols[i].nu > ols[pos].nu)
                {
                    major++;
                }
            }
            for(i=0; i<pos; i++)
            {
                if(ols[i].nu == ols[pos].nu && ols[i].name<ols[pos].name)
                    minor++;
            }
            if(minor != 1)
            {
                printf ( "%d %d\n", major, minor );
            }
            else
            {
                printf ( "%d\n", major );
            }
        }
    }
    return 0;
}