#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct cood {
	int x, y;
};
int main() {
	int n; scanf("%d",&n);
	cood cows[n];
	for (int i=0; i<n; i++) scanf("%d%d",&cows[i].x,&cows[i].y);
	vector<pair<int,pair<int, int> > > res;
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) for (int k=j+1; k<n; k++) {
		double px=cows[k].x-cows[i].x, qx=cows[j].x-cows[i].x;
		double py=cows[k].y-cows[i].y, qy=cows[j].y-cows[i].y;
		if (px*qy==qx*py) {
				res.push_back(make_pair(i+1,make_pair(j+1,k+1)));
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n",res.size());
	for (int i=0; i<res.size(); i++) {
		printf("%d %d %d\n",res[i].first,res[i].second.first,res[i].second.second);
	}
}