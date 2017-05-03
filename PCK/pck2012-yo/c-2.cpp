#include <cstdio>
#include <vector>
using namespace std;
int n;
int h[100];
int main() {
  while (scanf("%d",&n)) {
	if (!n) break;
	for (int i=0; i<n+1; i++) scanf("%d",&h[i]);
	for (int i=0; i<n+1; i++) {
	  vector<int> tmp;
	  for (int j=0; j<n+1; j++) if (j!=i) tmp.push_back(h[j]);
	  bool flag = true;
	  int diff = tmp[1]-tmp[0];
	  for (int j=1; j<tmp.size()-1; j++) if (diff!=tmp[j+1]-tmp[j]) {
		  //printf("%d %d\n",tmp[j+1],tmp[j]);
		  flag=false;
		}
	  if (flag) {
		printf("%d\n",h[i]);
		break;
	  }
	}
  }
}
