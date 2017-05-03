#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORS(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;

int main() {
	int N; cin >> N;
	map<int,int> rate;
	vi chefs;
	ll sum=0, chef=0,oscore=0;
	int omax=0,omin=0,ymax=0,ymin=0;
	REP(i,N) {
		int A, R; scanf("%d %d",&A,&R);
		rate[A] = R;
		sum+=R; chef++;
		chefs.PB(A);
		printf("%lld\n",abs(sum-oscore*2));
	}
}
