#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};  
int dy[] = {1, -1, 1, -1, 0, 0, -1, 1};  
int n,m ;
char arr[100][100];
char brr[100];
int signx,signy;

int judge(int x ,int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m)
		return 1;
	else return 0;
}
void find(char *a)
{
	int len = strlen(a);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
		{
			for(int k = 0 ; k < 8 ; k++)
			{
				char b[100];
				b[0] = arr[i][j];
				int nx = i + dx[k];
				int ny = j + dy[k];
				int cur = 1;
				while(judge(nx,ny))
				{
					b[cur++] = arr[nx][ny];
					nx +=dx[k];
					ny +=dy[k];
					if(cur == len)
						break;
				}
				b[cur] = '\0';
				if(strcmp(a,b) == 0 )
				{
					signx = i+1;
					signy = j+1;
					return ;
				}
			}
		}
	return;
}

int main() {
	int t, flag = 0;
	scanf("%d",&t);
	while(t--) {
		if (!flag)
			flag = 1;
		else printf("\n");
		cin>>n>>m;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
			{
				cin>>arr[i][j];
				arr[i][j] = tolower(arr[i][j]);
			}
		int k;
		cin>>k;
		while(k--) {
			cin>>brr;
			int len = strlen(brr);
			for(int i = 0 ; i < len ; i++)
				brr[i] = tolower(brr[i]);
			signx = signy = 0 ;
			find(brr);
			cout<<signx<<" "<<signy<<endl;
		}
	}
	return 0;
}
