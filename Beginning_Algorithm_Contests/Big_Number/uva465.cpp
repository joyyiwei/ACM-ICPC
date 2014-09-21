#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 0x7fffffff;

int main()
{
	char str1[1000],str2[1000],ch;

	while (scanf("%s %c %s",str1,&ch,str2) != EOF )
	{
		printf("%s %c %s\n",str1,ch,str2);

		double a,b;
		sscanf(str1,"%lf",&a);
		sscanf(str2,"%lf",&b);

		if (a > MAXN)  
			printf("first number too big\n");  
		if (b > MAXN)  
			printf("second number too big\n");  
		if ('+'==ch && a+b>MAXN)  
			printf("result too big\n");  
		if ('*'==ch && a*b>MAXN)  
			printf("result too big\n");  
	}
	return 0;
}
