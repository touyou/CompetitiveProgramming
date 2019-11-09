#include <bits/stdc++.h>
using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main() {
  int h, w, n, sr, sc;
  scanf("%d%d%d%d%d", &h, &w, &n, &sr, &sc);
  string s, t;
  cin >> s >> t;
  for (auto i = 0; i < n; i++) {
    // takahashi
    int nr, nc;
    switch (s[i]) {
      case 'L':
        nr = sr + dr[0];
        nc = sc + dc[0];
        break;
      case 'R':
        nr = sr + dr[1];
        nc = sc + dc[1];
        break;
      case 'U':
        nr = sr + dr[2];
        nc = sc + dc[2];
        break;
      case 'D':
        nr = sr + dr[3];
        nc = sc + dc[3];
        break;
    }
    if (nr < 1 || nr > h || nc < 1 || nc > w) {
      puts("NO");
      return 0;
    }
    if (min(h - nr + 1, nr) <= min(h - sr + 1, sr)) sr = nr;
    if (min(w - nc + 1, nc) <= min(w - sc + 1, sc)) sc = nc;
    // aoki
    switch (t[i]) {
      case 'L':
        nr = sr + dr[0];
        nc = sc + dc[0];
        break;
      case 'R':
        nr = sr + dr[1];
        nc = sc + dc[1];
        break;
      case 'U':
        nr = sr + dr[2];
        nc = sc + dc[2];
        break;
      case 'D':
        nr = sr + dr[3];
        nc = sc + dc[3];
        break;
    }
    if (nr < 1 || nr > h || nc < 1 || nc > w) continue;
    if (min(h - nr + 1, nr) >= min(h - sr + 1, sr)) sr = nr;
    if (min(w - nc + 1, nc) >= min(w - sc + 1, sc)) sc = nc;
  }
  if (sr < 1 || sr > h || sc < 1 || sc > w)
    puts("NO");
  else
    puts("YES");
}
