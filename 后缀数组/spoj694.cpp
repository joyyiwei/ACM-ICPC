#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1010;

int sa[maxn]; //SA数组，表示将S的n个后缀从小到大排序后把排好序的
//的后缀的开头位置顺次放入SA中
int t1[maxn], t2[maxn], c[maxn];
int rank[maxn], height[maxn];
int s[maxn];
char str[maxn];

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
		height[rank[i]]=k;
	}
}

int check(int n, int k, int mid) {
	int num = 1;
	for (int i = 2; i <= n; i++) {
		if (height[i] >= mid) {
			num++;
			if (num >= k) return 1;
		}
		else num = 1;
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int n = strlen(str);
		for (int i = 0; i <= n; i++)
			s[i] = str[i];
		build_sa(s, n+1, 128);
		getHeight(s, n);

		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += n - sa[i] - height[i];

		printf("%d\n", ans);
	}
	return 0;
}
