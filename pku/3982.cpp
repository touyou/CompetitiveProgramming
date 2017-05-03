#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string ret;
string add(const string &a, const string &b) {
    ret="";
    int as=a.size(), bs=b.size();
    int c=0;
    for (int i=0; i<max(as,bs); i++) {
        int t=c;
        if (i<as) t+=a[as-i-1]-'0';
        if (i<bs) t+=b[bs-i-1]-'0';
        c=t/10;
        t%=10;
        ret+=t+'0';
    }
    if (c) ret+=c+'0';
    reverse(ret.begin(), ret.end());
    return ret;
}
int main() {
    string dp[100];
    while (cin>>dp[0]>>dp[1]>>dp[2]) {
        for (int i=3; i<100; i++) {
            dp[i]=add(dp[i-1],add(dp[i-2],dp[i-3]));
        }
        cout<<dp[99]<<endl;
    }
}
