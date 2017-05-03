#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() 
{
    int H, W;
    cin >> H >> W;
    vector<string> map(H);
    for (int i=0; i<H; i++) cin >> map[i];
    vector<vector<int> > dp(H, vector<int>(W, 0));
    for (int i=1; i<W; i++) dp[0][i] = (map[0][i]-'0') + dp[0][i-1];
    for (int i=1; i<H; i++) {
        dp[i][0] = (map[i][0]-'0') + dp[i-1][0];
        for (int j=1; j<W; j++) {
            dp[i][j] = (map[i][j]-'0') + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[H-1][W-1] << endl;
}

