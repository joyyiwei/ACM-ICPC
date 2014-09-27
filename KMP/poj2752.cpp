#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 400010;

char pattern[maxn];
int next[maxn], flag;

void getNext() {
	int m = strlen(pattern);
	next[0] = next[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = next[i];
		while (j && pattern[i] != pattern[j]) 
			j = next[j];
		next[i+1] = pattern[i] == pattern[j] ? j+1 : 0;
	}
}

void dfs(int len) {
	if (len == 0)
		return;
	dfs(next[len]);
	if (!flag) {
		printf("%d", len);
		flag = 1;
	}
	else printf(" %d", len);
}

int main() {
	while (scanf("%s", pattern) != EOF) {
		getNext();
		int len = strlen(pattern);
		flag = 0;
		dfs(len);
		printf("\n");
	}	
	return 0;
}
