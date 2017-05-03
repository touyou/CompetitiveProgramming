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
#define REP(i,n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int INF = 100000000;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

void solve(int m, int n, int k, vs map) {
	vi cave(m*n, INF);
	cave[0] = 0;
	
}

//-- input --//
int main() {
	int T,M,N,K; cin >> T;
	REP(i,T) { cin >> M >> N >> K; vs map(M); REP(j,M) { cin >> map[j]; } solve(M,N,K,map); }
	return 0;
}
