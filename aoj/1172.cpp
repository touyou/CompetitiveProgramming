#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool isprime[1000001];
vector<int> prime;
int main() {
    fill(isprime, isprime+1000001, true);
    isprime[0]=isprime[1]=false;
    for (int i=2; i<1000001; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            for (int j=i+i; j<1000001; j+=i) isprime[j]=false;
        }
    }
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        printf("%d\n",upper_bound(prime.begin(),prime.end(),2*n)-upper_bound(prime.begin(),prime.end(),n));
    }
}
