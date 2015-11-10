#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int x,y,k;
    while(cin>>x>>y)
    {
        if(x > y)
        {
            k = x;
            x = y;
            y = k;
        }
        k = y - x;
        if(x == (int)(k*(1 + sqrt(5.0))/2))
        {
            cout<<0<<endl;
        }
        else
            cout<<1<<endl;
    }
    return 0;
}
