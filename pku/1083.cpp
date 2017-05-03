#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int T; scanf("%d",&T);
  for (int ix=0; ix<T; ix++) {
    int N; scanf("%d",&N);
    vector<int> cor(200,0);
    int res=0;
    for (int i=0; i<N; i++) {
      int x,y; scanf("%d %d",&x,&y);
      if (x>y) swap(x,y);
      for (int j=(x-1)/2; j<=(y-1)/2; j++) cor[j]++;
    }
    for (int i=0; i<200; i++) if (res<cor[i]) res=cor[i];
    printf("%d\n",res*10);
  }
}
