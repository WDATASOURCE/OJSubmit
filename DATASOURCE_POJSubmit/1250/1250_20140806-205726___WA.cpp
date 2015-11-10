#include<iostream>  
#include<string>  
#include<algorithm>  
#include<cstdio>
using namespace std;  
int n;  
bool vis[30];  
string s;  
int main(){  
    while(scanf("%d",&n),n){  
        memset(vis,0,sizeof(vis));  
        cin>>s;  
        int ans=0;  
        for(int i=0;i<s.length();i++){  
            int t=s[i]-'A';  
            if(!vis[t]){  
                if(n<=0){  
                    ans++;  
                }  
                else  
                    n--;  
            }  
            else  
                n++;  
            vis[t]=!vis[t];  
        }  
        if(!ans)  
            printf("All customers tanned successfully.\n");  
        else  
            printf("%d customer(s) walked away.\n",ans);  
    }  
    return 0;  
}  
