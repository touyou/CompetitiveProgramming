#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, scnt;
string name[20];
int main() {
    scnt = 1;
    while (scanf("%d",&n)) {
        if (!n) break;
        printf("SET %d\n",scnt++);
        for (int i=0; i<n; i++) cin>>name[i];
        vector<string> res;
        for (int i=0; i<n; i+=2) {
            res.push_back(name[i]);
        }
        for (int i=n-1; i>=0; i--) {
            if (i%2) res.push_back(name[i]);
        }
        for (int i=0; i<n; i++) cout<<res[i]<<endl;
    }
}
