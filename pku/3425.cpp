#include <cstdio>
#include <map>
using namespace std;
struct ac
{
    int anum, cost;
};
int main()
{
    int N;
    int q, a, x;
    map<int, ac> m;
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d%d%d",&q,&a,&x);
        if (m.find(q)==m.end()) {
            if (a == 0) {
                m[q].cost = 10;
            }
            else if (a == 1 && x == 0) {
                m[q].cost = 20;
                m[q].anum = 1;
            }
            else if (a == 1 && x == 1) {
                m[q].cost = 40;
                m[q].anum = 1;
            }
        }
        else {
            if (a == 0) {
                m[q].cost += 10;
            }
            else if (a == 1 && x == 0) {
                m[q].cost += 20 + m[q].anum * 10;
                m[q].anum++;
            }
            else if (a == 1 && x == 1) {
                m[q].cost += 40 + m[q].anum * 10;
                m[q].anum++;
            }
        }
    }
    map<int, ac>::iterator it;
    int res = 0;
    for (it=m.begin(); it!=m.end(); it++) res += (*it).second.cost;
    printf("%d\n",res);
}
