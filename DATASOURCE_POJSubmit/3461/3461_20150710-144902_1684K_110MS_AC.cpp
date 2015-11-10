#include <iostream>
#include <cstdio>  
#include <cstring>  
using namespace std;

const int MAXN_T=1000005;
const int MAXN_P=10005;
char t[MAXN_T],p[MAXN_P];
int next[MAXN_P];
  
void getNext(int l) {  
    int i=0;
    int j=-1;  
    next[0]=-1;  
    while(i<l){  
        if(j==-1||p[i]==p[j]){  
            i++;  
            j++;  
            next[i]=j; 
        }  
        else  
            j=next[j];  
    }  
}  
int KMP() {  
    int lenT=strlen(t),lenP=strlen(p);  
    getNext(lenP);
    int i=0,j=0,ans=0;  
    while(i<lenT){  
        if(j==-1||t[i]==p[j]){  
            i++;
            j++;
        }else
            j=next[j];
        if(j==lenP){
            ans++;
            j=next[j];
        }  
    }  
    return ans;  
}
  
int main() {  
    int cases;  
    scanf("%d",&cases);  
    while(cases--){  
        scanf("%s%s",p,t);  
        printf("%d\n",KMP());  
    }  
    return 0;  
}  