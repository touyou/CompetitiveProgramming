#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int isp[1000000];
vector<int> p;
int main() {
    fill(isp, isp+1000000, 1);
    isp[0]=isp[1]=0;
    for (int i=2; i<1000000; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (int j=i*2; j<1000000; j+=i) isp[j]=0;
    }
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        int res=0;
        for (int i=0; i<p.size()&&n-p[i]>=p[i];i++) {
            if (isp[n-p[i]]) res++;
        }
        printf("%d\n",res);
    }
}
