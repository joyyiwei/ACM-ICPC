#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 70;

int m, next[maxn];
char DNA[11][maxn];

void getNext(char *str) {
	int len = strlen(str);
	next[0] = next[1] = 0;
	for (int i = 1; i < len; i++) {
		int j = next[i];
		while (j && str[i] != str[j])
			j = next[j];
		next[i+1] = str[i] == str[j] ? j+1 : 0;
	}
}

int kmp(char *str, char *tmp) {
	getNext(str);
	int len = strlen(str);
	int j = 0;
	for (int i = 0; i < 60; i++) {
		while (j && str[j] != tmp[i])
			j = next[j];
		if (str[j] == tmp[i])
			j++;
		if (j == len) 
			return 1;
	}
	return 0;
}

int main() {
	int t;
	char ans[maxn], tmp[maxn];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%s", DNA[i]);
		int maxLen = 0;
		for (int i = 0; i < 60; i++) {
			memset(tmp, '\0', sizeof(tmp));
			int cnt = 0;
			for (int j = i; j < 60; j++) {
				tmp[cnt++] = DNA[0][j];
				int vis = 1;
				for (int k = 1; k < m; k++)
					if (!kmp(tmp, DNA[k])) {
						vis = 0;
						break;
					}
				if (vis) {
					if (maxLen < cnt) {
						maxLen = cnt;
						memcpy(ans, tmp, sizeof(tmp));
					}
					else if(maxLen == cnt && strcmp(ans, tmp) > 0)
						memcpy(ans, tmp, sizeof(tmp));
				}
			}
		}

		if (maxLen < 3)
			printf("no significant commonalities\n");
		else printf("%s\n", ans);
	}
	return 0;
}
