#include <cstdio>
int e[6], b, l[6];
int main() {
    for (int i=0; i<6; i++) {
        scanf("%d",&e[i]);
    }
    scanf("%d",&b);
    for (int i=0; i<6; i++) {
        scanf("%d",&l[i]);
    }
    int cnt=0, j=0;
    for (int i=0; i<6; i++) {
        for (; j<6; j++) {
            if (e[i]==l[j]) {
                cnt++;
                break;
            } else if (e[i]<l[j]) {
                break;
            }
        }
    }
    if (cnt==6) {
        puts("1");
    } else if (cnt==5) {
        bool flag=false;
        for (int i=0; i<6; i++) if (l[i]==b) flag=true;
        if (flag) puts("2");
        else puts("3");
    } else if (cnt==4) {
        puts("4");
    } else if (cnt==3) {
        puts("5");
    } else {
        puts("0");
    }
}