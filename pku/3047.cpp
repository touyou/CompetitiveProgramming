#include <cstdio>

typedef long long ll;
int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const char* day[] = {"monday","tuesday","wednesday",
"thursday","friday","saturday","sunday"};

bool isleap(int y) {
	if (y % 400 == 0) return true;
	else if (y % 100 == 0) return false;
	else if (y % 4 == 0) return true;
	else return false;
}

int main() {
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	int normal = 0, leap;
	for (int i=0; i<12; i++) normal += mon[i];
	leap = normal + 1;
	int cnt = 0;
	for (int i=1800; i<y; i++) if (isleap(i)) cnt++;
	ll dist = cnt*leap+(y-1800-cnt)*normal;
	for (int i=0; i<m-1; i++) {
		if (i == 1&&isleap(y)) {
			dist += mon[i] + 1;
		} else {
			dist += mon[i];
		}
	}
	dist += d;
	int res = (1 + dist % 7) % 7;
	printf("%s\n", day[res]);
}