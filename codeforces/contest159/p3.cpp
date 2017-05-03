#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef vector<int> vi;
map<char, vi> hash;
bool use[100][2000];
int main() {
    int k; scanf("%d",&k);
    string str; cin>>str;
    string res="";
    int n; scanf("%d",&n);
    int len=str.length();
    for (int i=0; i<len; i++) hash[str[i]].push_back(i);
    for (int i=0; i<len; i++) for (int j=0; j<k; j++) use[i][j]=true;
    for (int i=0; i<n; i++) {
        int p; char c; scanf("%d",&p); cin>>c;
        int sz=hash[c].size();
        int cnt=0;
        for (int j=0; j<k; j++) {
            bool flag=false;
            for (int l=0; l<sz; l++) {
                int h=hash[c][l];
                if (use[h][j]) cnt++;
                if (cnt==p) {
                    use[h][j]=false;
                    flag=true;
                    break;
                }
            }
            if (flag) break;
        }
    }
    for (int j=0; j<k; j++) {
        for (int i=0; i<len; i++) {
            if (use[i][j]) res+=str[i];
//            printf("%c%c",use[i][j]?'*':'-',str[i]);
        }
    }
    cout<<res<<endl;
}
