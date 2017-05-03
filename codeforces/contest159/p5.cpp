#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,vector<P> > M;
M stack;
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) {
        ll c,s; cin>>c>>s;
        stack[c].push_back(P(s,i+1));
    }
    M::iterator it;
    for (it=stack.begin(); it!=stack.end(); it++) {
        sort((*it).second.rbegin(),(*it).second.rend());
    }
    ll mh=0, c1=0, c2=0, cnt=0;
    for (it=stack.begin(); it!=stack.end(); it++) {
        for (M::iterator it2=stack.begin(); it2!=stack.end(); it2++) {
            if ((*it).first!=(*it2).first) {
                int s1=(*it).second.size(), s2=(*it2).second.size();
                if (s1<s2) {
                    ll h=0;
                    for (int i=0; i<s1; i++) {
                        h+=(*it).second[i].first+(*it2).second[i].first;
                    }
                    h+=(*it2).second[s1].first;
                    if (mh<h) {
                        mh=h;
                        c1=(*it).first;
                        c2=(*it2).first;
                        cnt=s1*2+1;
                    }
                } else if (s1>s2) {
                    ll h=0;
                    for (int i=0; i<s2; i++) {
                        h+=(*it).second[i].first+(*it2).second[i].first;
                    }
                    h+=(*it).second[s2].first;
                    if (mh<h) {
                        mh=h;
                        c1=(*it).first;
                        c2=(*it2).first;
                        cnt=s2*2+1;
                    }
                } else {
                    ll h=0;
                    for (int i=0; i<s1; i++) {
                        h+=(*it).second[i].first+(*it2).second[i].first;
                    }
                    if (mh<h) {
                        mh=h;
                        c1=(*it).first;
                        c2=(*it2).first;
                        cnt=s1*2;
                    }
                }
            }
        }
    }
    cout<<mh<<endl; cout<<cnt<<endl;
//    cout<<c1<<" "<<c2<<endl;
    int rs1=stack[c1].size(), rs2=stack[c2].size();
    if (rs1<rs2) {
        for (int i=0; i<rs1; i++) {
            cout<<stack[c2][i].second<<" "<<stack[c1][i].second<<" ";
        }
        cout<<stack[c2][rs1].second<<endl;
    } else if (rs2<rs1) {
        for (int i=0; i<rs2; i++) {
            cout<<stack[c1][i].second<<" "<<stack[c2][i].second<<" ";
        }
        cout<<stack[c1][rs2].second<<endl;
    } else {
        for (int i=0; i<rs1; i++) {
            cout<<stack[c2][i].second<<" ";
            if (i!=rs1-1) cout<<stack[c1][i].second<<" ";
            else cout<<stack[c1][i].second<<endl;
        }
    }
}
