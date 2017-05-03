#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    int k; scanf("%d",&k);
    string s; cin>>s;
    ll res=0;
    if (k==0) {
        int cnt=0;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='1') {
                res=max(res,(ll)cnt);
                cnt=0;
            } else {
                cnt++;
            }
        }
        res++;
    } else {
        int lcnt=-1, rcnt=-1;
        int l=-1, r=-1;
        int cnt=0;
        for (int i=0; i<s.length(); i++) {
            if (cnt==0&&s[i]=='1') {
                l=i;
                lcnt=i+1;
            }
            if (cnt==k-1&&s[i]=='1') {
                r=i;
            }
            if (cnt==k&&s[i]=='1') {
                rcnt=i-r;
                break;
            }
            if (s[i]=='1') cnt++;
        }
        if (rcnt==-1&&cnt==k) {
            rcnt=s.length()-r;
        }
        if (lcnt==-1||rcnt==-1||l==-1||r==-1) {
            puts("0");
            return 0;
        }
        res+=lcnt*rcnt;
        for (;;) {
            bool flag=false;
            for (int i=l+1; i<s.length(); i++) {
                if (s[i]=='1') {
                    lcnt=i-l;
                    l=i;
                    flag=true;
                    break;
                }
            }
            if (!flag) break;
            flag=false;
            for (int i=r+1; i<s.length(); i++) {
                if (flag&&s[i]=='1') {
                    rcnt=i-r;
                    break;
                } else if (s[i]=='1') {
                    r=i;
                    flag=true;
                }
            }
            if (!flag) break;
            res+=rcnt*lcnt;
        }
    }
    cout << res << endl;
}
