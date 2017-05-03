#include <cstdio>
#include <algorithm>
using namespace std;
int n, dig[100000];
int main() {
    bool flag=false;
    scanf("%d",&n);
    int sum=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&dig[i]);
        sum+=dig[i];
        if (dig[i]==0) flag=true;
    }
    if (!flag) {
        puts("-1");
        return 0;
    }
    sort(dig, dig+n);
    if (dig[n-1]==0) puts("0");
    else {
        if (sum%3==0) {
            for (int i=n-1; i>=0; i--) printf("%d",dig[i]);
            puts("");
        } else if (sum%3==1) {
            int a=-1;
            for (int i=0; i<n; i++) {
                if (dig[i]%3==sum%3) {
                    a=dig[i];
                    break;
                }
            }
            if (a==-1) {
                int cnt=0;
                for (int i=0; i<n&&cnt<2; i++) {
                    if (dig[i]%3==2) {
                        dig[i]=-1;
                        cnt++;
                    }
                }
            } else {
                for (int i=0; i<n; i++) {
                    if (dig[i]==a) {
                        dig[i]=-1;
                        break;
                    }
                }
            }
            flag=false;
            for (int i=0; i<n; i++) {
                if (dig[i]!=0&&dig[i]!=-1) flag=true;
            }
            if (!flag) puts("0");
            else {
                for (int i=n-1; i>=0; i--) if (dig[i]!=-1) printf("%d",dig[i]);
                puts("");
            }
        } else {
            int a=-1;
            for (int i=0; i<n; i++) {
                if (dig[i]%3==sum%3) {
                    a=dig[i];
                    break;
                }
            }
            if (a==-1) {
                int cnt=0;
                for (int i=0; i<n&&cnt<2; i++) {
                    if (dig[i]%3==1) {
                        dig[i]=-1;
                        cnt++;
                    }
                }
            } else {
                for (int i=0; i<n; i++) {
                    if (dig[i]==a) {
                        dig[i]=-1;
                        break;
                    }
                }
            }
            flag=false;
            for (int i=0; i<n; i++) {
                if (dig[i]!=0&&dig[i]!=-1) flag=true;
            }
            if (!flag) puts("0");
            else {
                for (int i=n-1; i>=0; i--) if (dig[i]!=-1) printf("%d",dig[i]);
                puts("");
            }
        }
    }
}