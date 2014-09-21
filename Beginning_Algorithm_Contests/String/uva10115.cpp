#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[220][220];
char b[220][220];
char c[220];

int main()
{
	int t;
	while(cin>>t && t)
	{
		getchar();
		for(int i = 1; i <= t ; i++)
		{
			gets(a[i]);
			gets(b[i]);
		}
		gets(c);
		for(int i = 1 ; i <= t ; i++)
		{
			char *pos;
			while((pos=strstr(c,a[i])) != NULL )  // 用strstr函数找到子串
			{
				int len1 = strlen(a[i]);
				int len2 = strlen(b[i]);
				char d[220];
				int cur = 0;
				for(int j = 0 ; j < pos-c ; j++)
					d[cur++] = c[j];
				for(int j = 0 ; j < len2 ; j++)
					d[cur++] = b[i][j];
				for(int j = (pos-c)+len1 ; j < strlen(c) ; j++ )
					d[cur++] = c[j];
				d[cur] = '\0';
				strcpy(c,d);
			}
		}
		cout<<c<<endl;
	}
	return 0 ;
}
