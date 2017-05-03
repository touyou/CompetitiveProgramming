#include <cstdio>
#include <cmath>
// v1 = Vs cos(wt)
// v2 = Vr cos(wt+q)
// v2 = iR
// i = C d/dt (v1 - v2)
// i = C (Vs cos(wt) - Vr cos(wt+q))'
// i = -C*(Vs*w sin(wt) - Vr*w sin(wt+q))
// -R*C*Vs*w*sin(wt) + R*C*Vr*w*sin(wt+q) = Vr*cos(wt+q)
int main() {
    double Vs,R,C,w;
    int n;
    scanf("%lf%lf%lf%d",&Vs,&R,&C,&n);
    for (int ix=0; ix<n; ix++) {
        scanf("%lf",&w);
        double f=R*C*w;
        printf("%.3f\n",Vs*f/sqrt(f*f+1));
    }
}
