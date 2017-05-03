#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
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

int c(int count, int max_k, int max_n, vector<int> log) {
	while (count < max_k) {
		if (log[0] >= 2) {
			count++;
			log[0] -= log[0]/2;
			max_n = max(max_n, count);
			continue;
		}
		if (log[1] >= 2) {
			count++;
			log[1] -= log[1]/2;
			max_n = max(max_n, count);
			continue;
		}
		if (log[2] >= 2) {
			count++;
			log[2] -= log[2]/2;
			max_n = max(max_n, count);
			continue;
		}
		break;
	}
	return max_n;
}
int main() {
	int x,y,z,k;
	cin >> x >> y >> z >> k;
	vector<int> log;
	log.push_back(x); log.push_back(y); log.push_back(z);
	int count = 1, max_n = 0;
	max_n = c(count, k, max_n, log);
	int ans = (int) pow(2, max_n); 
	cout << max_n << endl;
	return 0;
}

/*
x,y,z,k = map(int,raw_input().split())
x,y,z = sorted((x,y,z))
kx = min(x-1,k/3)
k -= kx
ky = min(y-1,k/2)
k -= ky
kz = min(z-1,k)
print (kx+1)*(ky+1)*(kz+1)
*/
