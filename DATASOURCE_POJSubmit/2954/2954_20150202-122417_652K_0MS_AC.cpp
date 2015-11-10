#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

struct Point{
    int x,y;    
}point[3];

int abs(int n){
    if(n >= 0) return n;
    else return -n;
}

int Gcd( int a , int b ){
   return  b == 0 ? a : Gcd(b, a % b);    
}

int Area(Point a, Point b, Point c){
   return abs((a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x)) / 2;    
}

int Edge(Point a, Point b, Point c){
   int E  = 0;
   E += Gcd(abs(a.x - b.x), abs(a.y - b.y));
   E += Gcd(abs(a.x - c.x), abs(a.y - c.y));
   E += Gcd(abs(b.x - c.x), abs(b.y - c.y));
   return E;    
}

int main(){
    while(1){
       int cnt = 0;
       for(int i = 0; i < 3; i++){
            scanf("%d%d", &point[i].x, &point[i].y);
            if(point[i].x == 0 && point[i].y == 0) cnt++;
       }
       if(cnt == 3) break;
       int area = Area(point[0], point[1], point[2]);
       int edge = Edge(point[0], point[1], point[2]);  
       printf("%d\n",area + 1 - edge / 2);    
    }
    return 0;
}
