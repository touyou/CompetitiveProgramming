#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string rev_s = s;
  reverse(rev_s.begin(), rev_s.end());
  int cnt = 0;
  for (auto i = 0; i < s.size(); i++)
    if (s[i] != rev_s[i]) cnt++;
  printf("%d\n", cnt / 2);
}
