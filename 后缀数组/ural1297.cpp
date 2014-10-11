#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 2010;

int sa[maxn]; //SA数组，表示将S的n个后缀从小到大排序后把排好序的
//的后缀的开头位置顺次放入SA中
int t1[maxn], t2[maxn], c[maxn];
int rank[maxn], height[maxn];
int s[maxn], r[maxn];
char str[maxn];
int st[maxn][20];

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

void ST(int n) {
	for (int i = 1; i <= n; i++)
		st[i][0] = i;

	for (int j = 1; (1<<j) <= n; j++) {
		for (int i = 1; i + (1<<j) <= n; i++) {
			int p = st[i][j-1];	
			int q = st[i+(1<<(j-1))][j-1];
			st[i][j] = height[p] > height[q] ? q : p;
		}
	}
}

int RMQ(int i, int j) {
	int k = 0;
	if (i > j)
		swap(i, j);
	i++;

	while ((1<<(k+1)) <= j-i+1) k++;
	i = st[i][k];
	j = st[j-(1<<k)+1][k];

	return min(height[i], height[j]);
}

int main() {
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		int n = 2 * len + 1;
		for (int i = 0; i < len; i++)
			r[i] = str[i];
		r[len] = 1;
		for (int i = 0; i < len; i++)
			r[i+len+1] = str[len-1-i];

		r[n] = 0; //notice
		build_sa(r, n+1, 128);
		getHeight(r, n);
		
		ST(n);
		int mid = n >> 1;
		int ans = 0, cur = 0;
		for (int i = 0; i < mid; i++) {
			int j = RMQ(rank[i], rank[n-i-1]);  //奇对称
			if ((j<<1) - 1 > ans) { 
				ans = (j<<1) - 1;
				cur = i - j + 1;
			}
			if (i) {
				j = RMQ(rank[i], rank[n-i]); //偶对称
				if ((j << 1) > ans) {
					ans = j << 1;
					cur = i - j;
				}
			}
		}
		
		for (int i = cur; i < cur + ans; i++)
			printf("%c", r[i]);
		printf("\n");
	}
	return 0;
}
