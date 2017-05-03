#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<string> s;
bool C(int n, int w, int h) {
    int sz=s.size();
    if (n*sz<=h) {
        int len=0;
        for (int i=0; i<sz; i++) len=max(len,(int)s[i].length());
        if (n*len<=w) return true;
        else return false;
    } else {
        int len[sz];
        for (int i=0; i<sz; i++) len[i]=s[i].length();
        int lim=sz-floor(h/n);
        int can=0, bef=len[0];
        if (bef*n>w) return false;
        for (int i=1; i<sz; i++) {
            if (len[i]*n>w) return false;
            if ((bef+len[i]+1)*n<=w) {
                bef+=len[i]+1;
                can++;
            } else {
                bef=len[i];
            }
        }
        if (can>=lim) return true;
        else return false;
    }
}
int main() {
    int t; cin >> t;
    int w, h;
    string line;
    getline(cin,line);
    for (int ix=1; ix<=t; ix++) {
        cin >> w >> h;
        getline(cin, line);
        s.clear();
        string temp="";
        for (int i=1; i<line.length(); i++) {
            if (line[i]==' ') {
                s.push_back(temp);
                temp="";
            } else temp+=line[i];
        }
        s.push_back(temp);
        int l=1, r=min(w, h)+1;
        while (r-l>1) {
            int mid=(l+r)/2;
            if (C(mid,w,h)) {
                l=mid;
            } else {
                r=mid;
            }
        }
        cout << "Case #" << ix << ": " << l << endl;
    }
}
