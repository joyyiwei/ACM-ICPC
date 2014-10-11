#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;
const int maxn = 400005;

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

int k, in[maxn], r[maxn], l[maxn];
char str[maxn];

int check(int mid, int n, int out) {
	int vis[105];
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	
	for (int i = 1; i <= n; i++) {
		if (height[i] < mid) {
			if (out && cnt > k / 2) {
				for (int j = 0, m = sa[i-1]; j < mid; j++)
					printf("%c", r[j+m]);
				printf("\n");
			}
			cnt = 0;
			memset(vis, 0, sizeof(vis));
		}
		else {
			if (!vis[in[sa[i-1]]]) {
				vis[in[sa[i-1]]] = 1;
				cnt++;
			}
			if (!vis[in[sa[i]]]) {
				vis[in[sa[i]]] = 1;
				cnt++;
			}
			if (!out && cnt > k / 2)
				return 1;
		}
	}
	return 0;
}

int main() {
	int first = 0;
	while (scanf("%d", &k) != EOF && k) {
		int n = 0;
		if (first) printf("\n");
		else first = 1;
		
		for (int i = 0; i < k; i++) {
			scanf("%s", str);
			l[i] = strlen(str);
			for (int j = n; j < n+l[i]; j++) {
				r[j] = str[j-n];
				in[j] = i;
			}
			n += l[i] + 1;
			r[n-1] = 128 + i;
		}
		n--;
		r[n] = 0;
		build_sa(r, n+1, 300);
		getHeight(r, n);

		int left = 0, right = 1000, mid, ans = -1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (check(mid, n, 0)) {
				ans = mid;
				left = mid + 1;
			}
			else right = mid - 1;
		}
		
		if (ans <= 0) printf("?\n");
		else check(ans, n, 1);
	}
	return 0;
}
