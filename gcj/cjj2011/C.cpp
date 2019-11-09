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
string solve(string a,string b) {
	
}
int main() {
	int t; scanf("%d", &t);
	for (int ix=1; ix<=t; ix++) {
		string a, b;
		cin>>a>>b;
		printf("Case #%d: ", ix);
		cout<<solve(a,b)<<endl;
	}
}