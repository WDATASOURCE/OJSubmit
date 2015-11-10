#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define M 800
using namespace std;

struct ss{
    int x, y;
};

ss s[M];
int n;

void solute(){
    int i, j, k, sum = 0, su = 2;
    for(i = 0; i < n; i++){
    	for(j = i + 1; j < n; j++){
    		su = 2;
    		for(k = j + 1; k < n; k++){
    			if((s[k].y - s[i].y) * (s[j].x - s[i].x ) == (s[k].x - s[i].x) * (s[j].y - s[i].y))
    			su++;
    		}
    		if(su > sum)
    		sum = su;
    	}
    }
    cout << sum << endl;
    return;
}

int main(){
    int i, j;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        else
            for(i = 0; i < n; i++)
                cin >> s[i].x >> s[i].y;
        if(n == 1)
            cout << 1 << endl;
        else if(n == 2)
            cout << 2 << endl;
        else
            solute();
    }
    return 0;
}