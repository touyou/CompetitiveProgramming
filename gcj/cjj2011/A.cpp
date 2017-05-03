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
typedef long long ll;
#define PI 3.14159265358979
int main() {
	int t; scanf("%d", &t);
	for (int ix=1; ix<=t; ix++) {
		int k;
		scanf("%d",&k);
		int e[k];
		for (int i=0; i<k; i++) scanf("%d",&e[i]);
		sort(e,e+k);
		double res=e[0]*e[k-1];
		for (int i=0; i<k-1; i++) {
			res += e[i]*e[i+1];
		}
		res = res * sin(2*PI/k) /2;
		printf("Case #%d: %.9f\n", ix,res);
	}
}