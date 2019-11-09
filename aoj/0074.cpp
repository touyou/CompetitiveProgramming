#include <cstdio>

int main() {
	int res;
	int h, m, s;
	while (scanf("%d%d%d", &h, &m, &s)) {
		res = 120;
		if (h==-1&&m==-1&&s==-1) break;
		m += h * 60;
		res -= m;
		if (s != 0) {
			res--;
			s = 60 - s;
		}
		h = (int)(res / 60);
		m = res - h * 60;
//		printf("%d\n",res);
		printf("%02d:%02d:%02d\n", h, m, s);
		res *= 3;
		s *= 3;
		res += s / 60;
		s -= s / 60 * 60;
		h = (int)(res / 60);
		m = res - h * 60;
		printf("%02d:%02d:%02d\n", h, m, s);
	}
}
