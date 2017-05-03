#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> abn;
set<int> se;
int divis(int num) {
    int sum = 0;
    for (int i=1; i<num; i++) {
        if (num%i==0) sum+=i;
    }
    return sum;
}
int main() {
    for (int i=1; i<30000; i++) {
        if (divis(i) > i) {
            abn.push_back(i);
        }
    }
    for (int i=0; i<abn.size(); i++) {
        for (int j=0; j<abn.size(); j++) {
            se.insert(abn[i]+abn[j]);
        }
    }
    ll ans = 0;
    for (int i=1; i<30000; i++) {
        if (se.find(i)==se.end()) ans += (ll)i;
    }
    printf("%lld\n",ans);
}
