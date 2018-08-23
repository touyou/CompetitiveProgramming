#include <bits/stdc++.h>
using namespace std;

int main() {
    int mp[100][100];
    int w, h, n; scanf("%d%d%d", &w, &h, &n);
    for (int y = 0; y < h; y++) for (int x = 0; x < w; x++) mp[y][x] = 1;
    for (int i = 0 ; i < n; i++) {
        int xi, yi, ai; scanf("%d%d%d", &xi, &yi, &ai);
        switch (ai) {
        case 1:
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < xi; x++) {
                    mp[y][x] = 0;
                }
            }
            break;
        case 2:
            for (int y = 0; y < h; y++) {
                for (int x = xi; x < w; x++) {
                    mp[y][x] = 0;
                }
            }
            break;
        case 3:
            for (int y = 0; y < yi; y++) {
                for (int x = 0; x < w; x++) {
                    mp[y][x] = 0;
                }
            }
            break;
        case 4:
            for (int y = yi; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    mp[y][x] = 0;
                }
            }
            break;
        default:
            break;
        }
    }
    int res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            res += mp[y][x];
        }
    }
    printf("%d\n", res);
}
