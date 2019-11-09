#include <cstdio>
#include <cstring>

int board[100][100];

void fill(int x, int y, int L, int c) {
	for (int i=y; i<y+L; i++) for (int j=x; j<x+L; j++) board[i][j] = c;
}

int main() {
	for (int i=0; i<100; i++) for (int j=0; j<100; j++) board[i][j] = 0;
	int t,x,y,L; scanf("%d",&t);
	char com[32];
	for (int ix=0; ix<t; ix++) {
		scanf("%s%d%d%d",com,&x,&y,&L);
		x--; y--;
		if (strcmp(com,"WHITE")==0) {
			fill(x,y,L,0);
		} else if (strcmp(com,"BLACK")==0) {
			fill(x,y,L,1);
		} else {
			int res = 0;
			for (int i=y; i<y+L; i++) for (int j=x; j<x+L; j++)
				if (board[i][j] == 1) res++;
			printf("%d\n",res);
		}
	}
}