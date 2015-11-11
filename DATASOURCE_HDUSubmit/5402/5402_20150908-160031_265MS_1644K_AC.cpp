/*
ID: LinKArftc
PROG: g.cpp
LANG: C++
*/

#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-8
#define randin srand((unsigned int)time(NULL))
#define input freopen("input.txt","r",stdin)
#define debug(s) cout << "s = " << s << endl;
#define outstars cout << "*************" << endl;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int INF = 0x7fffffff;
typedef long long ll;

const int maxn = 105;

int n, m;
int mp[maxn][maxn];

int cnt;
char ch[11000];

inline void print(char c){
    ch[cnt++] = c;
}

void print(int s_x, int s_y, int e_x, int e_y) {
    if (s_x == 1) {
        while (1) {
            for (int i = 1; i < n; i ++) print('D');
            print('R');
            for (int i = 1; i < n; i ++) print('U');
            s_y ++;
            if (s_y == e_y) break;
            else{ 
                s_y ++;
                print('R');
            }
        }
    } else {
        while (1) {
            for (int i = 1; i < n; i ++) print('U');
            print('R');
            for (int i = 1; i < n; i ++) print('D');
            s_y ++;
            if (s_y == e_y) break;
            else{ 
                s_y ++;
                print('R');
            }
        }
    }
}

void print(int min_x, int min_y) {
    int cur_x = 1, cur_y, end_x = n, end_y;
    if (min_y & 1) {
        cur_y = min_y;
        end_y = min_y + 1;
    } else {
        cur_y = min_y - 1;
        end_y = min_y;
    }
    while (1) {
        if (cur_y & 1) {
            if (cur_x == min_x) {
                print('D');
                print('R');
                cur_x ++;
                cur_y ++;
                if (cur_x == end_x && cur_y == end_y) break;
                else {
                    print('D');
                    cur_x ++;
                }
            } else {
                print('R');
                cur_y ++;
                if (cur_x == end_x && cur_y == end_y) break;
                else {
                    print('D');
                    cur_x ++;
                    if (cur_x == end_x && cur_y == end_y) break;
                }
            }
        } else {
            if (cur_x == min_x) {
                print('D');
                cur_x ++;
                if (cur_x == end_x && cur_y == end_y) break;
                else {
                    print('L');
                    print('D');
                    cur_x ++;
                    cur_y --;
                }
            } else {
                print('L');
                print('D');
                cur_x ++;
                cur_y --;
            }
        }
    }
}

int main() {

    //input;
    while (~scanf("%d %d", &n, &m)) {
        cnt = 0;
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                scanf("%d", &mp[i][j]);
                sum += mp[i][j];
            }
        }
        if(n == 2 && m == 2){
            if(mp[1][2] > mp[2][1]){
                printf("%d\n", sum - mp[2][1]);
                printf("RD\n");
            }else{
                printf("%d\n", sum - mp[1][2]);
                printf("DR\n");
            }
            continue;
        }
        if (n & 1) {
            printf("%d\n", sum);
            int cur_x = 1;
            int cur_y = 1;
            while (1) {
                if (cur_x & 1) {
                    for (int j = 1; j < m; j ++) print('R');
                    cur_y = m;
                } else {
                    for (int j = 1; j < m; j ++) print('L');
                    cur_y = 1;
                }
                if (cur_x != n || cur_y != m) {
                    cur_x ++;
                    print('D');
                } else {
                    //printf("\n");
                    break;
                }
            }
        } else if (m & 1) {
            printf("%d\n", sum);
            int cur_x = 1;
            int cur_y = 1;
            while (1) {
                if (cur_y & 1) {
                    for (int i = 1; i < n; i ++) print('D');
                    cur_x = n;
                } else {
                    for (int i = 1; i < n; i ++) print('U');
                    cur_x = 1;
                }
                if (cur_x != n || cur_y != m) {
                    cur_y ++;
                    print('R');
                } else {
                    //printf("\n");
                    break;
                }
            }
        } else {
            int min_x, min_y;
            int mi = inf;
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= m; j ++) {
                    if (((i + j) & 1) && mp[i][j] < mi) {
                        mi = mp[i][j];
                        min_x = i;
                        min_y = j;
                    }
                }
            }
            printf("%d\n", sum - mi);
            if (min_y & 1) {
                if(min_y != 1){
                    print(1, 1, 1, min_y - 1);
                    print('R');
                }
                print(min_x, min_y);
                if(min_y + 1 != m){
                    print('R');
                    print(n, min_y + 2, n, m);
                }
            } else {
                if(min_y != 2){
                    print(1, 1, 1, min_y - 2);
                    print('R');
                }
                print(min_x, min_y);
                if(min_y != m){
                    print('R');
                    print(n, min_y + 1, n, m);
                }
            }
        }
        ch[cnt] = '\0';
        puts(ch);
    }
    return 0;
}