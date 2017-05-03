#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
string s;
int n;
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        cin>>s;
        for (int j=0; j<s.size(); j++) {
            if (isupper(s[j])) s[j]=tolower(s[j]);
        }
        cout<<s<<endl;
    }
}
