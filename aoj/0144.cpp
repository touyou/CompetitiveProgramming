#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#define inf INT_MAX/2
using namespace std;
int ok[100][100];
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) ok[i][j]=inf;
    for (int i=0; i<n; i++) {
        int r,k; scanf("%d%d",&r,&k);
        for (int j=0; j<k; j++) {
            int t; scanf("%d",&t);
            ok[r-1][t-1]=1;
        }
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ok[i][j]=min(ok[i][j],ok[i][k]+ok[k][j]);
            }
        }
    }
    int p; scanf("%d",&p);
    for (int i=0; i<p; i++) {
        int s,d,v; scanf("%d%d%d",&s,&d,&v);
        if (v<=ok[s-1][d-1]) puts("NA");
        else printf("%d\n",ok[s-1][d-1]+1);
    }
}
