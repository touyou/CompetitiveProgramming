#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int N,M;
    while (scanf("%d%d",&N,&M)) {
        if (N==0&&M==0) break;
        vector<int> map(N);
        for (int i=0; i<N; i++) scanf("%d",&map[i]);
        int res=0,tmp,cnt=0;
        bool flag=true;
        for (int i=0; i<M; i++) {
            scanf("%d",&tmp);
            if (flag) {
                res+=tmp;
                if (res<N-1) {
                    res+=map[res]; cnt++;
                    if (res>=N-1) flag=false;
                } else if (res>=N-1) {
                    cnt++;
                    flag=false;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
