// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1257
// 素数を列挙した後はしゃくとり法で
#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
int n, res;
int main() {
    int isPrime[10001];
    fill(isPrime, isPrime+10001, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i=2; i<=10000; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j=i*2; j<=10000; j+=i) isPrime[j] = 0;
        }
    }
    while(scanf("%d",&n)) {
        if (n == 0) break;
        res = 0;
        int lb = 0, rb = 0, sum = 0;
        while (lb < prime.size()) {
            while (sum<n && rb<prime.size()) sum += prime[rb++];
            if (sum == n) res++;
            sum -= prime[lb++];
        }
        printf("%d\n",res);
    }
}
