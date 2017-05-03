#include <cstdio>
#include <algorithm>
using namespace std;
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int map[100][100];
int n,m,k;
int dfs(int x, int y, int sz) {
	map[x][y]=0;
	sz++;
	int res=0;
	for (int i=0; i<4; i++) {
		int nx=x+d[i][0], ny=y+d[i][1];
		if (nx>=0&&nx<n&&ny>=0&&ny<m&&map[nx][ny]) {
			sz = dfs(nx,ny,sz);
		}
	}
	return sz;
}
int main() {
	int r,c,i,j;
	scanf("%d%d%d",&n,&m,&k);
	for (i=0; i<n; i++) for (j=0; j<m; j++) map[i][j] = 0;
	for (i=0; i<k; i++) {
		scanf("%d%d",&r,&c);
		map[r-1][c-1] = 1;
	}
	int res=0;
	for (i=0; i<n; i++) for (j=0; j<m; j++) {
		if (map[i][j]) {
			res = max(dfs(i,j,0), res);
		}
	}
	printf("%d\n",res);
}