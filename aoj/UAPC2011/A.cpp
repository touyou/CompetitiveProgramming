#include <cstdio>
#include <iostream>
using namespace std;
/*
昼は11:00 ~ 14:59,
夕は18:00~20:59,
深夜は21:00~翌01:59
*/
int main() {
	int n;
	while (scanf("%d",&n)&&n!=0) {
		int lcnt=0,dcnt=0,mcnt=0,lok=0,dok=0,mok=0;
		for (int i=0; i<n; i++) {
			int h,t,e; scanf("%d%*c%d%d",&h,&t,&e);
			int lag = e-t;
			if (lag<0) lag += 60;
			if (11<=h&&h<=14) {
				if (lag <= 8) lok++;
				lcnt++;
			} else if (18<=h&&h<=20) {
				if (lag <= 8) dok++;
				dcnt++;
			} else if (21<=h||h<=1) {
				if (lag <= 8) mok++;
				mcnt++;
			}
		}
		if (lcnt==0) {
			cout << "lunch no guest" << endl;
		} else {
			double res = (double)lok*100/(double)lcnt;
			printf("lunch %d\n",(int)res);
		}
		if (dcnt==0) {
			cout << "dinner no guest" << endl;
		} else {
			double res = (double)dok*100/(double)dcnt;
			printf("dinner %d\n",(int)res);
		}
		if (mcnt==0) {
			cout << "midnight no guest" << endl;
		} else {
			double res = (double)mok*100/(double)mcnt;
			printf("midnight %d\n",(int)res);
		}
	}
}
