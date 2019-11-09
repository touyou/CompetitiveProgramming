#include <cstdio>
typedef long long ll;
ll a,b;
int main() {
  scanf("%lld%lld",&a,&b);
  ll c=1, at=a, bt=b;
  while (at-c>=0) {
	at-=c;
	++c;
  }
  ll ai = (at==0?1:c-at+1), bi = (at==0?c-1:at);
  //printf("%lld %lld %lld\n",ai,bi,c);
  c=1;
  while (bt-c>=0) {
	bt-=c;
	c++;
  }
  ll aj = (bt==0?1:c-bt+1), bj = (bt==0?c-1:bt);
  //printf("%lld %lld %lld\n",aj,bj,c);
  ll x=ai+aj, y=bi+bj;
  ll z=x+y-1;
  ll ret=0;
  for (ll i=1; i<z; i++) ret+=i;
  printf("%lld\n",ret+y);
}
