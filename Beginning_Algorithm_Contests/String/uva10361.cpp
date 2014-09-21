#include <stdio.h>  
#include <string.h>  
#define MAXN 110  
void getss(char s[]);  
int main()  
{  
    int n;  
    char s1[MAXN],s2[MAXN],s3[MAXN],s4[MAXN],s5[MAXN],c,line[MAXN];  
    scanf("%d",&n);  
    c = getchar();  
    while(n--)  
    {         
        getss(s1);  
        getss(s2);  
        getss(s3);  
        getss(s4);  
        getss(s5);  
        gets(line);  
        line[strlen(line) - 3] = '\0';  
        printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);  
        printf("%s%s%s%s%s\n",line,s4,s3,s2,s5);  
    }  
    return 0;  
}  
  
void getss(char s[])  
{  
    int i;  
    for(i=0; i<MAXN; i++)  
    {  
        if((s[i] = getchar()) == '<' || s[i] == '>' || s[i] == '\n'){  
            s[i] = '\0';  
            break;  
        }  
    }     
}
