/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年08月08日 星期五 22时57分34秒
 ************************************************************************/

 #include <iostream>
 #include <cmath>
 #include <cstdio>

 using namespace std;
 int main(){
     int i, t, ans;
     scanf("%d", &t);
     while(t--){
         int n;
         double sum = 0;
         scanf("%d", &n);
         for(i = 1; i <= n; i++)
         sum += log10(i * 1.0);
         ans = sum + 1;
         printf("%d\n", ans);
         }
     return 0;
 }
