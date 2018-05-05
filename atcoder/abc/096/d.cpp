#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> prime;
bool isPrime[55556];
int main() {
  fill(isPrime, isPrime + 55556, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < 55556; i++) {
    if (isPrime[i]) {
      prime.push_back(i);
      for (int j = i * 2; j < 55556; j += i) {
        isPrime[j] = false;
      }
    }
  }
  int n;
  scanf("%d", &n);
  int x = 0;
  for (int i = 0; i < prime.size(); i++) {
    if (prime[i] % 5 == 1) {
      printf("%d", prime[i]);
      x++;
    }
    if (x == n)
      break;
    printf(" ");
  }
  puts("");
}
