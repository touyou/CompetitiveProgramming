#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;

vi C;

bool compare(vi S, vi C) {
	for (int i=0; i<S.size(); i++) {
		if (S[i] != C[i]) return false;
	}
	return true;
}

int solve(vi S, int cnt) {
	C = vi(S.size());
	map<int, int> ma;
	for (int i=0; i<S.size(); i++) {
		if (ma.empty() || ma.find(S[i])==ma.end()) {
			ma[S[i]] = 1;
		} else {
			ma[S[i]]++;
		}
	}
	for (int i=0; i<S.size(); i++) {
		C[i] = ma[S[i]];
	}
	if (compare(S, C)) {
		return cnt;
	}
	return solve(C, cnt+1);
}

int main() {
	int n;
	while (scanf("%d",&n)&&n!=0) {
		vi S(n);
		for (int i=0; i<n; i++) scanf("%d",&S[i]);
		int res = solve(S, 0);
		printf("%d\n", res);
		for (int i=0; i<C.size()-1; i++) printf("%d ",C[i]);
		printf("%d\n", C[C.size()-1]);
	}
}
