#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int d;
int isp[1000001];
vector<int> p;
vector<int> tb;
int main() {
    fill(isp,isp+1000000,1);
    isp[0]=isp[1]=0;
    for (int i=2; i<=1000000; i++) {
        if (isp[i]) {
            p.push_back(i);
            for (int j=2*i; j<=1000000; j+=i) isp[j]=0;
        }
    }
    for (int i=0; i<p.size(); i++) {
        stringstream ss; ss<<p[i]; string r=ss.str();
        reverse(r.begin(), r.end());
        if (r==ss.str()) continue;
        int x;
        stringstream s2; s2<<r; s2>>x;
        if (isp[x]) {
            tb.push_back(p[i]);
        }
    }
    scanf("%d",&d);
    printf("%d\n",tb[d-1]);
}
