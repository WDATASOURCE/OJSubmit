#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stack>
#define M 110000
using namespace std;

struct rec{
    __int64 h, w;
};

rec a[M];

int main(){
    int n, i;
    rec t;
    __int64 ans;
    while(scanf("%d", &n) && n != 0){
        stack<rec> st;
        ans = 0; 
        for(i = 1; i <= n; i++){
            scanf("%I64d", &a[i].h); 
            a[i].w = 1;
        }
        for(i = 1; i <= n; i++){
            while(!st.empty() && st.top().h > a[i].h){
                t = st.top();
                if(ans < t.h * t.w)
                    ans = t.h * t.w;
                st.pop();
                if(!st.empty())
                   st.top().w += t.w;
                else
                    a[i].w += t.w;
            }
            st.push(a[i]);
        }
        while(!st.empty()){
            t = st.top();
            ans = ans > t.h * t.w ? ans : t.h * t.w;
            st.pop();
            if(!st.empty())
                st.top().w += t.w;
        }
        for(i = 1; i <= n; i++)
            a[i].w = 1;
        while(!st.empty())
            st.pop();
        for(i = 1; i <= n; i++){
            while(!st.empty() && st.top().h > a[i].h){
                t = st.top();
                if(ans < t.h * t.w)
                    ans = t.h * t.w;
                st.pop();
                a[i].w += t.w;
            }
            st.push(a[i]);
        }
        while(!st.empty()){
            t = st.top();
            ans = ans > t.h * t.w ? ans : t.h * t.w;
            st.pop();
            if(!st.empty())
                st.top().w += t.w;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
