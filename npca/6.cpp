#include <cstdio>
#include <algorithm>
using namespace std;
int n, w[100000];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&w[i]);
    sort(w, w+n);
    int res=0;
    for (int i=1; i<n; i+=2) {
        res+=(w[i]-w[i-1]);
    }
    printf("%d\n",res);
}
