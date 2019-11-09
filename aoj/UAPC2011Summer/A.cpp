#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<int> vi;
struct ch {
	string name;
	vector<int> time;
	int pt;
	ch() { pt=0; }
};
int main() {
	int n, m, d;
	while (scanf("%d",&n)&&n!=0) {
		vi times(31, 0);
		ch names[n];
		for (int i=0; i<n; i++) {
			cin >> names[i].name;
			scanf("%d", &m);
			for (int j=0; j<m; j++) {
				int temp; scanf("%d", &temp);
				names[i].time.push_back(temp);
				times[temp]++;
			}
		}
		int res = INT_MAX;
		string rstr;
		for (int i=0; i<n; i++) {
			for (int j=0; j<names[i].time.size(); j++) {
				int pts = n;
				int cnt = times[names[i].time[j]];
				if (cnt==n) pts = 1;
				else if (cnt>1) pts -= cnt-1;
				names[i].pt += pts;
			}
			if ((names[i].pt < res)||(names[i].pt==res&&names[i].name<rstr)) {
				rstr = names[i].name;
				res = names[i].pt;
			}
		}
		cout << res << " " << rstr << endl;
	}
}