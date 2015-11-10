#include <cstdio>
int main(){
	int n, i;
	while(scanf("%d", &n) != EOF){
		int cnt = 0;
		for(i = 0; i < 100; i++)
			if(n - i >= 0 && n - i < 100)
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
