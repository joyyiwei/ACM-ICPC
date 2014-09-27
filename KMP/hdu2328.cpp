#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn = 4010;
const int N = 210;

int n, next[Maxn];
char words[Maxn][N];

int cmp(const void *str1, const void *str2) {
	return strlen((char *)str1) - strlen((char *)str2);
}

void getNext(char *str) {
	int m = strlen(str);
	next[0] = next[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = next[i];
		while (j && str[i] != str[j])
			j = next[j];
		next[i+1] = str[i] == str[j] ? j+1 : 0;
	}
}

int kmp(char *text, char *str) {
	getNext(str);
	int n = strlen(text);
	int m = strlen(str);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j && text[i] != str[j])
			j = next[j];
		if (str[j] == text[i])
			j++;
		if (j == m)
			return 1;
	}
	return 0;
}

int main() {
	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; i++)
			scanf("%s", words[i]);
		qsort(words, n, sizeof(words[0]), cmp);
		char ans[Maxn], tmp[Maxn];
		int len = strlen(words[0]);
		int Max = 0;
		for (int i = 0; i < len; i++) {
			memset(tmp, '\0', sizeof(tmp));
			int pos = 0;
			for (int j = i; j < len; j++) {
				tmp[pos++] = words[0][j];
				getNext(tmp);

				int flag = 1;
				for (int k = 1; k < n; k++)
					if (kmp(words[k], tmp) == 0) {
						flag = 0;
						break;
					}
				if (flag && Max < pos) {
					Max = pos;
					memcpy(ans, tmp, sizeof(tmp));
				}
				else if (flag && Max == pos && strcmp(ans, tmp) > 0)
					memcpy(ans, tmp, sizeof(tmp));
			}
		}

		if (Max)
			printf("%s\n", ans);
		else printf("IDENTITY LOST\n");
	}
	return 0;
}

