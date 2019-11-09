#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int t, n;
int card[13];
int main() {
  scanf("%d", &t);
  for (int ix = 0; ix < t; ix++) {
    scanf("%d",&n);
    vector<int> rem;
    for (int i = 0; i < n; i++) rem.push_back(i);
    
    int idx = 0;
    for (int i = 1; i <= n; i++) {
      idx = (idx + i) % rem.size();
      card[rem[idx]] = i;
      rem.erase(rem.begin() + idx);
    }
    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", card[i]);
    }
    puts("");
  }
}
