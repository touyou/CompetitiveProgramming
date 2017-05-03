#include <cstdio>
#include <vector>
using namespace std;
int main() 
{
    int N, S;
    scanf("%d%d",&N,&S);
    vector<vector<int> > tri;
    for (int i=1; i<=N; i++) {
        vector<int> ed;
        for (int j=0; j<i; j++) {
            ed.push_back(S++);
            if (S == 10) S = 1;
        }
        tri.push_back(ed);
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) printf("  ");
        for (int j=i; j<N-1; j++) {
            printf("%d ", tri[j][i]);
        }
        printf("%d\n", tri[N-1][i]);
    }
}

