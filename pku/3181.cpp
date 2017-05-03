#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, k;
char* add(char* a, char* b, char* out) {
    int as=strlen(a), bs=strlen(b);
    int c=0;
    int sz=0;
    for (int i=0; i<(as<bs?bs:as); i++) {
        int t=c;
        if (i<as) t+=a[i]-'0';
        if (i<bs) t+=b[i]-'0';
        c=t/10;
        t%=10;
        out[sz++]=t+'0';
    }
    if (c) out[sz++]=c+'0';
    out[sz]=0;
    return out;
}
char dp[1001][101][40];
bool vis[1001][101];
char zero[]="0";
char one[]="1";
char* rec(int n, int k) {
    if (n<0||k<1) return zero;
    if (n==0) return one;
    if (vis[n][k]) return dp[n][k];
    vis[n][k]=true;
    return add(rec(n,k-1),rec(n-k,k),dp[n][k]);
}
int main() {
    scanf("%d%d", &n, &k);
    string ans(rec(n,k));
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}
