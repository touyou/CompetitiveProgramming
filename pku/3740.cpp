#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	while (scanf("%d%d", &m, &n)!=EOF) {
		int map[m][n];
		int res[m];
		fill(res, res+n, 0);
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				scanf("%d", &map[i][j]);
				res[i] += map[i][j];
			}
		}
		bool flag = false;
		
		if (flag) printf("Yes, I found it\n");
		else printf("It is impossible\n");
	}
}