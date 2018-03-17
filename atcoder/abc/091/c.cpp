#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
pi red[100], blue[100];
int table[100][100];
bool used[100];
bool custom(pi l, pi r) {
    if (l.first == r.first) return l.second > r.second;
    else return l.first < r.first;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        red[i] = pi(x, y);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        blue[i] = pi(x, y);
    }
    int res = 0;
    vector<pi> xdata, ydata;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (red[i].first < blue[j].first && red[i].second < blue[j].second) table[i][j] = 1;
            cnt += table[i][j];
        }
        xdata.push_back(pi(cnt, i));
    }
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += table[i][j];
        ydata.push_back(pi(cnt, j));
    }
    sort(xdata.begin(), xdata.end());
    sort(ydata.begin(), ydata.end());
    for (int i = 0; i < n; i++) {
        int xpos = xdata[i].second;
        for (int j = 0; j < n; j++) {
            int ypos = ydata[j].second;
            if (!used[ypos] && table[xpos][ypos] == 1) {
                used[ypos] = true;
                res++;
                break;
            }
        }
    }
    sort(ydata.begin(), ydata.end(), custom);
    for (int i = 0; i < n; i++) used[i] = false;
    int res2 = 0;
    for (int i = 0; i < n; i++) {
        int xpos = xdata[i].second;
        for (int j = 0; j < n; j++) {
            int ypos = ydata[j].second;
            if (!used[ypos] && table[xpos][ypos] == 1) {
                used[ypos] = true;
                res2++;
                break;
            }
        }
    }
    printf("%d\n", max(res, res2));
}
