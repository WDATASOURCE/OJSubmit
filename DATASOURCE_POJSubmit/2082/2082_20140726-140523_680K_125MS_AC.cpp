#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stack>
using namespace std;

struct rec{
    __int64 h, w;
}data;

int main(){
    int n, i;
    rec t;
    __int64 ans;
    while(scanf("%d", &n) && n != -1){
        int wight = 0;
        stack<rec> st;
        ans = 0; 
        for(i = 1; i <= n; i++){
            scanf("%I64d%I64d", &data.w, &data.h);
            wight = 0;
            while(!st.empty() && st.top().h > data.h){
                t = st.top();
                wight += st.top().w;
                if(ans < t.h * wight)
                    ans = t.h * wight;
                st.pop();
            }
            wight += data.w;
            data.w = wight;
            st.push(data);
        }
        wight = 0;
        while(!st.empty()){
            t = st.top();
            wight += t.w;
            if(ans < t.h * wight)
                ans = t.h * wight;
            st.pop();
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
