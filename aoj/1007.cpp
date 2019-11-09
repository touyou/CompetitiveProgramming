#include <cstdio>
int main() {
	for (int ix=1;;ix++) {
		int n; scanf("%d",&n);
		if (n==0) break;
		printf("Case %d:\n",ix);
		int f[n][n];
		int nx=0,ny=0;
		if (n%2==0) {
			for (int i=1; i<=n*n; i++) {
				f[nx][ny]=i;
				if (nx==n-1&&ny%2==0) ny++;
				else if (nx==n-1) {
					nx--;
					ny++;
				}
				else if (ny==n-1&&nx%2!=0) nx++;
				else if (ny==n-1) {
					nx++;
					ny--;
				}
				else if (nx==0&&ny%2==0) ny++;
				else if (nx==0) {
					nx++;
					ny--;
				}
				else if (ny==0&&nx%2!=0) nx++;
				else if (ny==0) {
					nx--;
					ny++;
				} 
				else if ((nx+ny)%2==0) {
					nx--;
					ny++;
				}
				else {
					nx++;
					ny--;
				}
			}
		} else {
			for (int i=1; i<=n*n; i++) {
				f[nx][ny]=i;
				if (nx==n-1&&ny%2!=0) ny++;
				else if (nx==n-1) {
					nx--;
					ny++;
				}
				else if (ny==n-1&&nx%2==0) nx++;
				else if (ny==n-1) {
					nx++;
					ny--;
				}
				else if (nx==0&&ny%2==0) ny++;
				else if (nx==0) {
					nx++;
					ny--;
				}
				else if (ny==0&&nx%2!=0) nx++;
				else if (ny==0) {
					nx--;
					ny++;
				} 
				else if ((nx+ny)%2==0) {
					nx--;
					ny++;
				}
				else {
					nx++;
					ny--;
				}
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				printf("%3d",f[i][j]);
			}
			printf("\n");
		}
	}
}