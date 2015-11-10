#include<iostream>
#include<cstdio>
#include<stack>
#define M 100010
using namespace std;

struct rec{
    int h, w;
};

rec a[M];

int main(){
    int n, i;
    rec t;
    long long ans;
    while(scanf("%d", &n) && n != 0){
        stack<rec> st;
        ans = 0; 
        for(i = 1; i <= n; i++){
            scanf("%d", &a[i].h); 
            a[i].w = 1;
        }
        for(i = 1; i <= n; i++){
            while(!st.empty() && st.top().h >= a[i].h){
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
        ans = ans > st.top().h * st.top().w ? ans : st.top().h * st.top().w;
        printf("%I64d\n", ans);
    }
    return 0;
}



            


