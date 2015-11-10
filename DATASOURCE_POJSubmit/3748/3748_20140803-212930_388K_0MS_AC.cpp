#include<cstdio>
#include<algorithm>
using namespace std;

int bits[33];

int main(){
    int r, x, y, i;
    while(scanf("%x,%d,%d", &r, &x, &y) == 3){
        fill(bits, bits + 32, 0);
        for(i = 0; i < 32; i++)
            bits[i] = (r >> i) & 1;
        bits[x] = 0;
        bits[y] = 1;
        bits[y - 1] = 1;
        bits[y - 2] = 0;
        r = 0; 
        for(i = 0; i < 32; i++)
            r |= (bits[i] << i);
        printf("%x\n", r);
    }
    return 0;
}
            
