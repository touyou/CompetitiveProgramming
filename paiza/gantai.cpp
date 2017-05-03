#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool exit[1001];
vector<int> list;
int n, m1, m2;
int x;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) exit[i+1] = false;
    scanf("%d", &m1);
    for (int i=0; i<m1; i++) {
        scanf("%d", &x);
        exit[x] = true;
    }
    scanf("%d", &m2);
    for (int i=0; i<m2; i++) {
        scanf("%d", &x);
        if (!exit[x]) list.push_back(x);
    }
    sort(list.begin(), list.end());
    if (list.size() == 0) printf("None\n");
    else {
        for (int i=0; i<list.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", list[i]);
        }
        puts("");
    }
}

