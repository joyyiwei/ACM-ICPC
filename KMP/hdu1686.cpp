#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000010;

char a[maxn], b[maxn];
int next[maxn];
int n, m;

void getnext() {
	int m = strlen(a);
	next[0] = 0, next[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = next[i];
		while (j && a[i] != a[j])
			j = next[j];
		next[i+1] = a[i] == a[j] ? j+1 : 0;
	}
}

int kmp() {
	int ans = 0;
	int n = strlen(b);
	int m = strlen(a);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j && a[j] != b[i])
			j = next[j];
		if (a[j] == b[i])
			j++;
		if (j == m)
			ans++;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", a, b);
		getnext();
		int ans = kmp();
		printf("%d\n", ans);
	}
	return 0;
}
