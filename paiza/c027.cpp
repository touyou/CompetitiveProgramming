// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

string bs, bs1, bs2, a[100];
int n, b, b1, b2;

int main() {
    cin>>b>>n;
    b1 = b + 1; b2 = b - 1;
    bs = to_string(b); bs1 = to_string(b1); bs2 = to_string(b2);
    reverse(bs.begin(), bs.end());
    reverse(bs1.begin(), bs1.end());
    reverse(bs2.begin(), bs2.end());
    for (int i=0; i<n; i++) {
        cin>>a[i];
        reverse(a[i].begin(), a[i].end());
    }
    for (int i=0; i<n; i++) {
        if (a[i] == bs) {
            printf("first\n");
        } else if (a[i] == bs1 || a[i] == bs2) {
            printf("adjacent\n");
        } else {
            for (int j=0; j<bs.length(); j++) {
                if (bs[j] != a[i][j]) {
                    if (j == 4) printf("second\n");
                    else if (j == 3) printf("third\n");
                    else printf("blank\n");
                    break;
                }
            }
        }
    }
}
