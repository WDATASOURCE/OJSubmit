#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int p[1000006], n, c;

bool iscan(int a)
{
    int i,j,be,ba;			//a 为可能的答案
    be=p[0];
    ba=be+a;
    c--;
    for(i=1;i<n;i++)
        if(p[i]>=ba){
            be=p[i];
            ba=be+a;
            c--;
        }
    if(c<=0)
        return true;
    return false;
}

int  find(){		//两分查找，始终认为 l 处为闭区间，h 处为开区间   h-l 为区间中的数字个数
    int l=0,h=p[n-1]+1;
    int min;
    while(h-l!=1){
        min=(l+h)/2;
        if(iscan(min))
            l=min;
        else
            h=min;
    }
    return l;
}

int main(){
    int i,n,c,key;
    scanf("%d%d", &n, &c);
    for(i=0;i<n;i++)
    scanf("%d", &p[i]);
    sort(p,p+n);
    key=find();
    printf("%d\n", key);
    return 0;
}
