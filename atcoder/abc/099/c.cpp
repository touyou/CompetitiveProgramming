#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> money;

int main() {
  ll n;
  scanf("%lld", &n);
  for (int i = 9; i < 100011; i *= 9)
    money.push_back(i);
  for (int i = 6; i < 100011; i *= 6)
    money.push_back(i);
  money.push_back(1);
  sort(money.begin(), money.end());
  int dp[100001];
  fill(dp, dp + 100001, 100001);
  dp[0] = 0;
  for (int i = 0; i < money.size(); i++) {
    for (int j = money[i]; j < 100001; j++) {
      dp[j] = min(dp[j], dp[j - money[i]] + 1);
    }
  }
  printf("%d\n", dp[n]);
}
