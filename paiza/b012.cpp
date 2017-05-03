#include <iostream>
using namespace std;
int n, even, odd, flag, x;
string str;
int solve(string s) {
  for (int i=0; i<16; i+=2) {
    x = (int)s[i] - '0';
    if (x >= 5) {
      x *= 2;
      x -= 9;
    } else x *= 2;
    even += x;
  }
  for (int i=1; i<15; i+=2) {
    odd += (int)(s[i]-'0');
  }
  return (even+odd)%10==0?0:10-(even+odd)%10;
}
int main() {
  cin>>n;
  for (int i=0; i<n; i++) {
    cin>>str;
    even = 0; odd = 0;
    cout<<solve(str)<<endl;
  }
}
