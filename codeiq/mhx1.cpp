#include "bits/stdc++.h"
using namespace std;
int n;
string q;
int skin, kiba, eye;
int main() {
    scanf("%d", &n);
    cin>>q;
    for (int i=0; i<n; i++) {
        if (q[i] == 'q') {
            skin += 2; kiba += 10; eye += 2;
        } else {
            skin += 8; kiba += 2; eye += 2;
        }
    }
    printf("%d\n", min((int)(skin/5), min((int)(kiba/6), (int)(eye/2))));
}
