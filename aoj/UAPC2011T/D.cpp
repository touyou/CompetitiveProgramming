/* x */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
void solve(vvi day, int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=n-1; j>i; j--) {
			if (day[0][j-1]>day[0][j]) {
				swap(day[0][j-1],day[0][j]); swap(day[1][j-1],day[1][j]); swap(day[2][j-1],day[2][j]);
			} else if (day[0][j-1]==day[0][j]) {
				if (day[1][j-1]>day[1][j]) {
					swap(day[0][j-1],day[0][j]); swap(day[1][j-1],day[1][j]); swap(day[2][j-1],day[2][j]);
				} else if (day[1][j-1]==day[1][j]) {
					if (day[2][j-1]>day[2][j]) {
						swap(day[0][j-1],day[0][j]); swap(day[1][j-1],day[1][j]); swap(day[2][j-1],day[2][j]);
					}
				}
			}
		}
	}
	for (int i=0; i<n; i++) {
		char res[10];
		sprintf(res, "%4d %2d %2d",day[0][i],day[1][i],day[2][i]);
		if (res[5] == ' ') res[5] = '0';
		if (res[8] == ' ') res[8] = '0';
		cout << res << endl;
	}
}

int main() {
	int N;
	while (cin >> N&&N!=0) {
		vi y(N), m(N), d(N);
		for (int i=0; i<N; i++) cin >> y[i] >> m[i] >> d[i];
		vvi day(3); day[0]=y; day[1]=m; day[2]=d;
		solve(day,N);
	}
}
