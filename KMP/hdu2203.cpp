#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200005;

char text[maxn], pattern[maxn];
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
}

int kmp() {
	int n = strlen(text), m = strlen(pattern);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j && text[i] != pattern[j])
			j = next[j];	
		if (text[i] == pattern[j])
			j++;
		if (j == m)
			return true;
	}
	return false;
}

int main() {
	while (scanf("%s%s", text, pattern) != EOF) {
		char tmp[2*maxn];
		memcpy(tmp, text, sizeof(text));
		strcat(text, tmp);

		getNext();
		if (kmp())
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
