#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
/*int sum1[100001], sum2[100001];
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
    int res=100001, sz=tempo.size(), s1=1, s2=1;
    if (sz==1) {
        puts("0");
        return 0;
    }
    sum1[0]=tempo[0];
    for (int i=2; i<sz; i+=2) {
        sum1[s1]=sum1[s1-1]+tempo[i]; s1++;
    }
    sum2[0]=tempo[1];
    for (int i=3; i<sz; i+=2) {
        sum2[s2]=sum2[s2-1]+tempo[i]; s2++;
    }
    for (int i=0; i<sz; i++) {
        int x=0;
        if (i&1) {
            x+=sum2[s2-1]-sum2[i/2];
            x+=sum1[i/2];
        } else {
            x+=sum1[s1-1]-sum1[i/2];
            if (i!=0) x+=sum2[(i-1)/2];
        }
        bool f=(i&1)?!ini:ini, e=(i%2==(sz-1)%2)?!eni:eni;
        if (!f&&e) continue;
        res=min(res, x);
    }
    printf("%d\n",res);
}*/
int main() {
    string str; cin>>str;
    int len=str.length(), uc=0, ub=0, lc=0, lb=0;
    for (int i=0; i<len; i++) {
        if (isupper(str[i])) uc++;
        else lc++;
    }
    int res=min(uc,lc);
    for (int i=0; i<len; i++) {
        if (isupper(str[i])) ub++;
        else lb++;
        res=min(res,lb+uc-ub);
    }
    printf("%d\n",res);
}