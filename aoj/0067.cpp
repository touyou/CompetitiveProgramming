#include <iostream>
#include <vector>
using namespace std;
typedef vector<string> vs;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

vs dfs(vs map, int nx, int ny) {
	map[nx][ny] = '0';
	for (int i=0; i<4; i++) {
		if (nx+dx[i]>=0&&nx+dx[i]<12&&
				ny+dy[i]>=0&&ny+dy[i]<12&&map[nx+dx[i]][ny+dy[i]]=='1') {
			map = dfs(map, nx+dx[i], ny+dy[i]);
		}
	}
	return map;
}

int main() {
	vs map;
	string buff;
	while (cin >> buff) {
		map.push_back(buff);
		for (int i=0; i<11; i++) {
			cin >> buff;
			map.push_back(buff);
		}
		int res = 0;
		for (int i=0; i<12; i++) {
			for (int j=0; j<12; j++) {
				if (map[i][j] == '1') {
					res++;
					map = dfs(map, i, j);
				}
			}
		}
		cout << res << endl;
		map.clear();
	}
}
