#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int t, e;
string s;
ll fact[501];
int main() {
    fact[0]=1;
    for (int i=1; i<501; i++) {
        fact[i]=fact[i-1]*(i+1)%MOD;
        //printf("%lld%c",fact[i],i%10==0?'\n':' ');
    }
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        cin>>s;
        int len=s.length();
        ll res=fact[len-1];
        sort(s.begin(), s.end());
        char state=s[0];
        int cnt=1;
        for (int i=1; i<len; i++) {
            if (state==s[i]) cnt++;
            else {
                res /= fact[cnt-1];
                state=s[i];
                cnt=1;
            }
        }
        res /= fact[cnt-1];
        printf("%lld\n",res);
    }
}
