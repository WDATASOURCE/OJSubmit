#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[20];
bool ok(){
    int n = strlen(s);
    if(n%3) return 0;
    int k = n/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<k; j++){
            if(s[i*k+j] != s[i*k])  return 0;
        }
    }
    if(s[0]==s[k] || s[k]==s[k+k] || s[0]==s[k+k])  return 0;
    return 1;
}
int main(){
    while(~scanf("%s", s)){
        puts(ok()?"YES":"NO");
    }
    return 0;
}