#include<stdio.h>  
#include<string.h>  
int v[20000000],sum,c[100];  
int max(int a,int b){  
    return a>b?a:b;  
}  
int main(){  
    int n,b;  
    while(scanf("%d%d",&n,&b)!=EOF){  
        for(int i=0;i<=n;i++) v[i]=0;  
        sum=0;  
        for(int i=1;i<=n;i++){  
            scanf("%d",&c[i]);  
            sum+=c[i];  
        }  
        int it=sum-b;  
        for(int i=1;i<=n;i++){  
            for(int j=it;j>=c[i];j--){  
                v[j]=max(v[j],v[j-c[i]]+c[i]);  
            }  
        }  
        printf("%d\n",it-v[it]);  
    }  
    return 0;  
}  