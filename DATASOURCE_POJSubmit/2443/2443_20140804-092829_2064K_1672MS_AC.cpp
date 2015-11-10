#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
   
#define Maxn 11000  
int sa[Maxn][35];//sa[i][j]表示i这个数在[32*j,32*j+31]集合区间的出现情况  
//一个int可以保存32个集合的信息，一共只有1000个集合所有只用32个整型即可  
   
int main(){  
   int n;  
   while(scanf("%d",&n) != EOF){  
       for(int i=0;i<n;i++){  
           int num;  
           scanf("%d",&num);  
           for(int j=1;j<=num;j++){  
               int a;  
               scanf("%d",&a);    //i/32代表该集合在那个整数里面  
               int bit=1<<(i%32); //i%32代表该集合在该整数中的第几位 位置  
                                  //if((sa[a][i/32]&bit)==0) //之前没有出现，因为一个集合可能有多个相同的数  
                sa[a][i/32]|=bit;  
           }  
       }  
       int q;  
       scanf("%d",&q);  
       for(int i=1;i<=q;i++){  
           int a,b;  
           scanf("%d%d",&a,&b);  
           bool flag=false;  
           for(int i=0;i<32;i++)  
                if(sa[a][i]&sa[b][i]){  
                    flag=true;  
                    break;  
                }  
            if(flag)  
                printf("Yes\n");  
            else 
                printf("No\n");  
       }  
   }  
   return 0;  
}
