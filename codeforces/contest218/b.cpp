#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int n, m;
int a[1000], b[1000];
int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
	scanf("%d",&a[i]);
	b[i]=a[i];
  }
  sort(a, a+m);
  sort(b, b+m);
  int maxi=0, mini=0;
  for (int i=0; i<n; i++) {
	maxi+=a[m-1];
	a[m-1]--;
	sort(a, a+m);
  }
  int c=0;
  for (int i=0; i<n; i++) {
	while (b[c]==0) c++;
	mini+=b[c];
	b[c]--;
	sort(b, b+m);
  }
  printf("%d %d\n",maxi, mini);
}
