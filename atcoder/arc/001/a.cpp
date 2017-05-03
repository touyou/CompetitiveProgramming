#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int main() {
    int n; scanf("%d",&n);
    string c; cin>>c;
    P cnt[4];
    for (int i=0; i<4; i++) cnt[i]=P(0,i+1);
    int len=c.length();
    for (int i=0; i<len; i++) {
        cnt[c[i]-'1'].first++;
    }
    sort(cnt, cnt+4);
    printf("%d %d\n",cnt[3].first,cnt[0].first);
}