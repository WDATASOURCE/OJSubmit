#include <cstdio>

int main(){
int n, ans;
while(scanf("%d", &n) != EOF){
int a = 1; 
ans = 1;
do{
a = a * 10 + 1;
ans++;
a %= n;
}while(a);
printf("%d\n", ans);
}
return 0;
}