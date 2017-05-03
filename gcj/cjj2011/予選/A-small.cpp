#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
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
typedef long long ll;
int solve(int m, int c, int w, int a[], int b[]) {
	int deck[m+1];
	for (int i=1; i<=m; i++) deck[i]=i;
	for (int i=0; i<c; i++) {
		int temp[b[i]], npos=0;
		for (int j=a[i]; j<a[i]+b[i]; j++) {
			temp[npos++] = deck[j];
			deck[j] = 0;
		}
		int ndeck[m+1];
		for (int j=1; j<b[i]+1; j++) ndeck[j] = temp[j-1];
		npos = b[i]+1;
		for (int j=1; j<m+1; j++) {
			if (deck[j]) {
				ndeck[npos++] = deck[j];
			}
		}
		memcpy(deck, ndeck, sizeof(ndeck));
	}
	return deck[w];
}
int main() {
	int t;scanf("%d",&t);
	for (int ix=1; ix<=t; ix++) {
		int m, c, w;
		scanf("%d%d%d",&m,&c,&w);
		int a[c], b[c];
		for (int i=0; i<c; i++) scanf("%d%d",&a[i],&b[i]);
		printf("Case #%d: %d\n", ix, solve(m,c,w,a,b));
	}
}