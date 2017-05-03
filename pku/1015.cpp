// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int main() {
	// int n, m;
	// int cnt = 1;
	// while (scanf("%d%d", &n, &m)) {
		// if (n == 0 && m == 0) break;
		// int d[n], p[n];
		// int sum, diff, s = 1, e = m;
		// for (int i=0; i<n; i++) scanf("%d%d", &d[i], &p[i]);
		// int dsum = 0, psum = 0, rd, rp;
		// for (int i=0; i<m; i++) {
			// dsum += d[i];
			// psum += p[i];
		// }
		// sum = dsum + psum;
		// diff = abs(dsum - psum);
		// rd = dsum; rp = psum;
		// for (int i=1; i<n-m+1; i++) {
			// dsum = dsum - d[i-1] + d[i];
			// psum = psum - p[i-1] + p[i];
			// if (diff > abs(dsum - psum)) {
				// sum = dsum + psum;
				// diff = abs(dsum - psum);
				// s = i + 1; e = i + m;
				// rd = dsum; rp = psum;
			// } else if (diff == abs(dsum - psum) &&
							// sum < dsum + psum) {
				// sum = dsum + psum;
				// diff = abs(dsum - psum);
				// s = i + 1; e = i + m;
				// rd = dsum; rp = psum;
			// }
		// }
		// printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",
			// cnt++, rp, rd);
		// for (int i=s; i<=e; i++) {
			// printf(" %d", i);
		// }
		// printf("\n\n");
	// }
// }
Jは部分数列
Jの要素数がm
diffが最小で、最小値が複数ある場合sumが最大になるように