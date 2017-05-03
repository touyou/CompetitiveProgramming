#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int t; scanf("%d",&t);
  for (int ix=0; ix<t; ix++) {
    int n; scanf("%d",&n);
    vector<bool> jail(n,true);
    for (int i=2; i<=n; i++) {
      for (int j=i-1; j<n; j+=i) {
	jail[j]=!jail[j];
      }
    }
    int res=0;
    for (int i=0; i<n; i++) if (jail[i]) res++;
    printf("%d\n",res);
  }
}
