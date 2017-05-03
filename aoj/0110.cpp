#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
string num[3], num2[3];
bool add(string a, string b, string res) {
    //if (a[0]=='0'||b[0]=='0'||res[0]=='0') return false;
    string ret="";
    int as=a.size(),bs=b.size();
    int c=0;
    for (int i=0; i<max(as,bs); i++) {
        int t=c;
        if (i<as) t+=a[as-i-1]-'0';
        if (i<bs) t+=b[bs-i-1]-'0';
        c=t/10;
        t%=10;
        ret+=t+'0';
    }
    if (c) ret+='1';
    reverse(ret.begin(), ret.end());
    return ret==res;
}
int main() {
    string alpha;
    while (cin>>alpha) {
        num[0]=""; num[1]=""; num[2]="";
        int pos=0;
        for (int i=0; i<alpha.length(); i++) {
            if (alpha[i]=='+'||alpha[i]=='=') {
                pos++;
            } else {
                num[pos]+=alpha[i];
            }
        }
        int res=-1;
        for (int i=0; i<=9; i++) {
            num2[0]=num[0]; num2[1]=num[1]; num2[2]=num[2];
            for (int j=0; j<3; j++) {
                for (int k=0; k<num2[j].length(); k++) {
                    if (num2[j][k]=='X') num2[j][k]=(i+'0');
                }
            }
            if (add(num2[0],num2[1],num2[2])) {
                res=i;
            }
        }
        if (res==-1) puts("NA");
        else printf("%d\n",res);
    }
}
