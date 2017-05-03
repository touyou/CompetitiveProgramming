#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// "H-1A-2C-3K-4E-5R-6C-3U-7P-8"
int main() {
    int t; cin >> t;
    int cnt[8];
    string temp; getline(cin, temp);
    for (int ix=1; ix<=t; ix++) {
        string line; getline(cin, line);
        fill(cnt, cnt+8, 0);
        for (int i=0; i<line.length(); i++) {
            if (line[i]=='H') cnt[0]++;
            if (line[i]=='A') cnt[1]++;
            if (line[i]=='C') cnt[2]++;
            if (line[i]=='K') cnt[3]++;
            if (line[i]=='E') cnt[4]++;
            if (line[i]=='R') cnt[5]++;
            if (line[i]=='U') cnt[6]++;
            if (line[i]=='P') cnt[7]++;
        }
        int res=1001;
        for (int i=0; i<8; i++) {
            if (i==2) res=min(res,cnt[2]/2);
            else res=min(res,cnt[i]);
        }
        cout << "Case #" << ix << ": " << res << endl;
    }
}
