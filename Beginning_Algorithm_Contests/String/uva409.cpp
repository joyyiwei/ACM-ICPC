#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char key[25][25];
char exe[75];
char excuses[25][75];
int cnt[100];
int k,e;

int find(char *tmp)		//找出key最多的借口，然后输出
{
	int sum = 0 ;
	for(int i = 0 ; i < k ; i++ )
	{
		if(strcmp(tmp,key[i]) == 0)
			sum++;
	}
	return sum;
}

int main()
{
	int cas = 1 ;
	while(scanf("%d%d",&k,&e) != EOF )
	{
		for(int i = 0 ; i < k ; i++)
			scanf("%s",key[i]);
		int max = 0 ;
		getchar();
		for(int i = 0 ; i < e ; i++)
			gets(excuses[i]);
		memset(cnt,0,sizeof(cnt));
		for(int i = 0 ; i < e ; i++)
		{
			strcpy(exe,excuses[i]);
			int len = strlen(exe);
			char tmp[75];
			int kg = 0 ;
			for(int j = 0 ; j < len ; j++)
			{
				if(exe[j] <= 'z' && exe[j] >= 'a')
					tmp[kg++] = exe[j];
				else if(exe[j] <= 'Z' && exe[j] >= 'A')
					tmp[kg++] = exe[j]+32;
				else
				{
					tmp[kg] = '\0';
					if (kg != 0)
						cnt[i] += find(tmp);
					if (cnt[i] > max)
						max = cnt[i];
					kg = 0;   //拆分每一个借口的单词
				}
			}
		}
		printf("Excuse Set #%d\n",cas++);
		for(int i = 0 ; i < e ; i++)
		{
			if(cnt[i] == max )
				printf("%s\n",excuses[i]);
		}
		printf("\n");
	}
	return 0;
}
