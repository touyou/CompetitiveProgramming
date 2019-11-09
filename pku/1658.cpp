#include <cstdio>
int main() {
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++) {
		int stat[4];
		for (int j=0; j<4; j++) scanf("%d", &stat[j]);
		int res;
		if (stat[3]-stat[2]==stat[2]-stat[1]&&
				stat[2]-stat[1]==stat[1]-stat[0]) {
			res = stat[3] + (stat[3]-stat[2]);
		} else {
			res = stat[3] * (stat[3] / stat[2]);
		}
		for (int j=0; j<4; j++) printf("%d ", stat[j]);
		printf("%d\n", res);
	}
}
