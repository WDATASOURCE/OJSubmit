#include<iostream>
using namespace std;

bool iscan(int m , int n , int *s, int key){
    int be = 0, i;
    for(i = 0; i < n; i++){
        if(s[i] - be > key){
            be = s[i-1];
            m--;
        }
    }
    m--;
    if(m < 0)
        return false;
    return true;
    
}

void find(int n , int *s ,int m , int sum){
    int l = 0 , r = sum , mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(iscan(m , n , s , mid)) r = mid;
        else l = mid;
        }
        cout << r <<endl;
        }

int main(){
    ios::sync_with_stdio(false);
    int n , m , i , sum = 0;
    cin >> n >> m;
    int *p = new int[n];
    int *s = new int[n];
    for( i = 0 ; i < n ; i++){
        cin >> p[i];
        sum += p[i];
        s[i] = sum;
    }
    find(n, s, m , sum);
    return 0;
    }
    


