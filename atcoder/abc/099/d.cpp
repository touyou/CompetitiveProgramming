#include <bits/stdc++.h>
using namespace std;

int d[30][30], color[500][500];
int arr[3][30];
int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  for (int i = 0; i < c; i++)
    for (int j = 0; j < c; j++)
      scanf("%d", &d[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &color[i][j]);
  int res = INT_MAX;
  for (int cx = 0; cx < c; cx++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        arr[(i + j) % 3][cx] += d[color[i][j] - 1][cx];
      }
    }
  }
  for (int c1 = 0; c1 < c; c1++) {
    for (int c2 = 0; c2 < c; c2++) {
      for (int c3 = 0; c3 < c; c3++) {
        if (c1 == c2 || c2 == c3 || c3 == c1)
          continue;
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
              if (i == j || j == k || k == i)
                continue;
              res = min(res, arr[i][c1] + arr[j][c2] + arr[k][c3]);
            }
          }
        }
      }
    }
  }
  printf("%d\n", res);
}
