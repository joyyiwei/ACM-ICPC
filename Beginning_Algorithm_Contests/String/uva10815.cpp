#include <iostream>  
#include <algorithm>  
#include <cstdio>  
#include <cstring>  
using namespace std;  

bool isLetter(char &ch) {  
	if (ch >= 'a' && ch <= 'z')  
		return true;  
	if (ch >= 'A' && ch <= 'Z') {  
		ch += 'a' - 'A';  
		return true;  
	}  
	return false ;  
}  

int cmp(const void* _a,const void *_b) {  
	char *a = (char*)_a;  
	char *b = (char*)_b;  
	return strcmp(a,b);  
}  

char b[50005][205];  

int main() {  
	char tmp;  
	bool flag = false;  
	int i = 0 , j = 0 ;  
	while ((tmp = getchar()) != EOF) {  
		if (isLetter(tmp) && !flag) {  
			i = 0 ;  
			b[j][i++] = tmp ;  
			flag = true;  
		}  
		else if (isLetter(tmp) && flag)  
			b[j][i++] = tmp ;  
		else if (!isLetter(tmp) && flag) {  
			flag = false;  
			b[j][i] = '\0';  
			j++;  
		}  
	}  
	qsort(b,j,sizeof(b[0]),cmp);  
	for(i = 0 ; i < j ; i++) {  
		if(strcmp(b[i],b[i+1]) == 0)  
			continue;  
		printf("%s\n",b[i]);  
	}  
	return 0 ;  
}  
