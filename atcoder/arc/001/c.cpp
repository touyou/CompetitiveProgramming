#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ok=true;
vector<string> mp(8);
int row[8], col[8], dia[2][15];
void dfs(int c) {
    if (ok&&c==8) {
        for (int i=0; i<8; i++) cout<<mp[i]<<endl;
        ok=false;
        return;
    }
    if (col[c]>0) {
        dfs(c+1);
        return;
    }
    col[c]++;
    for (int i=0; i<8; i++) {
        if (row[i]>0||dia[0][c-i+7]>0||dia[1][c+i]>0) continue;
        mp[c][i]='Q';
        row[i]++; dia[0][c-i+7]++; dia[1][c+i]++;
        dfs(c+1);
        mp[c][i]='.';
        row[i]--; dia[0][c-i+7]--; dia[1][c+i]--;
    }
    col[c]--;
    return;
}
int main() {
    for (int i=0; i<8; i++) {
        cin>>mp[i];
        for (int j=0; j<8; j++) if (mp[i][j]=='Q') {
            row[j]++; col[i]++;
            dia[0][i-j+7]++; dia[1][j+i]++;
        }
    }
    for (int i=0; i<8; i++) if (row[i]>1||col[i]>1) {
        puts("No Answer");
        return 0;
    }
    for (int i=0; i<15; i++) if (dia[0][i]>1||dia[1][i]>1) {
        puts("No Answer");
        return 0;
    }
    dfs(0);
    if (ok) puts("No Answer");
}