#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int map[N][N];
    for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d",&map[i][j]);
	int dp[N][N][N];
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int sum = 0;
			for (int k=j; k<N; k++) {
				sum += map[i][k];
				dp[i][j][k] = sum;
			}
		}
	}
	int res = INT_MIN;
	for (int k=0; k<N; k++) {
		for (int l=k; l<N; l++) {
			for (int i=0; i<N; i++) {
				int sum = 0;
				for (int j=i; j<N; j++) {
					sum += dp[j][k][l];
					res = max(res, sum);
				}
			}
		}
	}
	printf("%d\n", res);
}
