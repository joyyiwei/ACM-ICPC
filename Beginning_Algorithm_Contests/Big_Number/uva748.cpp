#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int m,i,j,temp,top,t,len;
	char st[90];
	while(scanf("%s%d",st,&m) != EOF)
	{
		long long factor[100] = {0},num[5000],flag = 0 ;
		i = j = temp = top = t = len = 0 ;
		len = strlen(st);
		i = 0 ;
		while (st[i] == '0' && i < len )   // 去除前缀多余的零
			i++;
		for(j = 0 ; i < len ; i++)
		{
			if(st[i] != '.')
				factor[j++] = st[i] - '0' ;
			else t = len - i - 1;           //确定小数点位置
		}
		t *= m ;
		flag = 0 ;
		temp = 1 ;
		for(i = j - 1 ; i >= 0 ; i--)
		{
			flag += temp * factor[i];
			temp *= 10;
		}
		temp = top = j;
		for(i = 0 ; i < j ; i++)
			num[i] = factor[j-1-i];      //逆序
		m--;
		while(m--)
		{
			for(i = 0 ; i < top ; i++)
				num[i] *= flag ;     //每一位都与本身相乘
			i = 0 ;
			while(1)                 
			{
				if ((num[i] == 0) && (i > top))
					break;
				num[i+1] += num[i] / 10 ;
				num[i] %= 10 ;
				i++;
			}
			top = i ;        //我们每次都记下最大值
		}
		t--;             // 因为num[]从下标0开始
		if(top <= t)        //如果小数点的位数大于数字个数
		{
			i = 0 ;
			while(num[i] == 0)
				i++;
			printf(".");
			while(t >= i && t >= 0)
				printf("%lld",num[t--]);

		}
		else 
		{
			top--;
			i = 0;
			while(num[i] == 0)
				i++;
			while(top >= i && top>= 0)
			{
				printf("%lld",num[top--]);
				if(top == t)
					printf(".");
			}
		}
		printf("\n");
		getchar();
	}
	return 0;
}
