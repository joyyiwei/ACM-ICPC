#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000010;

int a[MAXN],b[MAXN],next[MAXN];
int n,m;

void getnext(int b[]){
	int i = 0,j = -1,len = m-1;
	next[0] = -1;
	while (i < len){
		if (j == -1 || b[i] == b[j]){
			i++,j++;
			next[i] = j;
		}
		else j = next[j];
	}
}

int kmp(int n,int m){
	int i = 0, j = 0;
	while (i < n && j < m){
		if (j == -1 || a[i] == b[j])
			i++,j++;
		else j = next[j];
	}
	if (j == m)
		return i-j+1;
	else return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		for (int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		for (int j = 0; j < m; j++)
			scanf("%d",&b[j]);
		getnext(b);
		printf("%d\n",kmp(n,m));
	}
	return 0;
}
