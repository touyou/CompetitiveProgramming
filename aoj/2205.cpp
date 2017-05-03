#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
int main() {
    while (cin>>n>>m) {
        if (!n) break;
        string key[n];
        ll score[n];
        for (int i=0; i<n; i++) {
            string str; cin>>str>>score[i];
            key[i]=str;
        }
        ll sum=0;
        for (int i=0; i<m; i++) {
            string str; cin>>str;
            for (int j=0; j<n; j++) {
                int k=0;
                while ((key[j][k]=='*'||key[j][k]==str[k])&&k<8) k++;
                if (k==8) {
                    sum+=score[j];
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
}
