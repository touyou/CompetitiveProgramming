// #include <cstdio>
// #include <cmath>
// typedef long long ll;
// int main() {
	// int t; scanf("%d", &t);
	// int dp[31269]; dp[0] = 0;
	// for (int i=1; i<31269; i++) {
		// dp[i] = dp[i-1] + (int)log10((double)i) + 1;
	// }
	// for (int ix=0; ix<t; ix++) {
		// ll sum = 0;
		// int num, i; scanf("%d", &num);
		// for (i=1; sum < num; i++) sum += dp[i];
		// int cnt = num - (sum - dp[--i]);
		// if (cnt < 10) {
			// printf("%d\n", cnt);
		// } else {
			// sum = 9;
			// int j;
			// for (j=1; j<=4; j++) {
				// sum += 9 * pow(10, j);
				// if (sum >= cnt) break;
			// }
			// if (sum == cnt) {
				// printf("9\n");
			// } else {
				// sum -= 9 * pow(10, j);
				// cnt -= sum;
				// if (cnt % j == 0) {
					// int res = pow(10, j-1) + cnt / j;
					// char ans[j];
					// sprintf(ans, "%d", &res);
					// printf("%d\n", ans[j-1]-'0');
				// } else {
					// int res = pow(10, j-1) + cnt / j + 1;
					// char ans[j];
					// sprintf(ans, "%d", &res);
					// printf("%d\n", ans[cnt%j-1]-'0');
				// }
			// }
		// }		
	// }
// }