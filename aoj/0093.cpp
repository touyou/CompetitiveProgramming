#include <cstdio>
#include <vector>
using namespace std;
int main() {
    bool flag=false;
    int a, b;
    while (scanf("%d%d",&a,&b)) {
        if (!a&&!b) break;
        if (flag) puts("");
        flag=true;
        vector<int> leap;
        for (int i=a; i<=b; i++) {
            if (i%4==0&&(i%100!=0||i%400==0)) {
                leap.push_back(i);
            }
        }
        if (leap.size()==0) puts("NA");
        else {
            for (int i=0; i<leap.size(); i++) printf("%d\n",leap[i]);
        }
    }
}
