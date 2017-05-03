#include <cstdio>
#include <climits>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> P;
int max(int a, int b) { return a < b ? b : a; }
int mp[100][100], used[100][100];
int dx[4][6] = {{0,-1,0,1,1,1},  // 奇数行目 x
				{-1,0,1,1,0,-1}, // 奇数行目 y
				{-1,-1,-1,0,1,0},// 偶数行目 x
				{-1,0,1,1,0,-1}};
int m, n, s, t;
int main() {
  while (scanf("%d",&m)) {
	if (!m) break;
	scanf("%d%d",&n,&s);
	for (int i=1; i<=s; i++) {
	  int x, y; scanf("%d%d",&x,&y); x--; y--;
	  mp[x][y]=i;
	}
	int res = INT_MAX;
	scanf("%d",&t);
	for (int i=0; i<t; i++) {
	  int x, y; scanf("%d%d",&x,&y); x--; y--;
	  int temp = 1;
	  memset(used, 0, sizeof(used));
	  used[x][y]=1;
	  queue<pair<P, int> > que;
	  que.push_back(make_pair(P(x,y), 0));
