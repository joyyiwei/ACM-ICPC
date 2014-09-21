#include <iostream>  
#include <cstring>  
#include <algorithm>  
#include <cstdio>  
using namespace std;  

int f[11] = {0,0,64,32,16,8,0,4,2,1,0};    

int main() {  
	char str[12];  
	gets(str);  
	while (gets(str) && str[0] != '_') {  
		int ans = 0;  
		for (int i = 2; i < 10; i++)  
			if (str[i] == 'o')  
				ans += f[i];  
		printf("%c", ans);  
	}  
	return 0;  
}  
