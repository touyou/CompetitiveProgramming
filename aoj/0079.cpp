// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0079
// 一個の頂点を起点に三角形の面積をもとめて足し合わせる
// やるだけ
#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> P;
double x, y;
double S, z;
vector<P> points;
int main() {
    while (~scanf("%lf,%lf",&x,&y)) {
        points.push_back(P(x,y));
    }
    S = 0.0;
    for (int i=1; i<points.size()-1; i++) {
        double a=sqrt(pow(points[0].first-points[i].first,2.0)+
                pow(points[0].second-points[i].second,2.0));
        double b=sqrt(pow(points[i].first-points[i+1].first,2.0)+
                pow(points[i].second-points[i+1].second,2.0));
        double c=sqrt(pow(points[i+1].first-points[0].first,2.0)+
                pow(points[i+1].second-points[0].second,2.0));
        z = (a+b+c)/2;
        S += sqrt(z*(z-a)*(z-b)*(z-c));
    }
    printf("%.6f\n",S);
}
