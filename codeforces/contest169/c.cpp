#include <cstdio>
#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
typedef long long ll;
string s, t;
int slen, tlen;
ll cnt;
int c[5001][26];
void dfs(int x, int y) {
    if (x<slen||y<tlen) return;
    cnt=(cnt+c[y-1][s[x]-'a'])%mod;
    for (int i=y; i<tlen; i++) {
        if (s[x]==t[i]) dfs(x+1,i+1);
    }
}
int main() {
    cin>>s>>t;
    slen=s.length(); tlen=t.length();
    ll cnt=0;
    for (int i=tlen-1; i>0; i--) {
        for (int j=0; j<26; j++) {
            c[i-1][j]=c[i][j];
            if (t[i]-'a'==j) c[i-1][j]++;
        }
    }
    for (int i=0; i<slen; i++) {
        cnt=(cnt+c[0][s[i]-'a'])%mod;
        if (c[0][s[i]-'a']!=0) {
            for (int j=0; j<tlen; j++) {
                if (s[i]==t[j]) dfs(i+1,j+1);
            }
        }
    }
    printf("%d\n",(int)cnt%mod);
}
