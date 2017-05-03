#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, k;
int d[50][6];
int cnt[105][105][105];
vector<int> xx, yy, dd;
map<int, int> idx, idy, idd, dix, diy, did;
int main() {
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%d%d%d%d%d%d",
                &d[i][0],&d[i][1],&d[i][2],&d[i][3],&d[i][4],&d[i][5]);
        xx.push_back(d[i][0]); xx.push_back(d[i][3]);
        yy.push_back(d[i][1]); yy.push_back(d[i][4]);
        dd.push_back(d[i][2]); dd.push_back(d[i][5]);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    sort(dd.begin(), dd.end());
    int idn=0, idm=0, ido=0;
    dix[0]=xx[0]; diy[0]=yy[0]; did[0]=dd[0];
    for (int i=1; i<xx.size(); i++) {
        if (dix[idn]!=xx[i]) idn++;
        idx[xx[i]] = idn;
        dix[idn]=xx[i];
    }
    for (int i=1; i<yy.size(); i++) {
        if (diy[idm]!=yy[i]) idm++;
        idy[yy[i]] = idm;
        diy[idm]=yy[i];
    }
    for (int i=1; i<dd.size(); i++) {
        if (did[ido]!=dd[i]) ido++;
        idd[dd[i]] = ido;
        did[ido]=dd[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=idx[d[i][0]]; j<idx[d[i][3]]; j++) {
            for (int l=idy[d[i][1]]; l<idy[d[i][4]]; l++) {
                for (int m=idd[d[i][2]]; m<idd[d[i][5]]; m++) cnt[j][l][m]++;
            }
        }
    }
    ll res=0;
    for (int i=0; i<idn; i++) {
        for (int j=0; j<idm; j++) {
            for (int l=0; l<ido; l++) {
                if (cnt[i][j][l]>=k) res+=((ll)(dix[i+1]-dix[i])*(ll)(diy[j+1]-diy[j])*(ll)(did[l+1]-did[l]));
            }
        }
    }
    printf("%lld\n",res);
}
