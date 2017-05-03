#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	pair<int,int> num[100];
	for (int i=0; i<100; i++) {
		num[i].first = 0;
		num[i].second = i+1;
	}
	int n;
	while (cin >> n) {
		num[n-1].first++;
	}
	sort(num, num+100);
	reverse(num, num+100);
	int max=num[0].first;
	vector<int> maxs;
	maxs.push_back(num[0].second);
	for (int i=1; i<100; i++) {
		if (max==num[i].first) {
			maxs.push_back(num[i].second);
		} else {
			break;
		}
	}
	sort(maxs.begin(), maxs.end());
	for (int i=0; i<maxs.size(); i++) {
		cout << maxs[i] << endl;
	}
}
