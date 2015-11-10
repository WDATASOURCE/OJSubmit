//
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 10000
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[N];
char ch[7];
int b, m, vis, k;

void change(){
    int i, j = 0, f = 0, f1 = 0;                                    // f1 用来记录输入的数是否是一个整数, 即没有小数点;
    m = 0;                                                          // m 用来存储 输入的数(浮点型);
    fill(a, a + N + 1, 0);
    k = 0;
    for(i = 0; i < 6; i++)
        if(ch[i] == '.')
            f1 = 1;
    if(f1 == 1){                                                    // 输入的如果是一个浮点数, 即有小数点时执行下面的部分;
        for(i = 5; i >= 0; i--){
            if(ch[i] != '0')                                        // 以下 vis 记录了小数点的位置, 将ch数组中的数倒序放在a 数组中, 并且忽略小数末尾的零;
                f = 1;
            if(f == 1)
                k++;
            if(ch[i] == '.')
                vis = k, f = 1;
            else if(f == 1)
                a[j++] = ch[i] - '0';
        }
    }
    else{                                                           // 当输入的是一个整数(即没有小数点)时,直接倒序存放在a 数组中;
        for(i = 5; i >= 0; i--)
            a[k++] = ch[i] - '0';
        vis = 1;
    }
    vis--;
    for(k = 6; k >= 0; k--)                                         // 以下将输入的数去掉小数点后存放在 m ;
        if(a[k])
            break;
    for(i = k; i >= 0; i--)
        m = m * 10 + a[i];
    return;
}

void calculate(){
    int i = b - 1, j;
    while(i--){                                                     // 模拟乘法运算;
        int c = 0;
        for(j = 0; j < N; j++){
            int s = a[j] * m + c;
            a[j] = s % 10;
            c = s / 10;
        }
    }
    int rea = vis * b;                                              // rea 中保存的是 乘法结束后 结果的小数点位数;
    for(j = N - 1; j >= 0; j--)                                     // 以下为结果的输出, 需要去掉整数前的0,若位数不够小数的位数,要在小数点后面补0;
        if(a[j])                                                    // 先找到最高位的坐标, 并用 j 记录下来;
            break;
    if(j == -1)                                                     // 若 j 为 -1 说明, 整个数组a中都是0, 即结果为0;
        cout << 0 << endl;
    else if(j < rea){                                               // 如果a中不为零的位数比结果应当有的小数位数少, 则需要在小数点后补零;
        cout <<".";
        for(i = rea - j - 1; i > 0; i--)                            // 输出要补的零;
            cout << 0 ;
        for(i = j; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
    else{
        for(i = j; i >= rea; i--)                                   // 在适当的位置插入小数点;
            cout << a[i];
        if(rea != 0)
            cout <<".";
        for(i = rea - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
    return;
}

int main() {
    int i;
    ios_base::sync_with_stdio(false);
    while(cin >> ch >> b){
        if(b == 0){                                                 // 当指数为0时直接输出 1;
            cout << 1 << endl;
            continue;
        }
        change();
        calculate();
        fill(ch, ch + 7, '\0');
    }
	return 0;
}
