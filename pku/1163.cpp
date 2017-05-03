#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int main() {
  int N; scanf("%d",&N);
  vvi tri;
  for (int i=1; i<=N; i++) {
    vi tmp(i);
    if (i!=1) {
      for (int j=0; j<i; j++) {
	scanf("%d",&tmp[j]);
	if (j==0) tmp[j]+=tri[i-2][j];
	else if (j==i-1) tmp[j]+=tri[i-2][j-1];
	else tmp[j]+=max(tri[i-2][j],tri[i-2][j-1]);
      }
    } else {
      scanf("%d",&tmp[0]);
    }
    tri.push_back(tmp);
  }
  int res=0;
  for (int i=0; i<N; i++) if (res<tri[N-1][i]) res=tri[N-1][i];
  printf("%d\n",res);
}
