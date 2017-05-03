#include <cstdio>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int alen;
	while (scanf("%d",&alen)) {
		if (alen == 0) break;
		int a[alen];
		for (int i=0; i<alen; i++) scanf("%d",&a[i]);
		sort(a,a+alen);
		map<int, int> cnt;
		for (int i=0; i<alen; i++) {
			if (cnt.count(a[i])==0) {
				cnt[a[i]]=1;
			} else {
				cnt[a[i]]++;
			}
		}
		int res = INT_MAX;
		for (map<int, int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) {
			if ((*it).second > alen/2) {
				res = (*it).first;
			}
		}
		if (res == INT_MAX) {
			printf("NO COLOR\n");
		} else {
			printf("%d\n",res);
		}
	}
}