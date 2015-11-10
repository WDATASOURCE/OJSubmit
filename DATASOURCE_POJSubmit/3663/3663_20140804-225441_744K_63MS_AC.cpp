#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
const int maxn = 20002;
 
int main()
{
    //freopen("D:\\t.txt", "r", stdin);
    int n, s;
    int cow[maxn];
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &cow[i]);
    sort(cow, cow + n);
    int l, ans = 0;
    l = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (cow[l] + cow[i] <= s && l < n)
            l++;
        ans += l;
        if (l - 1 >= i)
            ans--;
    }
    printf("%d\n", ans / 2);
    return 0;
}
