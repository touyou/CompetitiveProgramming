#include <cstdio>
#include <iostream>
using namespace std;
int x, y, t, ans[30];
int main() {
  scanf("%d%d", &x, &y);
  for (int i=0; i<y; i++) for (int j=0; j<x; j++) {
    scanf("%d", &t);
    if (t==1) ans[j]++;
  }
  for (int i=0; i<y; i++) {
    for (int j=0; j<x; j++) {
      if (j!=0) printf(" ");
      if (i<y-ans[j]) printf("0");
      else printf("1");
    }
    cout<<endl;
  }
}
