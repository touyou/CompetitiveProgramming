#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> elem;

vector<string> masu;
int h, w;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
  scanf("%d%d", &h, &w);
  queue<elem> que;
  for (auto i = 0; i < h; i++) {
    string line;
    cin >> line;
    masu.emplace_back(line);
    for (auto j = 0; j < w; j++) {
      if (line[j] == '#') {
        que.push(elem(0, pii(i, j)));
      }
    }
  }
  int mcnt = 0;
  while (!que.empty()) {
    elem e = que.front();
    que.pop();
    auto x = e.second.second;
    auto y = e.second.first;
    auto cnt = e.first;
    mcnt = max(mcnt, cnt);
    for (auto i = 0; i < 4; i++) {
      auto nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
        if (masu[ny][nx] == '.') {
          masu[ny][nx] = '#';
          que.push(elem(cnt + 1, pii(ny, nx)));
        }
      }
    }
  }
  printf("%d\n", mcnt);
}
