#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
int a[110];
int sum[110];

int main()
{
	char s[110];
	memset(sum,0,sizeof(sum));
	while (scanf("%s",s) != EOF )
	{
		memset(a,0,sizeof(a));
		if (s[0] == '0')
			break;
		int len = strlen(s);
		for (int i = len-1,j=0 ; i >= 0 ; i--,j++)
			a[j] = s[i] - '0';
		int c = 0;
		for (int i = 0 ; i < MAXN ; i++)
		{
			int t = a[i]+sum[i]+c;
			sum[i] = t % 10 ;
			c = t / 10 ;
		}
	}
	//输出
	int b;
	for ( b = MAXN ; b >= 0 ; b--)
		if (sum[b])
			break;
	for (int i = b ; i >= 0 ; i--)
		printf("%d",sum[i]);
	printf("\n");
	return 0;
}
