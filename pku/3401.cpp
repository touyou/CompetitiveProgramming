#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string s; cin>>s;
    int cnt=0, res=0, len=s.length();
    char bef='*';
    for (int i=0; i<len; i++) {
        if (bef!=s[i]) {
            res=max(0,cnt-2);
            bef=s[i]; cnt=1;
        } else {
            cnt++;
        }
    }
    res+=max(0,cnt-2);
    printf("%d\n",len-res);
}
