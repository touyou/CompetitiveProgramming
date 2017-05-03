#include <cstdio>
#include <vector>
using namespace std;
int main() 
{
    int n;
    while (scanf("%d",&n)&&n!=0) {
        vector<vector<int> > map;
        for (int i=0; i<n; i++) {
            vector<int> in(n+1);
            in[n]=0;
            for (int j=0; j<n; j++) {
                scanf("%d",&in[j]);
                in[n]+=in[j];
            }
            map.push_back(in);
        }
        vector<int> sum(n+1,0);
        for (int i=0; i<n+1; i++) {
            for (int j=0; j<n; j++) {
                sum[i]+=map[j][i];
            }
        }
        map.push_back(sum);
        for (int i=0; i<n+1; i++) {
            for (int j=0; j<n+1; j++) {
                printf("%5d",map[i][j]);
            }
            printf("\n");
        }
    }
}

        
