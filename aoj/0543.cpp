#include <cstdio>
using namespace std;
int main() {
	int sum;
	while (scanf("%d",&sum)&&sum!=0) {
		for (int i=0; i<9; i++) {
			int n; scanf("%d",&n);
			sum -= n;
		}
		printf("%d\n",sum);
	}
}
