#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;

char pattern[maxn];  
int next[maxn];

void getNext() {
	int m = strlen(pattern);
	next[0] = 0, next[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = next[i];
		while (j && pattern[i] != pattern[j])
			j = next[j];
		next[i+1] = pattern[i] == pattern[j] ? j+1 : 0; 
	}

	int len = m - next[m];
	if (len == 1)
		printf("0\n");
	else if (len == m)
		printf("%d\n", m);
	else if (next[m] > 0 && (m % len) == 0)
		printf("0\n");
	else {
		int num = m / len;
		printf("%d\n", len-(m-len*num));
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", pattern);		
		getNext();
	}
	return 0;
}
