#include <cmath>
#define EPS 1e-10
struct P {
    double x, y;
    P () {}
    P (double x, double y) : x(x), y(y) {}
    double add(double a, double b) {
        if (abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
        return a+b;
    }
    P operator + (P p) {
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p) {
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (P p) {
        return P(x*d,y*d);
    }
    double dot(P p) {
        return add(x*p.x, y*p.y);
    }
    double det(P p) {
        return add(x*p.y, -y*p.x);
    }
};
