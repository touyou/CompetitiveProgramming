#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char s[1000000];

bool C(int x) {
    bool used[1000000];
    memset(used, 0, sizeof(used));
    vector<int> J, O, I;
    for (int i=n-1; i>=0&&I.size()<x; i--) {
        if (s[i]=='I') {
            I.push_back(i);
            used[i] = true;
        }
    }
    if (I.size()<x) return false;
    int a = 0;
    for (int i=n-1; i>=0&&O.size()<x; i--) {
        if (s[i]=='O'&&I[a]>i) {
            O.push_back(i);
            used[i] = true;
            a++;
        }
    }
    if (O.size()<x) return false;
    int b = 0;
    for (int i=n-1; i>=0&&J.size()<x; i--) {
        if (s[i]=='I'&&!used[i]&&O[b]>i) {
            J.push_back(i);
            used[i] = true;
            b++;
        } else if (s[i]=='J'&&O[b]>i) {
            J.push_back(i);
            used[i] = true;
            b++;
        }
    }
    if (J.size()<x) return false;
    return true;
}
int main() {
    scanf("%d%s",&n,s);
    int lb=0, ub=n+1;
    while (ub-lb>1) {
        int mid = (ub + lb) / 2;
        if (C(mid)) lb = mid;
        else ub = mid;
    }
    printf("%d\n", lb);
}