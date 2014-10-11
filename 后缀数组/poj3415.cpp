#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;
const int maxn = 200010;

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

int r[maxn];
int st[maxn], num[maxn];
char str1[maxn], str2[maxn];
int k, len1, len2;

ll solve(int n, int k) {
	ll i, j, tp, ans = 0;
	ll tot, top;
	for (i = 1; i <= n; i++) {
		if (height[i] < k) tot = top = 0;
		else {
			tp = 0;
			if (sa[i-1] > len1) {
				tp = 1;
				tot += height[i] - k + 1;
			}

			while (top > 0 && st[top] >= height[i]) {
				tot -= num[top] * (st[top] - height[i]);
				tp += num[top];
				top--;
			}

			st[++top] = height[i];
			num[top] = tp;
			if (sa[i] < len1)
				ans += tot;
		}
	}

	for (i = 1; i <= n; i++) {
		if (height[i] < k) tot = top = 0;
		else {
			tp = 0;
			if (sa[i-1] < len1) {
				tp = 1;
				tot += height[i] - k + 1;
			}

			while (top > 0 && st[top] >= height[i]) {
				tot -= num[top] * (st[top] - height[i]);
				tp += num[top];
				top--;
			}

			st[++top] = height[i];
			num[top] = tp;
			if (sa[i] > len1)
				ans += tot;
		}
	}
	return ans;
}

int main() {
	int i, j;
	while (scanf("%d", &k) != EOF && k) {
		scanf("%s%s",str1,str2);  
		for (i = 0; str1[i]; ++i)  
			r[i] = str1[i];  
		r[i] = '$',len1 = i,i++;  
		for (j = 0; str2[j];j++)  
			r[i+j] = str2[j];  
		r[i+j] = 0;
		int len = i + j; 

		build_sa(r, len+1, 128);
		getHeight(r, len);

		printf("%lld\n", solve(len, k));
	}
	return 0;
}
