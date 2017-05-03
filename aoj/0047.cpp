#include <cstdio>
using namespace std;
int main() {
	char from,to,ball='A';
	while (scanf("%c,%c",&from,&to)!=EOF) {
		if (ball==from) {
			ball=to;
		} else if (ball==to) {
			ball=from;
		}
	}
	printf("%c\n",ball);
}
