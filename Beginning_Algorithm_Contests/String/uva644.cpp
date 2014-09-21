#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 20;

char str[maxn][maxn];

int cmp(int i, int j) {
	int k;
	for (k = 0; str[i][k] && str[j][k]; k++)
		if (str[i][k] != str[j][k])
			return 0;
	return 1;
}

int main() {
	int i = 0, ans = 1, flag = 0;
	while (scanf("%s", str[i]) != EOF) {
		if (str[i][0] == '9') {
			for (int k = 0; k < i; k++) {
				for (int j = k+1; j < i; j++) 
					if (cmp(k, j)) {
						printf("Set %d is not immediately decodable\n", ans++);
						flag = 1;
						break;
					}
				if (flag)
					break;
			}
			if (!flag)
				printf("Set %d is immediately decodable\n", ans++);
			i = 0, flag = 0;
		}
		else i++;
	}
	return 0;
}
