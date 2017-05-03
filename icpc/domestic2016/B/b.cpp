// 2番目に多いところ＋残りの票数よりも一番多い票数が多ければその時点で確定
// Accepted
#include <bits/stdc++.h>
using namespace std;
int n, g[26], j;
char c[110], res;
int main() {
    while (scanf("%d",&n)) {
        if (n == 0) break;
        for (int i=0; i<n; i++) cin>>c[i];
        memset(g, 0, sizeof(g));
        int first = 0;
        int second = 0;
        for (j=0; j<n; j++) {
            int index = c[j] - 'A';
            g[index]++;
            if (first < g[index]) {
                first = g[index];
                res = c[j];
            } else if (second < g[index]) {
                second = g[index];
            }
            if (first > second + (n-j-1)) {
                break;
            }
        }
        if (j == n) printf("TIE\n");
        else cout<<res<<" "<<j+1<<endl;
    }
}
