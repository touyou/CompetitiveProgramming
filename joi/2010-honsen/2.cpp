#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int main() {
	int n, k; scanf("%d%d",&n,&k);
	P book[n];
	for (int i=0; i<n; i++) scanf("%d%d",book[i].second,book[i].first);
	sort(book,book+n);
}
