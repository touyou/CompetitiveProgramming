#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
int main() {
    int n;
    while (scanf("%d", &n)&&n!=0) {
        vii foods;
        for (int i=0; i<n; i++) {
            vi tmp(4);
            scanf("%d%d%d%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
            foods.push_back(tmp);
        }
        int P, Q, R, C;
        scanf("%d%d%d%d", &P,&Q,&R,&C);
        vi res;
        for (int i=0; i<n; i++) {
            int cp=foods[i][1],cq=foods[i][2],cr=foods[i][3],cc=cp+cq+cr;
            if (cp<=P&&cq<=Q&&cr<=R&&cc<=C) res.push_back(foods[i][0]);
        }
        if (res.empty()) {
            printf("NA\n");
        } else {
            for (int i=0; i<res.size(); i++) {
                printf("%d\n", res[i]);
            }
        }
    }
}
