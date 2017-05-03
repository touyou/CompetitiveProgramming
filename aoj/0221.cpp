#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m,n;
    while (scanf("%d%d",&m,&n)) {
        vector<int> play(m, 0);
        vector<string> ans(n);
        for (int i=1; i<=n; i++) {
            if (i%5==0&&i%3==0) ans[i-1]="FizzBuzz";
            else if (i%5==0) ans[i-1]="Buzz";
            else if (i%3==0) ans[i-1]="Fizz";
            else ans[i-1]=i;
        }
        string s;
        int p=0;
        for (int i=0; i<n; i++) {
            cin>>s;
            while (play[p]==1) {
                p++;
                if (p==m) p=0;
            }
            if (s!=ans[i]) play[p]=1;
            p++;
        }
        bool first=true;
        for (int i=0; i<m; i++) {
            if (play[i]==1) continue;
            if (first) {
                printf("%d",i+1);
                first=false;
                continue;
            }
            printf(" %d",i+1);
        }
        printf("\n");
    }
    return 0;
}

