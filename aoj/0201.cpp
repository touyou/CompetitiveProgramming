// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// typedef pair<ll, int> P;
// map<string, int> hash;
// int key;
// int findkey(string str) {
//   if (hash.find(str) != hash.end()) return hash[str];
//   return hash[str]=key;
// }

// int n, m, k;
// P p[100];
// ll dp[100];
// vector<int> rec[100];
// string ins;

// ll dfs(int ks) {
//   if (rec[ks].size()==0) return dp[ks];
//   ll sum = 0;
//   for (int i=0; i<rec[ks].size(); i++) {
//     sum += dfs(rec[ks][i]);
//   }
//   if (sum < dp[ks]) dp[ks] = sum;
//   return dp[ks];
// }

// int main() {
//   while (scanf("%d",&n)) {
//     if (!n) break;
//     key=0;
//     for (int i=0; i<n; i++) {
//       cin>>ins>>p[i].first;
//       dp[i]=p[i].first;
//       p[i].second=findkey(ins);
//       key++;
//     }
//     scanf("%d",&m);
//     for (int i=0; i<m; i++) {
//       cin>>ins>>k;
//       int o = findkey(ins);
//       for (int j=0; j<k; j++) {
//         cin>>ins;
//         rec[o].push_back(findkey(ins));
//       }
//     }
//     cin>>ins;
//     int need = findkey(ins);
//     // sort(p, p+n);
//     ll ans = dfs(need);
//     printf("%lld\n",ans);
//   }
// }
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> it;
map<string, vector<string> > rec;
int n, m, p, k;
string str;
int dfs(string s) {
  if (rec[s].size()==0) return it[s];
  int sum = 0;
  for (int i=0; i<rec[s].size(); i++) {
    sum+=dfs(rec[s][i]);
  }
  return it[s]=min(it[s], sum);
}
int main() {
  while (scanf("%d",&n)) {
    if (!n) break;
    it.clear(); rec.clear();
    for (int i=0; i<n; i++) {
      cin>>str>>p;
      it[str] = p;
    }
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
      cin>>str>>k;
      string need = str;
      for (int j=0; j<k; j++) {
        cin>>str;
        rec[need].push_back(str);
      }
    }
    cin>>str;
    cout<<dfs(str)<<endl;
  }
}
