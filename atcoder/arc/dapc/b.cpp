#include <cstdio>
#include <iostream>
using namespace std;
string c;
int main() {
    cin>>c;
    int cnt=0;
    string res="";
    for (int i=0; i<c.length(); i++) {
        if (cnt==0) {
            if (c[i]!='a') res+=(c[i]-1);
            cnt++;
        } else if (cnt==1) {
            if (c[i]=='z') {
                res+=c[i];
                continue;
            }
            res+=(c[i]+1);
            cnt++;
        } else {
            res+=c[i];
        }
    }
    if (cnt==1) res+='a';
    if (res.length()<0||res.length()>20||res==c) puts("NO");
    else cout<<res<<endl;
}
