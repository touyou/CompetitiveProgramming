#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll C(int c) {
    ll r=1;
    for (int i=2; i<=c; i++) r*=i;
    return r;
}
int main() {
    string s; cin>>s;
    map<char, int> cnt;
    for (int i=0; i<s.length(); i++) {
        if (cnt.find(s[i])!=cnt.end()) {
            cnt[s[i]]++;
        } else {
            cnt[s[i]]=1;
        }
    }
    int c=0, odd=0;
    for (map<char, int>::iterator it=cnt.begin(); it!=cnt.end(); it++) {
        if ((*it).second%2!=0) {
            odd++;
        }
    }
    if (odd>1) {
        puts("0");
    } else {
        ll res=C(s.length()/2);
        for (map<char, int>::iterator it=cnt.begin(); it!=cnt.end(); it++) {
            res/=C((*it).second/2);
        }
        printf("%lld\n",res);
    }
}
