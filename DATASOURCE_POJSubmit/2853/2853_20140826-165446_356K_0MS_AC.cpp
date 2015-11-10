#include <cstdio>
int main() {
	int number, t, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &j, &number);
		int ans = 0, sum = 0;
		for(int i = 1; (i + 2) * (i + 1) <= 2 * number; ++i){
			sum += i;
			if((number - sum) % (i + 1) == 0) ++ans;
		}
		printf("%d %d\n", j, ans);
	}
	return 0;
}
