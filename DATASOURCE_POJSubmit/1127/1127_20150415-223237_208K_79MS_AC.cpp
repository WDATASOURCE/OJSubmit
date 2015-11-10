#include <iostream>
#include <memory>
#define MAX_N 13
#define MAXV(x, y) ((x) >= (y) ? (x) : (y))
#define MINV(x, y) ((x) <= (y) ? (x) : (y))
using namespace std;
int num;
struct node
{
    int x1, y1, x2, y2;
}data[MAX_N + 1];
int set[MAX_N + 1];
int rank[MAX_N + 1];

int direct(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);    
}

bool onLine(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (MINV(x1, x2) <= x3 && x3 <= MAXV(x1, x2) && MINV(y1, y2) <= y3 && y3 <= MAXV(y1, y2));
}

bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int d1 = direct(x3, y3, x4, y4, x1, y1);
    int d2 = direct(x3, y3, x4, y4, x2, y2);
    int d3 = direct(x1, y1, x2, y2, x3, y3);
    int d4 = direct(x1, y1, x2, y2, x4, y4);
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;
    if(d1 == 0 && onLine(x3, y3, x4, y4, x1, y1)) return true;
    else if(d2 == 0 && onLine(x3, y3, x4, y4, x2, y2)) return true;
    else if(d3 == 0 && onLine(x1, y1, x2, y2, x3, y3)) return true;
    else if(d4 == 0 && onLine(x1, y1, x2, y2, x4, y4)) return true;
    else return false;
}

int find(int pos) {
    if(pos != set[pos]) set[pos] = find(set[pos]);
    return set[pos];
}

void joinSet(int pos1, int pos2) {
    if(pos1 == pos2) return;
    int pre1 = find(pos1);
    int pre2 = find(pos2);
    if(pre1 == pre2) return;
    else {
        int rank1 = rank[pre1];
        int rank2 = rank[pre2];
        if(rank1 < rank2) set[pre1] = pre2;
        else if(rank1 > rank2) set[pre2] = pre1;
        else {
            rank[pre1]++;
            set[pre2] = pre1;
        }
    }
}

void init() {
    int i; 
    for(i = 1; i <= num; i++) {
        set[i] = i;
        rank[i] = 0;
    }
}

int main() {
    int i, n1, n2, pre1, pre2;
    while(cin>>num && num != 0) {
        for(i = 1; i <= num; i++)
            cin>>data[i].x1>>data[i].y1>>data[i].x2>>data[i].y2;
        init();
        for(n1 = 1; n1 <= num; n1++) {
            for(n2 = n1; n2 <= num; n2++) {
                pre1 = find(n1);
                pre2 = find(n2);
                if(pre1 == pre2) continue;
                else {
                    if(intersect(data[n1].x1, data[n1].y1, data[n1].x2, data[n1].y2, 
                        data[n2].x1, data[n2].y1, data[n2].x2, data[n2].y2))
                        joinSet(n1, n2);
                }
            }
        }
        while(cin>>n1>>n2 && !(n1 == 0 && n2 == 0)) {
            pre1 = find(n1);
            pre2 = find(n2);
            if(pre1 == pre2) cout<<"CONNECTED"<<endl;
            else cout<<"NOT CONNECTED"<<endl;
        }
    }
    return 0;
}
