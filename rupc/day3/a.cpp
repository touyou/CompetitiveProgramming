#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<string, int> P;
vector<P> log;
int main() {
    string s; cin >> s;
    string bef="";
    int i=0;
    if (s[0]=='e') {
        bef="egg";
        i+=3;
    } else {
        bef="chicken";
        i+=7;
    }
    if (i==s.length()) {
        cout<<bef<<endl;
        return 0;
    }
    int cnt=1;
    for (;i<s.length(); i++) {
        if (s[i]=='e'&&bef=="egg") {
            log.push_back(P(bef,cnt));
            cnt=1;
            i+=2;
        } else if (s[i]=='c'&&bef=="chicken") {
            log.push_back(P(bef,cnt));
            cnt=1;
            i+=6;
        } else {
            if (s[i]=='e') {
                bef="egg";
                i+=2;
            } else if (s[i]=='c') {
                bef="chicken";
                i+=6;
            }
            cnt++;
        }
    }
    log.push_back(P(bef,cnt));
    string res;
    int rc=0;
    for (int i=0; i<log.size(); i++) {
        if (log[i].second>rc) {
            res=log[i].first;
            rc=log[i].second;
        }
        // cout<<log[i].first<<" "<<log[i].second<<endl;
    }
    cout<<res<<endl;
}
