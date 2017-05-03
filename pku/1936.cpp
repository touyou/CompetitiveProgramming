#include <iostream>
using namespace std;

int main() 
{
    string s,t;
    while (cin>>s>>t) {
        int spos = 0, tpos, slen = s.length(), tlen = t.length();
        for (tpos=0; tpos<tlen; tpos++) {
            if (s[spos] == t[tpos]) spos++;
        }
        if (spos == slen) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

