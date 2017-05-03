#include <bits/stdc++.h>
using namespace std;
int bill;
int c[4], ans[4];
int main() {
    bool flag = true;
    int coin[4] = {10, 50, 100, 500};
    while(scanf("%d",&bill)&&bill!=0) {
        if (!flag) {
            puts(" ");
            flag = false;
        }
        for (int i=0; i<4; i++) scanf("%d",&c[i]);
        // for (int i=3; i>=0; i--) {
        //     int temp = bill/coin[i];
        //     ans[i] = min(temp, c[i]);
        //     bill -= ans[i] * coin[i];
        // }
        for (int i=0; i<4; i++) {
            if (ans[i] != 0) printf("%d %d\n",coin[i],ans[i]);
        }
    }
}
