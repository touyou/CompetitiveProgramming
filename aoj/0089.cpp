// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main() {
	// int map[100][100], i=0,n=0;
	// char getch;
	// while (scanf("%d%c", &map[i][n++], &getch) != EOF){
		// if (getch == '\n') {
			// i++;
			// n=0;
		// }
	// }
	// int dp[100][100];
	// for (int j=0; j<100; j++) for (int k=0; k<100; k++) dp[j][k] = 0;
	// for (int j=0; j<100; j++) {
		// for (int k=0; k<100; k++) printf("%d ", map[j][k]);
		// puts("");
	// }
	// dp[0][0] = map[0][0];
	// for (int j=1; j<i/2; j++) {
		// dp[j][0] = dp[j-1][0] + map[j][0];
		// dp[j][sizeof(map[j])-1] = dp[j-1][sizeof(map[j-1])-1] + map[j][sizeof(map[j])-1];
		// for (int k=1; k<sizeof(map[j])-1; k++) {
			// dp[j][k] = max(dp[j-1][k-1],dp[j-1][k]) + map[j][k];
		// }
	// }
	// for (int j=i/2; j<i; j++) {
		// for (int k=0; k<sizeof(map[j]); k++) {
			// dp[j][k] = max(dp[j-1][k],dp[j-1][k+1]) + map[j][k];
		// }
	// }
	printf("%d\n",dp[i-1][0]);
// }