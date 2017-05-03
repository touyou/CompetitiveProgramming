#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

/*int solve(int p, int e, int i, int d) {
	const int P=23, E=28, I=33;
	int j;
	/*while (p>d) {
		p-=P;
		if (p<0) {
			p+=P;
			break;
		}
	}
	while (e>d) {
		e-=E;
		if (e<0) {
			e+=E;
			break;
		}
	}
	while (i>d) {
		i-=I;
		if (i<0) {
			i+=I;
			break;
		}
	}
	p%=P; e%=E; i%=I;
	if (p==e&&e==i&&p>d) {
		p-=d;
	} else {
		while (p<=21252) {
			if (p==min(p,min(e,i))) p+=P;
			if (p==e&&e==i&&p>d) {
				p-=d;
				break;
			}
			if (e==min(p,min(e,i))) e+=E;
			if (p==e&&e==i&&p>d) {
				p-=d;
				break;
			}
			if (i==min(p,min(e,i))) i+=I;
			if (p==e&&e==i&&p>d) {
				p-=d;
				break;
			}
		}
	}
	return p;
}
*/
int main() {
	int p,e,i,d;
	int c = 1;
	while (true) {
		cin >> p >> e >> i >> d;
		if (p==-1&&e==-1&&i==-1&&d==-1) break;
		for (int j=1; j<=21252; j++) {
			if ((j+d-p)%23==0&&(j+d-e)%28==0&&(j+d-i)%33==0) {
				printf("Case %d: the next triple peak occurs in %d days.\n",c,j);
				break;
			}
		}
		//int ans = solve(p,e,i,d);
		//printf("Case %d: the next triple peak occurs in %d days.\n",c,ans);
		c++;
	}
	return 0;
}
