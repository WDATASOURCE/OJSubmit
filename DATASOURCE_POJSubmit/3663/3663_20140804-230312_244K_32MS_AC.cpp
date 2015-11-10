#include <iostream>

#include <algorithm>
using namespace std;
int a[20001];

int bin_search(int i, int j, const int &key)
{
 int point = (i + j + 1) >> 1;
 while(i < j)
 {
  if (a[point] <= key)
  {
   i = point;
   point = (i + j + 1) >> 1;
  }
  else 
  {
   j = point - 1;
   point = (i + j + 1) >> 1;
  }
 }
 return point;
}

int main()
{
  int n, s, k, p, ans;
  while(scanf("%d%d", &n, &s) != EOF)
  {
     for (int i = 0; i < n; i++)
  {
   scanf("%d", &a[i]);
  }
  sort(a, a + n);
  ans = 0;
  k = bin_search(0, n - 1, s);
  for (int i = 1; i <= k; i++)
  {
   p = bin_search(0, i - 1, s - a[i]);
   if (p != -1)
   {
    ans += p + 1;
   }
   }
   printf("%d\n", ans);
 }
  return 0;
}
