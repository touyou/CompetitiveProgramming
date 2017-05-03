#include "grader.h"
#include <map>
#include <algorithm>
using namespace std;
map<int, int> pct() {
    int isp[40000];
    fill(isp, isp+40000, 1);
    isp[0]=isp[1]=0;
    int cnt=0;
    map<int, int> res;
    for (int i=2; i<40000; i++) {
        if (isp[i]) {
            res[i]=cnt++;
            for (int j=i*2; j<40000; j+=i) isp[j]=0;
        }
    }
    return res;
}
map<int, int> rpct() {
    int isp[40000];
    fill(isp, isp+40000, 1);
    isp[0]=isp[1]=0;
    int cnt=0;
    map<int, int> res;
    for (int i=2; i<40000; i++) {
        if (isp[i]) {
            res[cnt++]=i;
            for (int j=i*2; j<40000; j+=i) isp[j]=0;
        }
    }
    return res;
}
void taro(int N) {
    int res=-1;
    for (int i=2; i*i<=N; i++) {
        if (N%i==0) {
            res=i;
            break;
        }
    }
    map<int, int> mp=pct();
    // res<40000
    if (res==-1) send(0);
    else {
        int x=mp[res];
        for (int i=0; i<12; i++) send(x>>i&1);
    }
}

int jiro(int S, int X[]) {
    if (S==1&&X[0]==0) return -1;
    int t=1, res=0;
    map<int, int> ans=rpct();
    for (int i=0; i<12; i++) {
        res+=t*X[i];
        t*=2;
    }
    return ans[res];
}

