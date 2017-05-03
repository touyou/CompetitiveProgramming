#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n; scanf("%d",&n);
    string str; getline(cin,str);
    set<string> log;
    for (int i=0; i<n; i++) {
        getline(cin,str);
        if (log.find(str)!=log.end()) puts("Yes");
        else {
            log.insert(str);
            puts("No");
        }
    }
}
