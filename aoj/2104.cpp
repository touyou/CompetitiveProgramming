// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2104
// 発電機がk個あればk-1個の空白があってよいので家の間の距離をすべてリストアップし長いところk-1個を空白区間にした
// またkがnより大きい場合は各家庭に一個発電機が置けるので例外にした。
#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int x[100000];
int main() {
    scanf("%d", &t);
    for (int c=0; c<t; c++) {
        scanf("%d%d",&n,&k);
        for (int i=0; i<n; i++) scanf("%d",&x[i]);
        if (n <= k) {
            puts("0");
            continue;
        }
        vector<int> lines;
        for (int i=1; i<n; i++) lines.push_back(x[i]-x[i-1]);
        sort(lines.begin(), lines.end());
        int res = 0;
        for (int i=0; i<lines.size()-k+1; i++) res += lines[i];
        printf("%d\n",res);
    }
}
