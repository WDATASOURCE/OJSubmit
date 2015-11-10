#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stack>
using namespace std;

struct rec{
    __int64 h, w;
    int i;
}data;

int main(){
    int n, i;
    rec t;
    __int64 ans;
    while(scanf("%d", &n) != EOF){
        int wight = 0;
        stack<rec> st;
        ans = 0; 
        int a, b;
        for(i = 0; i < n; i++){
            scanf("%I64d", &data.h);
            data.w = data.h;
            data.i = i;
            wight = 0;
            while(!st.empty() && st.top().h > data.h){
                t = st.top();
                wight += st.top().w;
                if(ans < t.h * wight){
                    ans = t.h * wight;
                    a = t.i;
                    b = data.i;
                }
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
        printf("%d %d\n", a, b);
    }
    return 0;
}
