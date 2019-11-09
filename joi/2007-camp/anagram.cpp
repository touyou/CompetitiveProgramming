#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map<char, int> cnt;
ll calc[21];
int main() {
    calc[0]=0;
    calc[1]=1;
    for (int i=2; i<=20; i++) calc[i]=calc[i-1]*i;
    string str; cin>>str;
    for (int i=0; i<str.size(); i++) {
        if (cnt.find(str[i])!=cnt.end()) cnt[str[i]]++;
        else cnt[str[i]]=1;
    }
    ll ans=0;
    int sz=str.size()-1;
    for (int i=0; i<str.size()-1; i++) {
        for (map<char,int>::iterator j=cnt.begin(); j!=cnt.end(); j++) {
            if ((*j).first==str[i]) break;
            cnt[(*j).first]--;
            ll res=0;
            if (cnt[(*j).first]>=0) res+=calc[sz-i];
            for (map<char,int>::iterator it=cnt.begin(); it!=cnt.end(); it++) {
                if ((*it).second>=2) res/=calc[(*it).second];
            }
            ans+=res;
//            printf("%d %lld %c\n",i,res,(*j).first);
            cnt[(*j).first]++;
        }
        cnt[str[i]]--;
    }
    printf("%lld\n",ans+1);
}
