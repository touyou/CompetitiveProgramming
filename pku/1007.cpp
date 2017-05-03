#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<string> input(m);
	for (int i=0; i<m; i++) cin >> input[i];
	pair<int, string> pis[m],spis[m];
	for (int i=0; i<m; i++) {
		pis[i].first=0;
		spis[i].second=pis[i].second=input[i];
		for (int j=0; j<n-1; j++) {
			for (int k=j+1; k<n; k++) {
				if (input[i][j]>input[i][k]) pis[i].first++;
			}
		}
		spis[i].first=pis[i].first;
	}
	sort(spis, spis+m);
	for (int i=0; i<m; i++) {
		cout << spis[i].second << endl;
	}
}
