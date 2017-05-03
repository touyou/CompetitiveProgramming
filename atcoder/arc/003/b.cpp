#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s[100];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        string in; cin>>in;
        reverse(in.begin(), in.end());
        s[i]=in;
    }
    sort(s, s+n);
    for (int i=0; i<n; i++) {
        reverse(s[i].begin(), s[i].end());
        cout<<s[i]<<endl;
    }
}