#include <cstdio>

using namespace std;

int main() {
	/*
	int p[10][10];
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			p[i][j] = 0;
		}
	}
	int x,y,size;
	int dx[] = { 0, 0,-1, 1,-1,-1, 1, 1, 0, 0,-2, 2};
	int dy[] = {-1, 1, 0, 0,-1, 1,-1, 1,-2, 2, 0, 0};
	while (scanf("%d,%d,%d", &x, &y, &size)!=EOF) {
		p[x][y]++;
		for (int i=0; i<size*4; i++) {
			int mx=x+dx[i];
			int my=x+dy[i];
			if (mx>=0&&mx<10&&my>=0&&my<10) {
				p[mx][my]++;
			}
		}
	}
	int c=0,m=0;
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (p[i][j] == 0) {
				c++;
			} else if (p[i][j]>m) {
				m=p[i][j];
			}
		}
	}
	printf("%d\n%d\n",c,m);
	return 0;
	*/
		int map[10][10],ink,x,y,max=0,count=0;
	int dx[] = { 0, 0,-1, 1,-1,-1, 1, 1, 0, 0,-2, 2};
	int dy[] = {-1, 1, 0, 0,-1, 1,-1, 1,-2, 2, 0, 0};

	for(int i=0 ; i<10 ; i++){
		for(int j=0 ; j<10 ; j++){
			map[i][j] = 0;
		}
	}
	while( scanf("%d,%d,%d", &x, &y, &ink) != EOF ){
		map[y][x]++;
		for(int i=0 ; i<ink*4 ; i++){
			int mx = x + dx[i];
			int my = y + dy[i];
			if(mx>=0 && mx<10 && my>=0 && my<10){
				map[my][mx]++;
			}
		}
	}
	for(int y=0 ; y<10 ; y++){
		for(int x=0 ; x<10 ; x++){
			if(map[y][x]==0){
				count++;
			}
			if(map[y][x]>max){
				max = map[y][x];
			}
		}
	}
	printf("%d\n%d\n", count , max);
}
