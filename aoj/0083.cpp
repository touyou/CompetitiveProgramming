#include <cstdio>
int y, m, d;
int main() {
    while (scanf("%d%d%d",&y,&m,&d)!=EOF) {
        if (y==1868) {
            if (m==9) {
                if (d<8) puts("pre-meiji");
                else printf("meiji 1 %d %d\n",m,d);
            } else if (m < 9) {
                puts("pre-meiji");
            } else {
                printf("meiji 1 %d %d\n",m,d);
            }
        } else if (y < 1868) {
            puts("pre-meiji");
        } else if (y>1868&&y<1912) {
            printf("meiji %d %d %d\n",y-1868+1,m,d);
        } else if (y==1912) {
            if (m==7) {
                if (d<30) printf("meiji %d %d %d\n",y-1868+1,m,d);
                else printf("taisho 1 %d %d\n",m,d);
            } else if (m<7) {
                printf("meiji %d %d %d\n",y-1868+1,m,d);
            } else {
                printf("taisho 1 %d %d\n",m,d);
            }
        } else if (y>1912&&y<1926) {
            printf("taisho %d %d %d\n",y-1912+1,m,d);
        } else if (y==1926) {
            if (m==12) {
                if (d<25) printf("taisho %d %d %d\n",y-1912+1,m,d);
                else printf("showa 1 %d %d\n",m,d);
            } else if (m<12) {
                printf("taisho %d %d %d\n",y-1912+1,m,d);
            } else {
                printf("showa 1 %d %d\n",m,d);
            }
        } else if (y>1926&&y<1989) {
            printf("showa %d %d %d\n",y-1926+1,m,d);
        } else if (y==1989) {
            if (m==1) {
                if (d<8) printf("showa %d %d %d\n",y-1926+1,m,d);
                else printf("heisei 1 %d %d\n",m,d);
            } else {
                printf("heisei 1 %d %d\n",m,d);
            }
        } else {
            printf("heisei %d %d %d\n",y-1989+1,m,d);
        }
    }
}
