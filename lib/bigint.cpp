#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string ret;
string add(const string &a, const string &b) {
    ret="";
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
    reverse(ret.begin(), ret.end());
    return ret;
}
string dec(const string &a, const string &b) {
    ret="";
    int as=a.size(),bs=b.size();
    int c=0;
    for (int i=0; i<max(as,bs); i++) {
        int t=c;
        if (i<as) t+=a[as-i-1]-'0';
        if (i<bs) t-=b[bs-i-1]-'0';
        if (t<0) {
            c=-1;
            t+=10;
        } else {
            c=0;
        }
        ret+=t+'0';
    }
    if (c<0) ret+='-';
    reverse(ret.begin(), ret.end());
    return ret;
}
string mul(const string &a, const string &b) {
    ret="";
    int as=a.size(),bs=b.size();
    int c=0;
}
void test(string a, string b) {
    cout << "a+b: " << add(a,b) << endl;
    cout << "a-b: " << dec(a,b) << endl;
}
int main() {
    string a, b;
    cin>>a>>b;
    test(a,b);
}
