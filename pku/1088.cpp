#include <cstdio>
#include <algorithm>
using namespace std;

int R, C;
int map[100][100], dp[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int dfs(int x, int y, int cnt) {
	cnt++;
	int res = cnt;
	for (int i=0; i<4; i++) {
		int nx = dx[i]+x;
		int ny = dy[i]+y;
		if (nx<R&&nx>=0&&ny<C&&ny>=0&&map[nx][ny]<map[x][y]) {
			// printf("%d %d\n", map[nx][ny], map[x][y]);
			if (dp[nx][ny]!=-1) {
				res = max(res, cnt+dp[nx][ny]);
			} else {
				res = max(res, dfs(nx, ny, cnt));
			}
		}
	}
	return res;
}

int main() {
	scanf("%d%d", &R, &C);
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}
	int res = -1;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			dp[i][j] = dfs(i, j, 0);
			res = max(res, dp[i][j]);
		}
	}
	// for (int i=0; i<R; i++) {
		// for (int j=0; j<C; j++) printf("%d ", dp[i][j]);
		// printf("\n");
	// }
	printf("%d\n", res);
}