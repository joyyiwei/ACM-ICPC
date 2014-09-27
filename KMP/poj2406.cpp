#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000010;

char pattern[maxn];
int next[maxn];

void getNext() {
	int m = strlen(pattern);
	next[0] = next[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = next[i];
		while (j && pattern[i] != pattern[j])
			j = next[j];
		next[i+1] = pattern[i] == pattern[j] ? j+1 : 0;
	}

	int len = m - next[m];
	if (m % len == 0)
		printf("%d\n", m/len);
	else printf("1\n");
}

int main() {
	while (gets(pattern)) {
		if (strcmp(pattern, ".") == 0)
			break;
		getNext();
	}	
	return 0;
}
