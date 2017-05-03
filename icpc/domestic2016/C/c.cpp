// エラトステネスの篩もどきで同時に咲くことがないように決める
// Accepted
#include <bits/stdc++.h>
using namespace std;
int m, n;
int res;
int judge[8000000];
int main() {
    while(scanf("%d%d",&m,&n)) {
        if (m==0&&n==0) break;
        memset(judge, 0, sizeof(judge));
        int c = 0;
        for (int i=m; i<8000000; i++) {
            if (judge[i]==0) {
                if (c == n) {
                    res = i;
                    break;
                }
                c++;
                for (int j=i*2; j<8000000; j+=i) judge[j] = 1;
            }
        }
        printf("%d\n",res);
    }
}
