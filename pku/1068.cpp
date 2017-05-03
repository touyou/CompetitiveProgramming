#include <iostream>
#include <algorithm>
#include <vector>
#define ALL(a) (a).begin(), (a).end()
typedef vector<char> vc;
typedef vector<int> vi;
using namespace std;

int main() {
	int t; cin >> t;
	for (int ix=0; ix<t; ix++) {
		int n; cin >> n;
		vc S;
		int old = 0;
		for (int i=0; i<n; i++) {
			int num; cin >> num;
			num-=old;
			for (int j=0; j<num; j++) S.push_back('(');
			S.push_back(')');
			old = num;
		}
		// Sは括弧を示している⇒どうやってW-Sequenceにするか？
		// ')'の時に探索する？
		vi ans(n);
		for (int i=0; i<S.size(); i++) {
			if (S[i]=='(') {
				;
			}
		}
	}
	return 0;
}
