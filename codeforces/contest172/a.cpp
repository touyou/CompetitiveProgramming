#include <iostream>
#include <cstdio>
using namespace std;
string str[30000];
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) cin>>str[i];
    int res, len=str[0].length();
    for (res=0; res<len; res++) {
        bool flag=true;
        char c=str[0][res];
        for (int i=1; i<n; i++) {
            if (c!=str[i][res]) {
                flag=false;
                break;
            }
        }
        if (!flag) break;
    }
    printf("%d\n",res);
}
