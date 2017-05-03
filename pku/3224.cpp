#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n,in; scanf("%d",&n);
	vector<int> play(n,0);
	int max=0, res=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			scanf("%d",&in);
			if (in==3) play[i]++;
		}
		if (max<play[i]) {
			max=play[i];
			res=i+1;
		}
	}
	printf("%d\n",res);
}
