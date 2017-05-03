#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> gava(n);
	for (int i=0; i<n; i++) scanf("%d", &gava[i]);
	sort(gava.begin(), gava.end());
	for (int i=0; i<n-1; i++) {
		int temp = gava[i] * 2;
		bool flag=true;
		for (int j=i+1; j<n; j++) {
			if (gava[j] == temp) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}
