#include <iostream>
#include <vector>
using namespace std;
typedef vector<string> vs;

int dx[] = {-3,-2,-1,0,0,0,0,0,0,1,2,3};
int dy[] = {0,0,0,-3,-2,-1,1,2,3,0,0,0};

vs dfs(vs map, int nx, int ny) {
	map[nx][ny] = '0';
	for (int i=0; i<12; i++) {
		if (nx+dx[i]>=0&&nx+dx[i]<8&&
				ny+dy[i]>=0&&ny+dy[i]<8&&
				map[nx+dx[i]][ny+dy[i]]=='1') {
			map = dfs(map, nx+dx[i], ny+dy[i]);
		}
	}
	return map;
}

int main() {
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		vs map(8);
		for (int j=0; j<8; j++) cin >> map[j];
		int x, y;
		cin >> x >> y;
		map = dfs(map, y-1, x-1);
		cout << "Data " << i+1 << ":" << endl;
		for (int j=0; j<8; j++) cout << map[j] << endl;
	}
}
