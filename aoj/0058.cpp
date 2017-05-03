#include <cstdio>
int main() {
    double xA,yA,xB,yB,xC,yC,xD,yD;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&xA,&yA,&xB,&yB,&xC,&yC,&xD,&yD)!=EOF) {
        if ((xA-xB)*(xC-xD)+(yA-yB)*(yC-yD)==0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
