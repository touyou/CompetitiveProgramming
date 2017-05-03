#include <cstdio>
#include <vector>
using namespace std;
int val[3000][366];
int dp[3000][366][3];
int main() {
    int n, d; scanf("%d%d",&n,&d);
    for (int i=1; i<=d; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&val[j][i]);
        }
    }
    for (int i=1; i<=d; i++) {
        for (int j=0; j<n; j++) {
            dp[j][i][0]=val[j][i-1];
        }
        for (int j=0; j<n; j++) {
            dp[j][i][1]
