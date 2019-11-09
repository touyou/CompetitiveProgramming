#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
string solve(int n, string res) {
	if (n==0) return "0";
	if (n==1) return "1"+res;
	if (n%2==0) {
		res = solve(n/-2, "0"+res);
	} else {
		res = solve((n-1)/-2, "1"+res);
	}
	return res;
}
int main() {
	int n;
	scanf("%d",&n);
	cout << solve(n, "") << endl;
}