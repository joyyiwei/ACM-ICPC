#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const long long MAXN = 1000000;
char str[MAXN];
char newstr[MAXN];
long long n;

int main()
{
	char ch;
	memset(str,0,sizeof(str));
	while (scanf("%s",str) != EOF )
	{
		memset(newstr,0,sizeof(newstr));
		n = 0 ;
		ch = getchar();
		while (ch == ' ')
			ch = getchar();
		cin >> n ;
		getchar();
		long long mod = 0 ;
		long long num = 0 ;
		long long len = strlen(str);
		if (ch == '%')
		{
			for (long long i = 0 ; i < len ; i++)
			{
				mod = mod*10 + str[i] - '0';
				if (mod >= n)
					mod = mod % n ;   //我们每次都去掉n，减少计算规模
			}
			cout<<mod<<endl;
		}
		int flag=0,k=0;
		int flag1 = 0 ;
		if (ch == '/')
		{
			for (long long i = 0 ; i < len ; i++)  // 小于 n 的判断
			{
				num = num * 10 + str[i] - '0' ;
				if (num >= n)
				{
					flag1 = 1;
					break;
				}
			}
			num = 0 ;
			if ( !flag1 )
				cout<<'0'<<endl;
			else 
			{
				for (long long i = 0 ; i < len ; i++)  //手动模拟除法
				{
					num = num*10 + str[i] - '0';
					if (num < n && flag )    // 第一位数是0的话是不被我们记录的
						newstr[k++]	= '0' ;
					if ( num >= n )
					{
						flag = 1 ;
						newstr[k++] = num/n + '0' ;
						num %= n ;
					}
				}
				cout<<newstr<<endl;
			}
			memset(str,0,sizeof(str));
		}
	}
	return 0;
}
