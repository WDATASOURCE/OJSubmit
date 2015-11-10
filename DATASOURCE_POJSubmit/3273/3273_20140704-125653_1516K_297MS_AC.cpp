#include<iostream>
using namespace std;

bool iscan(int m , int n , int *s, int key){
    int be = 0, i;
    for(i = 0; i < n; i++){
        if(s[i] - be > key){
            be = s[i - 1];
            m--;
        }
    }
    m--;
    if(m < 0)
        return false;
    return true;
    
}


void find(int n , int *s ,int m , int sum , int mx ){
    int l = mx - 1 , r = sum , mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(iscan(m , n , s, mid))  { r = mid;}
        else l = mid;
    }
    cout << r <<endl;
}

int main(){
    ios::sync_with_stdio(false);
    int n , m , i , sum = 0 , mx = 0;
    while(cin >> n >> m){
        sum = 0;
        mx = 0;
        int *p = new int[n];
        int *s = new int[n];
        for( i = 0 ; i < n ; i++){
            cin >> p[i];
            sum += p[i];
            s[i] = sum;
            if(p[i] > mx)
                mx = p[i];
        }
        find(n, s, m , sum ,mx);
    }
    return 0;
}
    


