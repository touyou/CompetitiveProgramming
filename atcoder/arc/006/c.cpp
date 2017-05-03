#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, w[50];
vector<int> vc;
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&w[i]);
    for (int i=0; i<n; i++) {
        sort(vc.begin(), vc.end());
        int pos=lower_bound(vc.begin(), vc.end(), w[i])-vc.begin();
        if (pos==vc.size()) vc.push_back(w[i]);
        else {
            vc[pos]=w[i];
        }
    }
    printf("%d\n",vc.size());
}