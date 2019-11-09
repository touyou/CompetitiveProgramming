#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	vector<int> res;
	bool flag[k];
	fill(flag, flag+k, true);
	int npos = 0;
	for (int i=1; i<=k; i++) {
		if (i % n == 0) res.push_back(npos+1);
		if (i == k) break;
		flag[npos]=false;
		int cnt = 0;
		while (cnt <= p) {
			npos++;
			if (npos>=k) npos-=k;
			if (flag[npos]) cnt++;
		}
	}
	sort(res.begin(), res.end());
	for (int i=0; i<res.size(); i++) printf("%d\n",res[i]);
}

/*
1 4 7
2 5 3
9 6 8
*/