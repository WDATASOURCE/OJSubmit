// 用数组的下标来充当电话号码;
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#define M 10000010

int ph[M];
int n;
char ch[500];

using namespace std;

void change(){
    int i, m = 0;
    for(i = 0; ch[i]; i++){
        if(ch[i] >= '0' && ch[i] <= '9')
            m = m * 10 + ch[i] - '0';
        else if(ch[i] >= 'A' && ch[i] <= 'C')
            m = m * 10 + 2;
        else if(ch[i] >= 'D' && ch[i] <= 'F')
            m = m * 10 + 3;
        else if(ch[i] >= 'G' && ch[i] <= 'I')
            m = m * 10 + 4;
        else if(ch[i] >= 'J' && ch[i] <= 'L')
            m = m * 10 + 5;
        else if(ch[i] >= 'M' && ch[i] <= 'O')
            m = m * 10 + 6;
        else if(ch[i] >= 'P' && ch[i] <= 'S' && ch[i] != 'Q')
            m = m * 10 + 7;
        else if(ch[i] >= 'T' && ch[i] <= 'V')
            m = m * 10 + 8;
        else if(ch[i] >= 'W' && ch[i] <= 'Y')
            m = m * 10 + 9;
    }
    ph[m]++;
    return;
}

void print(int x){
    int i, j = x;
    int a[8];
    for(i = 6; i >= 0; i--){
        a[i] = j % 10;
        j = j / 10;
    }
    for(i = 0; i < 7; i++){
        if(i == 3)
            cout << '-';
        cout << a[i];
    }
    cout <<" "<< ph[x] << endl;
    return;
}

int main() {
    int i, f = 0;
    ios_base::sync_with_stdio(false);
    while(cin >> n){
        fill(ph, ph + 10000000, 0);
        for(i = 0; i < n; i++){
            fill(ch, ch + 20, '\0');
            cin >> ch;
            change();
        }
        for(i =0; i < 10000000; i++)
            if(ph[i] > 1)
                print(i), f = 1;
        if(f == 0)
            cout <<"No duplicates. "<< endl;
    }
    return 0;
}
