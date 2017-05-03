#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, k, x;
float c[10], sum;
int score[1000];

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0; i<n; i++) scanf("%f",&c[i]);
    for (int i=0; i<m; i++) {
        sum = 0.0;
        for (int j=0; j<n; j++) {
            scanf("%d",&x);
            sum += (float)x*c[j];
        }
        if (sum - floor(sum) >= 0.5) score[i] = floor(sum) + 1;
        else score[i] = floor(sum);
    }
    sort(score, score+m);
    for (int i=m-1; i>=m-k; i--) printf("%d\n",score[i]);
}
