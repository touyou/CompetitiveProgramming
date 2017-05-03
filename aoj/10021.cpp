// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=10021
// 一応通してなかったので埋めたパート２。後からソートするのではなく順次更新という形にした。
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    scanf("%d",&n);
    string res = "";
    for (int i=0; i<n; i++) {
        cin >> s;
        if (res == "" || res > s) res = s;
    }
    cout << res << endl;
}
