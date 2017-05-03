#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
bool isr[100001];
int main() {
    string str; cin>>str;
    vector<int> tempo;
    int cnt=1, len=str.length();
    bool isu=false, ini=isupper(str[0]), eni=isupper(str[len-1]);
    if (ini) isu=true;
    for (int i=1; i<len; i++) {
        if (isupper(str[i])==isu) cnt++;
        else {
            tempo.push_back(cnt);
            cnt=1;
            isu=!isu;
        }
    }
    tempo.push_back(cnt);
    int res=100001, sz=tempo.size();
    for (int i=0; i<sz; i++) {
        int x=0;
        memset(isr, 0, sizeof(isr));
        for (int j=i-1; j>=0; j-=2) {
            x+=tempo[j];
            isr[j]=true;
        }
        for (int j=i+2; j<sz; j+=2) {
            x+=tempo[j];
            isr[j]=true;
        }
        bool f=isr[0]?!ini:ini, e=isr[sz-1]?!eni:eni;
        if (!f&&e) continue;
        res=min(res, x);
    }
    printf("%d\n",res);
}