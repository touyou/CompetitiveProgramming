#include <cstdio>
int main() {
	int n, k; scanf("%d%d",&n,&k);
	bool flag[n][n];
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) flag[i][j]=false; 
	for (int i=0; i<k; i++) {
		int a, b; scanf("%d%d",&a,&b);
		flag[a-1][b-1]=true;
	}
	int res = 0;
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) if (flag[i][j]&&flag[j][i]) res++;
	printf("%d\n", res);
}