#include <iostream>
#include <vector>
using namespace std;
typedef vector<string> vs;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int H, W;
vs dfs(vs map, int ny, int nx, char now) {
	map[ny][nx] = '-';
	for (int i=0; i<4; i++) {
		if (ny+dy[i]>=0&&ny+dy[i]<H&&
		nx+dx[i]>=0&&nx+dx[i]<W&&map[ny+dy[i]][nx+dx[i]]==now) {
			map = dfs(map, ny+dy[i], nx+dx[i], now);
		}
	}
	return map;
}
int main() {
	while (cin>>H>>W) {
		if (H==0&&W==0) break;
		vs map(H);
		for (int i=0; i<H; i++) cin>>map[i];
		int res = 0;
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				if (map[i][j]!='-') {
					map = dfs(map, i, j, map[i][j]);
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
}
