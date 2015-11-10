/* 题目的意思是 有20000  个数, 让你找出其中  相加的和小于等于 s 的两个数的对数;
 * 这个程序运用了两次二分来简化双重循环;
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[20001];

int bin_search(int i, int j, const int &key){
    int point;
    while(i < j){
        point = (i + j + 1) >> 1;
        if (a[point] <= key)
            i = point;
        else
            j = point - 1;
    }
    return i;
}

int main(){
    int n, s, k, p, ans;
    while(scanf("%d%d", &n, &s) != EOF){
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        ans = 0;
        k = bin_search(0, n - 1, s);                        // 找到第一个小于等于  s  的数的下标;
        for (int i = 1; i <= k; i++){
            p = bin_search(0, i - 1, s - a[i]);             // 枚举每一个 小于等于  s  的数, 二分找到相加小于等于 s 的数的下标 直接下标相加; 
            ans += p + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
