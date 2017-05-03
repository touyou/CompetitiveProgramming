#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
#define inf INT_MAX/2
int n, haba;
string in;
int r[13];
double dist[13][13], dp[1<<13][13];
void input(string in) {
    int i;
    string x="";
    for (i=0; i<in.length(); i++) {
        if (in[i]==' ') {
            stringstream ss;
            ss<<x;
            ss>>haba;
            x="";
            break;
        } else {
            x+=in[i];
        }
    }
    for (;i<in.length(); i++) {
        if (in[i]==' ') {
            stringstream ss;
            ss<<x;
            ss>>r[n];
            x=""; n++;
        } else {
            x+=in[i];
        }
    }
    stringstream ss;
    ss<<x;
    ss>>r[n]; n++;
}
double calc(int i, int j) {
    return sqrt((double)(r[i]+r[j])*(r[i]+r[j])-(double)(r[i]-r[j])*(r[i]-r[j]));
}
int main() {
    while (getline(cin,in)) {
        n=0; memset(r,0,sizeof(r));
        input(in);
        for (int i=1; i<n; i++) {
            dist[0][i]=dist[i][0]=r[i];
            for (int j=i+1; j<=n; j++) {
                dist[i][j]=dist[j][i]=calc(i,j);
            }
        }
        for (int S=0; S< 1<<n; S++) {
            fill(dp[S], dp[S]+n, inf);
        }
        dp[(1<<n)-1][0]=0;
        for (int S=(1<<n)-2; S>=0; S--) {
            for (int v=0; v<n; v++) {
                for (int u=0; u<n; u++) {
                    if (!(S>>u&1)) {
                        dp[S][v]=min(dp[S][v],dp[S|1<<u][u]+dist[v][u]);
                    }
                }
            }
        }
        if (dp[0][0]>haba) puts("NA");
        else puts("OK");
    }
}
