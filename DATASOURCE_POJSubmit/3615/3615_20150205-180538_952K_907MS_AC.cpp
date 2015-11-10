#include<cstdio>  
#include<cmath>  
#include<string>  
#include<cstring>  
#include<queue>  
#include<algorithm>  
#include<iostream>  
#include<cstring>  
using namespace std;  
#define INF 1000000001  
int map[301][301];  
int n,m,t;  
int a,b,c;  
void flody(){  
    for(int k=1;k<=n;k++)  
        for(int i=1;i<=n;i++)  
            for(int j=1;j<=n;j++)  
                map[i][j]=min(map[i][j],max(map[i][k],map[k][j]));  
}  
void init(){  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)  
            map[i][j]=INF;  
}  
int main(){;  
while(scanf("%d%d%d",&n,&m,&t)!=EOF){  
    init();  
    for(int i=1;i<=m;i++){  
        scanf("%d%d%d",&a,&b,&c);  
        map[a][b]=c;  
    }  
    flody();  
    for(int i=1;i<=t;i++){  
        scanf("%d%d",&a,&b);  
        if(map[a][b]<INF)  
            printf("%d\n",map[a][b]);  
        else  
            printf("-1\n");  
    }  
}  
return 0;  
}  
