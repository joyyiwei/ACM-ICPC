#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void add(int *sum,int *c,int n)
{
	int t = 0;
	for (int i = 0 ; i < n ; i++)   // 因为这里不是MAXN
	{
		int tmp = sum[i] + c[i] + t ;
		sum[i] = tmp % 10 ;
		t = tmp / 10 ;
	}
	if (t)  // notice 
		sum[n] = t ;
}

void mul(char *str1,char *str2)
{
	int a[550],b[550],c[500],sum[550];
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = len1-1 ; i >= 0 ; i--)
		a[len1-1-i] = str1[i] - '0';
	for (int i = len2 - 1 ; i >= 0 ; i--)
		b[len2-1-i] = str2[i] - '0';
	memset(sum,0,sizeof(sum));

	for (int i = 0 ; i < len1 ; i++)
	{
		memset(c,0,sizeof(c)); &nbsp; &nbsp;//记住每次都要初始化
		for (int j = 0 ; j < len2 ; j++ )
			c[i+j] = a[i] * b[j]; &nbsp; &nbsp; &nbsp;//自己动手试试就知道了
		add(sum,c,i+len2);
	}
	int n = len1+len2;
	while (!sum[n] && n )
		n--;
	for (int i = 0 ; i <= n ; i++)
		str1[i] = sum[n-i] + '0';
	str1[n+1] = '\0';
}

int main()
{
	char str1[550],str2[550];
	while (scanf("%s%s",str1,str2) != EOF )
	{
		mul(str1,str2);
		printf("%s\n",str1);
	}
	return 0;
}
