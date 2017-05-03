#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n;
string s[1000], t[50];
int main() {
    int x=0;
    string str;
    getline(cin, str);
    string tmp="";
    for (int i=0; i<str.length(); i++) {
        if (str[i]==' ') {
            s[x++] = tmp;
            tmp="";
        } else {
            tmp+=str[i];
        }
    }
    s[x++] = tmp;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>t[i];
        for (int j=0; j<x; j++) {
            if (t[i].length()!=s[j].length()) continue;
            bool flag=true;
            for (int k=0; k<t[i].length()&&flag; k++) {
                if (t[i][k]!='*'&&t[i][k]!=s[j][k]) flag=false;
            }
            if (flag) {
                for (int k=0; k<s[j].length(); k++) s[j][k]='*';
            }
        }
    }
    cout<<s[0];
    for (int i=1; i<x; i++) cout<<" "<<s[i];
    cout<<endl;
}
