#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll f(ll n) {
  if (n % 2)
    return ((n + 1) / 2) % 2;
  else {
    return ((n / 2) % 2) ^ n;
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (f(a - 1) ^ f(b)) << endl;
}
