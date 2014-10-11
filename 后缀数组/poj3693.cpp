#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
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
int r[maxn];
int a[maxn];

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

int main() {
	int cas = 1;
	while (scanf("%s", str) != EOF && str[0] != '#') {
		int n = strlen(str);
		for (int i = 0; i <= n; i++)
			r[i] = str[i];
		
		build_sa(r, n+1, 128);
		getHeight(r, n);
		initRMQ(n);
		
		int cnt = 0, Max = 0;
		for (int l = 1; l < n; l++) {
			for (int i = 0; i + l < n; i += l) {
				int tmp = lcp(i, i+l);
				int step = tmp / l + 1;
				int k = i - (l - tmp % l);
				if (k >= 0 && tmp % l) 
					if (lcp(k, k+l) >= tmp)
						step++;

				if (step > Max) {
					Max = step;
					cnt = 0;
					a[cnt++] = l;
				}
				else if (step == Max)
					a[cnt++] = l;
			}	
		}

		int len = -1, st;
		for (int i = 1; i <= n && len == -1; i++) 
			for (int j = 0; j < cnt; j++) {
				int l = a[j];
				if (lcp(sa[i], sa[i]+l) >= (Max - 1) * l) {
					len = l;
					st = sa[i];
					break;
				}
			}

		str[st + len * Max] = 0;
		printf("Case %d: %s\n", cas++, str + st);
	}
	return 0;
}
