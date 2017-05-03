#include <cstdio>
#include <climits>
#include <algorithm>
#define inf INT_MAX/2;
using namespace std;
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        int M=0, m=inf;
        for (int i=0; i<n; i++) {
            int sum=0;
            for (int j=0; j<5; j++) {
                int s; scanf("%d",&s);
                sum+=s;
            }
            M=max(M,sum);
            m=min(m,sum);
        }
        printf("%d %d\n",M,m);
    }
}
