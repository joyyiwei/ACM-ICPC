#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 200005;
const int mod = 10007;

int dp[maxn], next[maxn], n;
char pattern[maxn];

int getNext() {
	int m = strlen(pattern);
	next[0] = next[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = next[i];
		while (j && pattern[i] != pattern[j])
			j = next[j];
		next[i+1] = pattern[i] == pattern[j] ? j+1 : 0;
	}

	memset(dp, 0, sizeof(dp));
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = (dp[next[i]] + 1) % mod;
		sum = (sum + dp[i]) % mod;
	}
	return sum;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", pattern);
		printf("%d\n", getNext());
	}
	return 0;
}
