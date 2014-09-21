#include<stdio.h>  
#include<string.h>  

double sum(char *str)  
{  
	double s=0;  
	int leap,i,n;  
	n=strlen(str);  
	leap=1;  
	for(i=0;i<n;i++)  
	{  
		if(str[i]>='0'&&str[i]<='9')  
		{  
			s=s*10+str[i]-'0';  
		}  
		else  
		{  
			for(i=i+1;i<n;i++)  
			{  
				s=s*10+str[i]-'0';  
				leap=leap*10;  
			}  
		}  
	}  
	return s/leap;  
}

void pan(char *str)  
{  
	double shu[100];  
	char s[100];  
	int i,n,leap,j;  
	int con;  
	n=strlen(str);  
	memset(shu,0,sizeof(shu));  
	for(i=0;i<n;i++)  
	{  
		if(str[i]=='=')  
		{  
			con=str[i-1];  
			for(j=i+1;j<n;j++)  
			{  
				if(str[j]!='.'&&(str[j]<'0'||str[j]>'9'))  
				{  
					s[j-i-1]='\0';  
					break;  
				}  
				s[j-i-1]=str[j];  
			}  
			i=j;  
			shu[con]=1.0*sum(s);  
			if(str[i]=='m')  
				shu[con]*=0.001;  
			if(str[i]=='k')  
				shu[con]*=1000;  
			if(str[i]=='M')  
				shu[con]*=1000000;  
		}  
	}  
	if(shu['P']==0)  
		printf("P=%.2lfW\n",1.0*shu['U']*shu['I']);  
	if(shu['U']==0)  
		printf("U=%.2lfV\n",1.0*shu['P']/shu['I']);  
	if(shu['I']==0)  
		printf("I=%.2lfA\n",1.0*shu['P']/shu['U']);  
}

int main()  
{  

	int n,i;  
	char str[1000];  
	scanf("%d%*c",&n);  
	for(i=0;i<n;i++)  
	{  
		gets(str);  
		printf("Problem #%d\n",i+1);  
		pan(str);  
		printf("\n");  
	}  
	return 0;  
}  
