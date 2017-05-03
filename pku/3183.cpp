#include <cstdio>
#include <set>
using namespace std;
int main() {
	int N; scanf("%d",&N);
	int H[N];
	for (int i=0; i<N; i++) scanf("%d",&H[i]);
	set<int> ans;
	if (N==1) {
		printf("1\n");
		return 0;
	}
	if (H[0]>=H[1]) ans.insert(1);
	if (H[N-1]>=H[N-2]) ans.insert(N);
	for (int i=1; i<N-1; i++) {
		if (H[i-1]<=H[i]&&H[i]>=H[i+1]) ans.insert(i+1);
	}
	for (set<int>::iterator it=ans.begin(); it!=ans.end(); it++) {
		printf("%d\n", (*it));
	}
}