#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	double a;
	while (cin>>a) {
		double s[10], res=a;
		s[0]=a;
		for (int i=1; i<10; i++) {
			if (i%2==0) {
				s[i]=s[i-1]/3.0;
			} else {
				s[i]=s[i-1]*2.0;
			}
			res+=s[i];
		}
		printf("%.8f\n",res);
	}
}
