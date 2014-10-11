#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;
const int maxn = 100010;

int sa[maxn]; 
int t1[maxn], t2[maxn], c[maxn];
int rank[maxn], height[maxn];

void build_sa(int s[], int n, int m) {
	int i, j, p, *x = t1, *y = t2;
	for (i = 0; i < m; i++) c[i] = 0;
	for (i = 0; i < n; i++) c[x[i] = s[i]]++;
	for (i = 1; i < m; i++) c[i] += c[i-1];
	for (i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;

	for (j = 1; j <= n; j <<= 1) {
		p = 0;
		for (i = n-j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) 
			if (sa[i] >= j) 
				y[p++] = sa[i] - j;
		for (i = 0; i < m; i++) c[i] = 0;
		for (i = 0; i < n; i++) c[x[y[i]]]++;
		for (i = 1; i < m; i++) c[i] += c[i-1];
		for (i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

		swap(x, y);
		p = 1, x[sa[0]] = 0;
		for (i = 1; i < n; i++) 
			x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+j] == y[sa[i]+j] ? p-1 : p++;

		if (p >= n) break;
		m = p;
	}
}

void getHeight(int s[],int n) {
	int i, j, k = 0;
	for (i = 0; i <= n; i++)
		rank[sa[i]] = i;

	for (i = 0; i < n; i++) {
		if (k) k--;
		j = sa[rank[i]-1];
		while (s[i+k] == s[j+k]) k++;
		height[rank[i]] = k;
	}
}

char str[maxn];
int r[maxn];

int main() {
	while (scanf("%s", str) != EOF) {
		int n = strlen(str);
		for (int i = 0; i <= n; i++)
			r[i] = str[i];

		build_sa(r, n+1, 128);
		getHeight(r, n);

		int ans = n;
		int mid = rank[0];
		int tmp = n;
		while (mid < n) {
			tmp = min(tmp, height[mid+1]);
			mid++;
			ans += tmp;
		}
		mid = rank[0];
		tmp = n;
		while (mid > 1) {
			tmp = min(tmp, height[mid]);
			mid--;
			ans += tmp;
		}

		printf("%d\n", ans % 256);
	}
	return 0;
}
