#include <cstdio>
typedef long long ll;
ll gcd(ll a, ll b) {
	if (a == 1 || a == -1 || b == 1 || b == -1) return 1;
	return b?gcd(b,b%a):a;
}
int main() {
	ll x, y, m, n, l;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	// ll xy = (x - y) % l;
	// if (xy % gcd(m-n,l)!=0) {
		// printf("Impossible\n");
		// return 0;
	// }
	// int k;
	// for (k=1;;k++) if ((l*k-xy)%(m-n)==0&&(l*k-xy)/(m-n)>=0) break;
	// printf("%lld\n", (l*k-xy)/(m-n));
	if ((-x+y)%gcd(m-n,l)!=0) {
		printf("Impossible\n");
		return 0;
	}
	int k;
	for (k=1;;k++) if ((l*k-x+y)%(m-n)==0) if ((l*k-x+y)/(m-n)>=0) break;
	printf("%lld\n", (l*k-x+y)/(m-n));
}

/*
t回繰り返したものを f1(t), f2(t)とすると
 f1(t) = (f1(t-1) + m) mod l ただし f(0) = x
 f2(t) = (f2(t-1) + n) mod l ただし f(0) = y
これをほどく。
 f1(t) = (...((((((x+m)%l)+m)%l)+m)%l)+...+m)%l
       = (x + t * m) mod l
同様に
 f2(t) = (y + t * n) mod l
だからこれをtにおける方程式にすると
     (x + t * m) mod l = (y + t * n) mod l
 x mod l + t * m mod l = y mod l + t * n mod l
     x mod l - y mod l = t * m mod l - t * n mod l
         (x - y) mod l = t(m - n) mod l
???????????????????????????????????????????
(x - y) mod lは求められるから、その値をxyと置くと
 xy = t(m - n) mod l
つまり
 xy + t(m - n) = lk (aは正数)
             t = (lk - xy) / (m - n)
			   = l / (m - n) * k - xy / (m - n)
???????????????????????????????????????????
 (m - n)t - Lk = -x + y
だから
 t = (Lk - x + y) / (m - n)
*/