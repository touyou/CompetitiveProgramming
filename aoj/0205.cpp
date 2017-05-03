#include <cstdio>

int main() {
	int te[5];
	while (scanf("%d", &te[0])!=EOF) {
		if (te[0] == 0) break;
		for (int i=1; i<5; i++) scanf("%d", &te[i]);
		int num[3];
		for (int i=0; i<3; i++) num[i] = 0;
		for (int i=0; i<5; i++) num[te[i]-1]++;
		if (num[0]!=0&&num[1]!=0&&num[2]!=0) {
			for (int i=0; i<5; i++) printf("3\n");
			continue;
		} else if ((num[0]==0&&num[1]==0)||
			(num[1]==0&&num[2]==0)||(num[0]==0&&num[2]==0)) {
			for (int i=0; i<5; i++) printf("3\n");
			continue;
		}
		if (num[0] == 0) {
			for (int i=0; i<5; i++) {
				if (te[i] == 2) {
					printf("1\n");
				} else if (te[i] == 3) {
					printf("2\n");
				}
			}
		} else if (num[1] == 0) {
			for (int i=0; i<5; i++) {
				if (te[i] == 3) {
					printf("1\n");
				} else if (te[i] == 1) {
					printf("2\n");
				}
			}
		} else if (num[2] == 0) {
			for (int i=0; i<5; i++) {
				if (te[i] == 1) {
					printf("1\n");
				} else if (te[i] == 2) {
					printf("2\n");
				}
			}
		}
	}
}
