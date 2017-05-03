#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
int n;
double res;
int str[101];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&str[i]);
    }
    sort(str, str+n, greater<int>());
    res=(double)str[0];
    for (int i=1; i<n; i++) {
        res=2*sqrt(res*str[i]);
    }
    printf("%.3f\n",res);
}
