#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int x, y, z, n, d, a, h, w;
vector<int> hor, ver, res;
int main() {
    scanf("%d%d%d%d", &x, &y, &z, &n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&d,&a);
        if (d == 0) hor.push_back(a);
        else ver.push_back(a);
    }
    hor.push_back(x); ver.push_back(y);
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());
    for (int i=0; i<hor.size(); i++) for (int j=0; j<ver.size(); j++) {
        if (i == 0) w = hor[0];
        else w = hor[i] - hor[i-1];
        if (j == 0) h = ver[0];
        else h = ver[j] - ver[j-1];
        res.push_back(w*h*z);
    }
    sort(res.begin(), res.end());
    printf("%d\n", res[0]);
}
