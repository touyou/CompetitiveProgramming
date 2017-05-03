#include <cstdio>
int y, m, d;
int day1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int day2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
bool isreep(int y) {
    if (y%100==0&&y%400!=0) return false;
    if (y%4==0) return true;
    return false;
}
void next() {
    d++;
    if (isreep(y)) {
        if (day2[m-1]>=d) return;
        m++; d=1;
        if (m==13) { m=1; y++; }
    } else {
        if (day1[m-1]>=d) return;
        m++; d=1;
        if (m==13) { m=1; y++; }
    }
}
bool ok() {
    if ((double)y/(double)m/(double)d==y/m/d) return true;
    return false;
}
int main() {
    scanf("%d/%d/%d",&y,&m,&d);
    while (!ok()) next();
    printf("%d/%02d/%02d\n",y,m,d);
}