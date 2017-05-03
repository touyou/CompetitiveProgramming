#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> p(n),a(n/2),b(n/2);
	int A=0,B=0;
	for (int i=0; i<n; i++) cin >> p[i];
	a[0] = 1;
	A += p[0];
	for (int i=0; i<n; i++) {
		if (i+1<n&&p[i]>p[i+1]) {
			if (A>B) {
				
			}
		}
	}
	if (n%2==1) {
		if (A>B) B += p[n-1];
		else A += p[n-1];
		
	}
	cout << max(A,B) << endl;
	for (int i=0; i<n/2; i++) {
		cout << a[i] << " " << b[i] << endl;
	}
}
