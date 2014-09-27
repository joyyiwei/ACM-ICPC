#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000005;

int next[maxn], n, m;
char pattern[maxn];
char s1[maxn], s2[maxn];

void getNext() {
	int len = strlen(pattern);
	next[0] = next[1] = 0;
	for (int i = 1; i < len; i++) {
		int j = next[i];
		while (j && pattern[i] != pattern[j])
			j = next[j];
		next[i+1] = pattern[i] == pattern[j] ? j+1 : 0;
	}

	int ans = next[len];
	if (ans == 0)
		printf("0\n");
	else {
		s1[ans] = '\0';
		if (n > m) {
			if (ans > m)
				printf("%s %d\n", s2, m);
			else printf("%s %d\n", s1, ans);
		}	
		else {
			if (ans > n)
				printf("%s %d\n", s1, n);
			else printf("%s %d\n", s1, ans);
		}
	}
}

int main() {
	while (scanf("%s%s", s1, s2) != EOF) {
		n = strlen(s1), m = strlen(s2);
		memcpy(pattern, s1, sizeof(s1));
		strcat(pattern, s2);
		getNext();
	}	
	return 0;
}
