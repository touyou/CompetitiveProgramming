#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;
int N;
ll d[100000], cnt[100000];
int main() {
  scanf("%d", &N);
  for (auto i = 0; i < N; i++) {
    scanf("%ld", d + i);
    cnt[d[i]]++;
  }
  if (d[0] != 0 || cnt[0] >= 2) {
    puts("0");
    return 0;
  }
  ll res = 1;
  for (auto i = 2; i < N; i++) {
    for (auto j = 0; j < cnt[i]; j++) {
      res = (res * cnt[i - 1]) % MOD;
    }
  }
  printf("%ld\n", res);
}
