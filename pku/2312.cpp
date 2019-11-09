#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int, int> P;
const int MA = 100000;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int sy, sx, gy, gx;
vs map;
vii d;
int dfs() {
	queue<P> que;
	que.push(P(sy, sx));
	int N=map[0].length(), M=map.size();
	for (int i=0; i<M; i++) for (int j=0; j<N; j++) d[i][j]=MA;
	d[sy][sx] = 0;
	while (que.size()) {
		P p = que.front();
		que.pop();
		if (p.first==gy && p.second==gx) break;
		for (int i=0; i<4; i++) {
			int ny=p.first+dy[i];
			int	nx=p.second+dx[i];
			if (0<=nx&&nx<N&&0<=ny&&ny<M) {
				if ((map[ny][nx]=='E'||map[ny][nx]=='T')&&
						d[ny][nx]>d[p.first][p.second]+1) {
					que.push(P(ny, nx));
					d[ny][nx]=d[p.first][p.second]+1;
				} else if (map[ny][nx]=='B'&&
						d[ny][nx]>d[p.first][p.second]+2) {
					que.push(P(ny, nx));
					d[ny][nx]=d[p.first][p.second]+2;
				}
			}
		}
	}
	return d[gy][gx];
}

int main() {
	int M, N;
	while (cin>>M>>N) {
		if (M==0&&N==0) break;
		map = vs(M);
		for (int i=0; i<M; i++) cin>>map[i];
		int i, j;
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) { 
				if (map[i][j]=='Y') {
					sx = j;
					sy = i;
				} else if (map[i][j]=='T') {
					gx = j;
					gy = i;
				}
			}
		}
		d = vii(M,vi(N));
		cout << dfs() << endl;
	}
}
