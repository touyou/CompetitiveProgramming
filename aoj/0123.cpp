#include <cstdio>
int main() {
	float fm, tm;
	while (scanf("%f%f",&fm,&tm)!=EOF) {
		if (fm<35.5&&tm<71.0) printf("AAA\n");
		else if (fm<37.5&&tm<77.0) printf("AA\n");
		else if (fm<40.0&&tm<83.0) printf("A\n");
		else if (fm<43.0&&tm<89.0) printf("B\n");
		else if (fm<50.0&&tm<105.0) printf("C\n");
		else if (fm<55.0&&tm<116.0) printf("D\n");
		else if (fm<70.0&&tm<148.0) printf("E\n");
		else printf("NA\n");
	}
}