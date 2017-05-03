#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define EPS 1e-9
using namespace std;
string str;
int w[10], s[10];
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (n==0) break;
        string h[n];
        int perm[n];
        for (int i=0; i<n; i++) {
            cin>>str>>w[i]>>s[i];
            h[i]=str;
            perm[i]=i;
        }
        double G=INT_MAX/2.0;
        string res[n];
        do {
            int sum=w[perm[0]];
            bool flag=true;
            for (int i=1; i<n; i++) {
                int x=perm[i];
                if (s[x]<sum) {
                    flag=false;
                    break;
                }
                sum+=w[x];
            }
            if (flag) {
                int sum2=0;
                for (int i=0; i<n; i++) sum2+=(n-i)*w[perm[i]];
                if (G-EPS>(double)sum2/(double)sum) {
                    G=(double)sum2/(double)sum;
                    for (int i=0; i<n; i++) res[i]=h[perm[i]];
                }
            }
        } while (next_permutation(perm, perm+n));
        for (int i=n-1; i>=0; i--) cout<<res[i]<<endl;
    }
}
