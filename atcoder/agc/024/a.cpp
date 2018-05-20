#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a, b, c, k;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
  /*
      係数が1,0,0と0,1,1から始まり、sとoとするとs_(n+1)=2o_(n),
     o_(n+2)=2o_(n)+o_(n+1) s_0=1,o_0=0,s_1=0,o_1=1 (x-2)(x+1)=0
      o_n2-2o_n1=-(o_n1-2o_n) -> n+1 - 2n = (-1)^n
      o_n2+o_n1=2(o_n1+o_n) -> n+1 + n = 2^n
      o_n = (2^n - (-1)^n) / 3
      s_n = (2^n - 2(-1)^(n-1)) / 3

      a_n = s_n*a + o_n*(b+c)
      b_n = s_n*b + o_n*(a+c)
      a_n - b_n = s_n * (a - b) + o_n * (b - a)
  */
  ll ab = a - b;
  ll ba = b - a;
  if (k % 2 == 0) {
    // o_k = (2^k - 1) / 3, s_k = (2^k + 2) / 3
    // (2ab - ba) / 3
    ll y = (2 * ab - ba) / 3;
    printf("%lld\n", y);
  } else {
    // o_k = (2^k + 1) / 3, s_k = (2^k - 2) / 3
    // (ab - 2ba) / 3
    ll y = (ba - 2 * ab) / 3;
    printf("%lld\n", y);
  }
}
