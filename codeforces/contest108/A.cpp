#include <cstdio>

int main() {
	int HH, MM;
	scanf("%d:%d", &HH, &MM);
	int rev = int(HH/10) + (HH%10)*10;
	if (5 < HH && HH < 10) {
		HH = 10;
	} else if (15 < HH && HH < 20) {
		HH = 20;
	} else if (rev > MM) {
		printf("%02d:%02d\n", HH, rev);
		return 0;
	} else {
		HH++;
	}
	if (5 < HH && HH < 10) HH = 10;
	if (15 < HH && HH < 20) HH = 20;
	if (HH == 24) HH = 0;
	rev = HH/10 + (HH%10)*10;
	printf("%02d:%02d\n", HH, rev);
}
