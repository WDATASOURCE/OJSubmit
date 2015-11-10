#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct TrieNode {
	TrieNode * next[10];
	int num;
	int isEnd;
	TrieNode() {
		for (int i = 0; i < 10; i ++) next[i] = NULL;
		isEnd = 0;
		num = 0;
	}
};

TrieNode * root;
TrieNode memory[600010];
int tol = 0;

bool insertTrie(char str[]) {
	TrieNode * cur = root;
	int k;
	for (int i = 0; str[i]; i ++) {
		k = str[i] - '0';
		if (cur->next[k] == NULL) {
			cur->next[k] = &memory[tol ++];
		} else {
			cur->next[k]->num ++;
			if (cur->next[k]->isEnd) return false;
		}
		cur = cur->next[k];
	}
	cur->isEnd ++;
	if (cur->num) return false;
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int T, n;
	char str[12];
	scanf("%d", &T);
	while (T --) {
		tol = 0;
		memset(memory, 0, sizeof(memory));
		root = &memory[tol ++];
		scanf("%d", &n);
		bool flag = true;
		for (int i = 0; i < n; i ++) {
			scanf("%s", str);
			if (flag) {
				flag = insertTrie(str);
			}
		}
		if (!flag) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}