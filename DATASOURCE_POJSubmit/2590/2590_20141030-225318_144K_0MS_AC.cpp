#include <cstdio>
#include <cmath>  
  
int main()  {  
    int x,y,n;  
    scanf("%d", &n);
    while(n--)  {  
        scanf("%d%d", &x, &y);
        printf("%d\n", (int)(sqrt((double)(y - x)) * 2 - 1e-9));
    }  
    return 0;  
}  
