#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

int main() {
	int T; cin >> T;
	for (int i=1; i<=T; i++) {
		int C,D,N;
		string c,d,n,tp;
		char tmp;
		string key[2];
		vector<char> list;
		cin >> C;
		if (C==1) {
			cin >> c;
			tp = c.substr(0,2);
			key[0] = tp;
			reverse(tp.begin(), tp.end());
			key[1] = tp;
		}
		cin >> D;
		if (D==1) cin >> d;
		cin >> N >> n;
		for (int j=0; j<N; j++) {
			if (tmp==d[1]&&n[j]==d[0]) {
				list.clear();
				tmp = '*';
			} else if (tmp==d[0]&&n[j]==d[1]) {
				list.clear();
				tmp = '*';
			} else if (j+1<=N&&(n.substr(j,2)==key[0]||n.substr(j,2)==key[1])) {
				list.push_back(c[2]);
				j++;
			} else if (n[j]==d[0]) {
				tmp=d[0];
				list.push_back(n[j]);
			} else if (n[j]==d[1]) {
				tmp=d[1];
				list.push_back(n[j]);
			} else {
				list.push_back(n[j]);
			}
		}
		cout << "Case #" << i << ": [";
		for (int j=0; j<list.size(); j++) {
			if (j!=0) cout << ", ";
			cout << list[j];
		}
		cout << "]" << endl;
	}
}
