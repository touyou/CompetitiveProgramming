#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#define inf INT_MAX/2
using namespace std;
struct bus {
    double t, v;
    double cost, time;
};
bus bus[100000];
int main() {
    int n, a, d; scanf("%d%d%d",&n,&a,&d);
    double fastest=0.0;
    double x, y;
    for (int i=0; i<n; i++) {
        scanf("%lf%lf",&bus[i].t,&bus[i].v);
        x=(d-bus[i].v*bus[i].v/(2.0*a))/bus[i].v;  // 速度限界に到達する地点からゴールまでにかかる時間
        y=bus[i].t+(bus[i].v/a)+x;
        if (x<0) {                                  // 速度限界に達する前にゴール
            y=bus[i].t+sqrt(2.0*d/(double)a);
        }
        if (fastest<=y) fastest=y;
        printf("%.10f\n",fastest);
    }
}
