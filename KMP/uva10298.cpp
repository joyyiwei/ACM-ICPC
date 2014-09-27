#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000000;

char str[MAXN];
int next[MAXN];

int main() {
	while (scanf("%s", str) != EOF && str[0] != '.') {
		int len = strlen(str);
		int i = 0, j = -1;
		next[0] = -1;
		while (i < len) {
			if (j == -1 || str[i] == str[j]) {
				i++, j++;
				next[i] = j;
			}
			else j = next[j];
		}
		printf("%d\n", len/(len-next[len]));
	}
	return 0;
}
