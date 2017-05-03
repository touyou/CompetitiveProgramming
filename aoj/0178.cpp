#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
int main() {
    int n, d, p, q;
    while (scanf("%d", &n)&&n!=0) {
        vii tet;
        for (int ix=0; ix<n; ix++) {
            scanf("%d%d%d",&d,&p,&q);
            int sz = tet.size();
            if (d == 1) {
                if (sz == 0) {
                    vi block(5, 0);
                    for (int i=0; i<q; i++) {
                        block[p-1+i] = 1;
                    }
                    tet.push_back(block);
                } else {
                    int i;
                    for (i = sz-1; i>=0; i--) {
                        bool flag = false;
                        for (int j=0; j<q; j++) {
                            if (tet[i][p-1+j] == 1) {
                                flag = true;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                    if (i == sz-1) {
                        vi block(5, 0);
                        for (int j=0; j<q; j++) {
                            block[p-1+j] = 1;
                        }
                        tet.push_back(block);
                    } else {
                        for (int j=0; j<q; j++) {
                            tet[i+1][p-1+j] = 1;
                        }
                    }
                } 
            } else {
                    int i;
                    for (i = sz-1; i>=0; i--) {
                        if (tet[i][p-1] == 1)
                            break;
                    }
                    i++;
                    if (i != sz) {
                        for (int j=i; j<sz&&q>0; j++) {
                            tet[j][p-1] = 1;
                            q--;
                        }
                    }
                    if (q != 0) {
                            for (int j=0; j<q; j++) {
                                vi block(5, 0);
                                block[p-1] = 1;
                                tet.push_back(block);
                            }
                        }
            }
            int i = 0;
            for (vii::iterator it=tet.begin(); it!=tet.end(); it++) {
                int tmp = 0;
                for (int j=0; j<5; j++) {
                    tmp += tet[i][j];
                }
                if (tmp == 5) {
                    tet.erase(it);
                    it--;
                    i--;
                }
                i++;
            }
        }
        int res = 0;
        for (int i=0; i<tet.size(); i++) for (int j=0; j<5; j++) res += tet[i][j];
        printf("%d\n", res);
    }
}
