#include <cstdio>
#include <iostream>
using namespace std;
int a[101], b[101];
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        string str; cin>>str;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&a[i],&b[i]);
            a[i]--; b[i]--;
        }
        for (int i=n-1; i>=0; i--) {
            int diff=(b[i]-a[i])%26;
            char c1, c2;
            if (str[a[i]]+diff>'z') c1=str[a[i]]+diff-26;
            else c1=str[a[i]]+diff;
            if (str[b[i]]+diff>'z') c2=str[b[i]]+diff-26;
            else c2=str[b[i]]+diff;
            str[a[i]]=c2; str[b[i]]=c1;
        }
        cout<<str<<endl;
    }
}
