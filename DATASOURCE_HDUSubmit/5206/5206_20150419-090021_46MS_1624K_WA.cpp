#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 4
using namespace std;

struct point {
    int x, y, z;

    long long juli(const point &a){
        return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) + (z - a.z);
    }
}p[N];

long long dis[6];

int main(){
    int t, di = 1;
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i < N; i++)
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        int e = 0;
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++){
                if(i == j) continue;
                dis[e++] = p[i].juli(p[j]);
            }
        //cerr <<"e = "<< e << endl;
        long long mi = (1000000000000000000L), ma = 0;
        for(int i = 0; i < e; i++){
            if(dis[i] < mi) mi = dis[i];
            if(dis[i] > ma) ma = dis[i];
            //cerr <<"i = "<< i <<", dis[i] = "<< dis[i] << endl;
        }
        //cerr <<"mi = "<< mi <<", ma = "<< ma << endl;
        bool f = 1;
        for(int i = 0; i < e; i++)
            if(dis[i] != ma && dis[i] != mi) f = 0;
        if(2 * mi != ma) f = 0;
        if(f) printf("Case #%d: Yes\n", di++);
        else printf("Case #%d: No\n", di++);
    }
    return 0;
}
    
