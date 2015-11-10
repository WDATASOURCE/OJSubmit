#include<iostream>
using namespace std;
char ch[65][20];
int vis[65];
int n, s, w;

void change(){
    int i = 1, j = n;
    while(i <= s * n){
        if(w + i - 1 > n)
            w = w - n;
        if(i % s == 0 && vis[w + i - 1] == 0){
            cout << ch[w + i - 1] << endl;
            vis[w + i - 1] = 1;
            i++;
        }
        else if(vis[w + i - 1] == 0)
            i++;
        else
            w++;
    }
    return;
}

int main(){
    int i;
    char a;
    cin >> n;
    fill(vis, vis + n + 1, 0);
    cin.ignore();
    for(i = 1; i <= n; i++)
        cin.getline(ch[i], 20);
    cin >> w >> a >> s;  
    change(); 
    return 0;
}
