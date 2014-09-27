#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;

char a[maxn], b[maxn];
int next[maxn];

void getfail(char *p) {
	int m = strlen(p);
	next[0] = 0, next[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = next[i];
		while (j && p[i] != p[j])
			j = next[j];
		next[i+1] = p[i] == p[j] ? j+1 : 0;
	}
}

int kmp() {
	int ans = 0;
	int n = strlen(a), m = strlen(b);	
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j && b[j] != a[i])
			j = next[j];
		if (b[j] == a[i])
			j++;
		if (j == m) {
			ans++;
			j = 0;
		}
	}
	return ans;
}

int main() {
	while (scanf("%s", a) != EOF && a[0] != '#') {
		scanf("%s", b);
		getfail(b);
		int ans = kmp();
		printf("%d\n", ans);
	}
	return 0;
}
