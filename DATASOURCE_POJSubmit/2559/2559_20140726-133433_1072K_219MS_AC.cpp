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
        int wight = 0;
        int lasth = 0; 
        stack<rec> st;
        ans = 0; 
        for(i = 1; i <= n; i++){
            scanf("%I64d", &data.h);
            data.w = 1;
            wight = 0;
            if(data.h >= lasth)
                st.push(data);
            else{
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
            lasth = data.h;
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
