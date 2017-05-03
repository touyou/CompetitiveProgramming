#include <cstdio>
int main() {
    int b,r,g,c,s,t;
    while (scanf("%d%d%d%d%d%d",&b,&r,&g,&c,&s,&t)) {
        if (!b&&!r&&!g&&!c&&!s&&!t) break;
        int res=100+12*(b+r)+13*(b*5+r*3)-c+4*g;
        t-=b*6+r*4+c+g+s;
        printf("%d\n",res-t*3);
    }
}
