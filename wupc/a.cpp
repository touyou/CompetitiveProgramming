#include <cstdio>
int day[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int ma,da,mb,db; scanf("%d%d%d%d",&ma,&da,&mb,&db);
    int res=0;
    if (ma==mb) res=db-da;
    else {
        res+=-da+db;
        for (int i=ma-1; i<mb-1; i++) res+=day[i];
    }
    printf("%d\n",res);
}