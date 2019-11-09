#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<string> map(100);
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y) {
	map[x][y] = '*';
	for (int i=0; i<8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny]=='@') {
			dfs(nx, ny);
		}
	}
	return;
}

int main() {
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		for (int i=0; i<n; i++) {
			cin >> map[i];
		}
		int res = 0;
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
			if (map[i][j] == '@') {
				dfs(i, j);
				res++;
			}
		}
		printf("%d\n", res);
	}
}