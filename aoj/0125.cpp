#include <cstdio>
int y1, m1, d1, y2, m2, d2;
int day[2][12]={
{31,28,31,30,31,30,31,31,30,31,30,31},
{31,29,31,30,31,30,31,31,30,31,30,31}
};
bool uruu(int year) {
    if (year%400==0) return true;
    else if (year%100==0) return false;
    else if (year%4==0) return true;
    else return false;
}
int main() {
    while (scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2)) {
        if (y1==-1&&m1==-1&&d1==-1&&y2==-1&&m2==-1&&d2==-1) break;
        long long res = 0, flag;
        if (y1==y2) {
            if (uruu(y1)) flag = 1;
            else flag = 0;
            if (m1==m2) res = d2-d1;
            else {
                for (int i=m1; i<m2-1; i++) res += day[flag][i];
                res += day[flag][m1-1] - d1;
                res += d2;
            }
        } else {
            if (uruu(y1)) flag = 1;
            else flag = 0;
            for (int i=m1; i<12; i++) res += day[flag][i];
            res += day[flag][m1-1] - d1;
            if (y1+1<y2) for (int i=y1+1; i<y2; i++) {
                if (uruu(i)) res += 366;
                else res += 365;
            }
            if (uruu(y2)) flag = 1;
            else flag = 0;
            for (int i=0; i<m2-1; i++) res += day[flag][i];
            res += d2;
        }
        printf("%lld\n", res);
    }
}
