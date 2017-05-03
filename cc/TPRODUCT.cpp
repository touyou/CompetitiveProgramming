#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

#define MOD 1000000007
#define INF 1000000000

using namespace std;

int main() {
	int H, len, all, i;
	while (scanf("%d", &H)) {
		if (H==0) break;
		if (H>15) H=15;
		all = pow(2, H)-1;
		long long V[all], P[all];
		for (i=0; i<all; i++) {
			cin >> V[i];
			if (V[i] > INF) V[i] = INF;
		}
		for (i=all-1; i>=0; i--) {
			if (i*2+1>=all||i*2+2>=all) {
				P[i] = V[i];
			} else {
				P[i] = V[i]*max(P[i*2+2], P[i*2+1]);
			}
		}
		P[0] %= MOD;
		printf("%lld\n" ,P[0]);
	}
	return 0;
}
