#include <cstdio>
#include <vector>
using namespace std;
#define PB push_back

int main() {
	int n; scanf("%d",&n);
	vector<int> deck(2*n), tmp1(n), tmp2(n);
	for (int i=0; i<2*n; i++) deck[i] = i+1;
	int m; scanf("%d",&m);
	for (int c=0; c<m; c++) {
		int k; scanf("%d",&k);
		if (k != 0) {
			vector<int> back, before;
			for (int l=0; l<k; l++) before.PB(deck[l]);
			for (int l=k; l<2*n; l++) back.PB(deck[l]);
			for (int i=0; i<back.size(); i++) deck[i] = back[i];
			for (int i=0; i<before.size(); i++) deck[i+back.size()] = before[i];
		} else {
			vector<int> before, back;
			for (int i=0; i<n; i++) before.PB(deck[i]);
			for (int i=n; i<2*n; i++) back.PB(deck[i]);
			for (int i=0; i<2*n; i+=2) deck[i]=before[i/2];
			for (int i=1; i<2*n; i+=2) deck[i]=back[(int)(i/2)];
		}
	}
	for (int i=0; i<2*n; i++) printf("%d\n",deck[i]);
}
