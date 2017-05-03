#include <cstdio>
struct pos { int x, y; };
int main() {
	int n;
	while (scanf("%d",&n)&&n!=0) {
		int map[n][n];
		for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = -1;
		pos p; p.y = n/2; p.x = n/2+1;
		for (int i=1; i<=n*n; i++) {
			while (map[p.x][p.y] != -1) {
				p.x++; p.y--;
				if (p.x>=n) p.x = 0;
				else if (p.x<0) p.x = n-1;
				if (p.y>=n) p.y = 0;
				else if (p.y<0) p.y = n-1;
			}
			map[p.x][p.y] = i;
			p.x++; p.y++;
			if (p.x>=n) p.x = 0;
			else if (p.x<0) p.x = n-1;
			if (p.y>=n) p.y = 0;
			else if (p.y<0) p.y = n-1;
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				printf("%4d", map[i][j]);
			}
			printf("\n");
		}
	}
}