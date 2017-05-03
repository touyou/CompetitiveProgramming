#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, a[100000], b[100000];
vector<int> birth, dead;
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&a[i],&b[i]);
        birth.push_back(a[i]);
        dead.push_back(b[i]);
    }
    sort(birth.begin(), birth.end());
    sort(dead.begin(), dead.end());
    for (int i=0; i<n; i++) {
        printf("%d\n",int((upper_bound(birth.begin(), birth.end(), b[i])-birth.begin())-(lower_bound(dead.begin(), dead.end(), a[i])-dead.begin()))-1);
    }
}
