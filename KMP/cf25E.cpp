#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100050;

char str[3][maxn];
int next[3][maxn], len[3];

void get_next(int x) {
	int k = -1, j = 0;
	next[x][0] = -1;
	while (j < len[x]) {
		if (k == -1 || str[x][k] == str[x][j]) {
			++k;
			++j;
			next[x][j] = k;
		}
		else k = next[x][k];
	}
}

int kmp(int x, int y) {
	int j = 0, k = 0;
	while (j < len[y] && k < len[x]) {
		if (j == -1 || str[x][k] == str[y][j]) {
			j++, k++;
		}
		else j = next[y][j];
	}
	return j;   // the maximum match
}

int main() {
	while (scanf("%s%s%s", str[0], str[1], str[2]) != EOF) {
		len[0] = strlen(str[0]);
		len[1] = strlen(str[1]);
		len[2] = strlen(str[2]);
		for (int i = 0; i < 3; i++)
			get_next(i);
		int ans = -10;
		for (int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++) {
				if (i == j) 
					continue;
				for (int k = 0; k < 3; k++) {
					if (k == j || k == i)
						continue;
					int z = kmp(i, j);
					int tmp = z;
					if (len[j] == z)
						tmp += kmp(i, k);
					else tmp += kmp(j, k);
					ans = max(ans, tmp);
				}
			}
		printf("%d\n", (len[0] + len[1] + len[2]) - ans);
	}	
	return 0;
}
