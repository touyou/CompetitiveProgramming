#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  vector<int> array{a, b, c};
  sort(array.begin(), array.end());
  printf("%d %d %d\n", array[0], array[1], array[2]);
}
  
