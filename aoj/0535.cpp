#include <cstdio>
#include <algorithm>
using namespace std;
int m, n;
int maps[92][92];
int res;
void dfs(int x, int y, int r) {
	int dx[] = {-1,0,0,1};
	int dy[] = {0,-1,1,0};
	maps[x][y]=0;
	for (int i=0; i<4; i++) {
		int nx=x+dx[i],ny=y+dy[i];
		if (maps[nx][ny]) {
			dfs(nx,ny,r+1);
		}
	}
	res=max(r,res);
	maps[x][y]=1;
}
int main() {
	while (scanf("%d%d",&m,&n)) {
		if (m==0&&n==0) break;
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
			scanf("%d",&maps[i][j]);
		res = 0;
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
			if (maps[i][j]) {
				dfs(i,j,0);
			}
		}
		printf("%d\n",res+1);
	}
}
