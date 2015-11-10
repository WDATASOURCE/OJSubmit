/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年08月08日 星期五 22时57分34秒
 ************************************************************************/

 #include <iostream>
 #include <cstdio>

 using namespace std;
 char ch[33];

 void change(int i, int &ans){
     int j, k = 0;
     ans = 0;
     for(j = i; j > i - 8; j--)
     ans += (ch[j] - '0') << k++;
 }

 int main(){
     int i, t, ans;
     scanf("%d", &t);
     while(t--){
         scanf("%s", ch);
         for(i = 7; i < 32; i += 8){
             change(i, ans);
             printf("%d", ans);
             if(i == 31)
             printf("\n");
             else
             printf(".");
         }
     }
     return 0;
 }
