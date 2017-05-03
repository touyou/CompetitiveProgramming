#include <cstdio>
#include <vector>
using namespace std;
int n;
int light[100000];
vector<int> count;
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&light[i]);
    int cnt = 1;
    int now = light[0];
    for (int i=1; i<n; i++) {
        if (now == light[i]) {
            count.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
            now = light[i];
        }
    }
    count.push_back(cnt);
    
    int res = 0;
    for (int i=0; i<count.size(); i++) {
        if (i-1>=0&&i+1<count.size()) res = max(res, count[i-1]+count[i]+count[i+1]);
        else if (i-1<0) res = max(res, count[i]+count[i+1]);
        else res = max(res, count[i-1]+count[i]);
    }
    printf("%d\n",res);
}