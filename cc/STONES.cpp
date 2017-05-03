#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool used[1001];
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        string J, S; cin>>J>>S;
        memset(used, 0, sizeof(used));
        int res=0;
        for (int i=0; i<J.length(); i++) {
            for (int j=0; j<S.length(); j++) {
                if (used[j]) continue;
                if (J[i]==S[j]) {
                    res++;
                    used[j]=true;
                    break;
                }
            }
        }
        printf("%d\n",res);
    }
}