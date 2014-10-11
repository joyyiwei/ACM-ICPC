#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
//typedef long long ll;
typedef __int64 ll;
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
int dp[maxn][30];
char str[maxn];
int r[maxn], ind[maxn][30];
ll b[maxn];

void initRMQ(int n) {
	int m = floor(log(n+0.0) / log(2.0));  
	for (int i = 1; i <= n; i++) 
		dp[i][0] = height[i];  

	for (int i = 1; i <= m; i++) {  
		for (int j = n; j; j--) {  
			dp[j][i] = dp[j][i-1];  
			if (j+(1<<(i-1)) <= n)  
				dp[j][i] = min(dp[j][i], dp[j+(1<<(i-1))][i-1]);  
		}  
	}  
}

int lcp(int l, int r) {
	int a = rank[l], b = rank[r];  
	if (a > b) 
		swap(a,b);  
	a++;  
	int m = floor(log(b-a+1.0) / log(2.0));  
	return min(dp[a][m], dp[b-(1<<m)+1][m]);  
}

void init(int n) {
	int m = floor(log(n+0.0) / log(2.0));  
	for (int i = 1; i <= n; i++) 
		ind[i][0] = sa[i];  

	for (int i = 1; i <= m; i++) {  
		for (int j = n; j; j--) {  
			ind[j][i] = ind[j][i-1];  
			if (j+(1<<(i-1)) <= n)  
				ind[j][i] = min(ind[j][i], ind[j+(1<<(i-1))][i-1]);  
		}  
	}  
}

int rmq(int a, int b) {
	int m = floor(log(b-a+1.0) / log(2.0));  
	return min(ind[a][m], ind[b-(1<<m)+1][m]);  
}

int main() {
	while (scanf("%s", str) != EOF) {
		int n = strlen(str);	
		for (int i = 0; i <= n; i++)
			r[i] = str[i];
		build_sa(r, n+1, 128);
		getHeight(r, n);
		initRMQ(n);
		init(n);

		b[0] = 0;
		for (int i = 1; i <= n; i++)
			b[i] = b[i-1] + n - sa[i] - height[i];

		int m;
		scanf("%d", &m);
		ll k;
		int lastl = 0, lastr = 0;
		while (m--) {
			scanf("%I64d", &k);
			k = (k ^ lastl ^ lastr)  + 1;
			if (k > b[n]) {
				printf("0 0\n");
				lastl = 0;
				lastr = 0;
				continue;
			}
			int id = lower_bound(b+1, b+1+n, k) - b;
			k -= b[id-1];
			int len = height[id] + k;
			int ll = id;
			int rr = id;
			int L = id, R = n;
			while (L <= R) {
				int mid = (L + R) / 2;
				if (sa[id] == sa[mid] || lcp(sa[id], sa[mid]) >= len) {
					rr = mid;
					L = mid + 1;
				}
				else R = mid - 1;
			}

			int ansl = rmq(ll, rr) + 1;
			int ansr = ansl + len - 1;
			printf("%d %d\n", ansl, ansr);
			lastl = ansl;
			lastr = ansr;
		}
	}	
	return 0;
}
