#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000005;

char pattern[maxn];
int next[maxn];

int main() {
	while (scanf("%s", pattern) != EOF) {
		int m = strlen(pattern);
		next[0] = next[1] = 0;
		for (int i = 1; i < m; i++) {
			int j = next[i];
			while (j && pattern[i] != pattern[j])
				j = next[j];
			next[i+1] = pattern[i] == pattern[j] ? j+1 : 0;
		}

		printf("%d\n", m-next[m]);
	}
	return 0;
}
