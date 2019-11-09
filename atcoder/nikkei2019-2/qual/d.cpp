#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N, M;
ll length[110000];
ll d[110000];
int main() {
  scanf("%d%d", &N, &M);
  vector<pair<pii, ll> > graph;
  for (auto i = 0; i < M; i++) {
    int l, r;
    ll c;
    scanf("%d%d%ld", &l, &r, &c);
    graph.push_back(pair<pii, ll>(pii(l, r), c));
  }
  graph.push_back(pair<pii, ll>(pii(1, 1), 0));
  sort(graph.begin(), graph.end());
}
