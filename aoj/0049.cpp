#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int A=0,B=0,C=0,D=0;
	char bl[3];
	while (scanf("%*d,%2s",bl)!=EOF) {
		if (string(bl)=="A") {
				A++;
		} else if (string(bl)=="B") {
				B++;
		} else if (string(bl)=="AB") {
				C++;
		} else if (string(bl)=="O") {
				D++;
		}
	}
	printf("%d\n%d\n%d\n%d\n",A,B,C,D);
}
