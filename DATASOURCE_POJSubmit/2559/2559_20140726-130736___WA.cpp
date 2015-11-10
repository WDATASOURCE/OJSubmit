#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stack>
#define M 110000
using namespace std;

struct rec{
    __int64 h, w;
}data;

int main(){
    int n, i;
    rec t;
    __int64 ans;
    while(scanf("%d", &n) && n != 0){
        //int wight = 0;
        stack<rec> st;
        ans = 0; 
        for(i = 1; i <= n; i++){
            scanf("%I64d", &data.h);
            data.w = 1;
            while(!st.empty() && st.top().h > data.h){
                t = st.top();
                if(ans < t.h * t.w)
                    ans = t.h * t.w;
                st.pop();
                if(!st.empty())
                    st.top().w += t.w;
                else
                    data.w += t.w;
            }
            st.push(data);
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
